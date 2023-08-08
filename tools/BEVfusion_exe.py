import argparse
import copy
import os
from typing import List, Optional, Tuple
import mmcv
# import numpy as np
from matplotlib import pyplot as plt
from mmcv import Config
from mmcv.parallel import MMDistributedDataParallel
from mmcv.runner import load_checkpoint
from torchpack import distributed as dist
from torchpack.utils.config import configs
from tqdm import tqdm
from mmdet3d.core import LiDARInstance3DBoxes
from mmdet3d.datasets import build_dataloader, build_dataset
from mmdet3d.models import build_model
import cv2
import time
import rclpy
from rclpy.node import Node
from bev_output_utils import Cube_Publisher
# from BEVfusion_utils import Output_Module
from sensor_msgs.msg import Image, PointCloud2, PointField
from cv_bridge import CvBridge
import message_filters
import torch
from typing import Any, Dict
from collections import OrderedDict
from realtime_loading import *

bridge = CvBridge() 

__all__ = ["visualize_camera", "visualize_lidar"]


OBJECT_PALETTE = {
    "car": (255, 158, 0),
    "truck": (255, 99, 71),
    "construction_vehicle": (233, 150, 70),
    "bus": (255, 69, 0),
    "trailer": (255, 140, 0),
    "barrier": (112, 128, 144),
    "motorcycle": (255, 61, 99),
    "bicycle": (220, 20, 60),
    "pedestrian": (0, 0, 230),
    "traffic_cone": (47, 79, 79),
}

def visualize_camera(
    fpath: str,
    image: np.ndarray,
    *,
    bboxes: Optional[LiDARInstance3DBoxes] = None,
    labels: Optional[np.ndarray] = None,
    transform: Optional[np.ndarray] = None,
    classes: Optional[List[str]] = None,
    color: Optional[Tuple[int, int, int]] = None,
    thickness: float = 4,
) -> None:
    canvas = image.copy()
    canvas = cv2.cvtColor(canvas, cv2.COLOR_RGB2BGR)

    if bboxes is not None and len(bboxes) > 0:
        corners = bboxes.corners
        num_bboxes = corners.shape[0]

        coords = np.concatenate(
            [corners.reshape(-1, 3), np.ones((num_bboxes * 8, 1))], axis=-1
        )
        transform = copy.deepcopy(transform).reshape(4, 4)
        coords = coords @ transform.T
        coords = coords.reshape(-1, 8, 4)

        indices = np.all(coords[..., 2] > 0, axis=1)
        coords = coords[indices]
        labels = labels[indices]

        indices = np.argsort(-np.min(coords[..., 2], axis=1))
        coords = coords[indices]
        labels = labels[indices]

        coords = coords.reshape(-1, 4)
        coords[:, 2] = np.clip(coords[:, 2], a_min=1e-5, a_max=1e5)
        coords[:, 0] /= coords[:, 2]
        coords[:, 1] /= coords[:, 2]

        coords = coords[..., :2].reshape(-1, 8, 2)
        for index in range(coords.shape[0]):
            name = classes[labels[index]]
            for start, end in [
                (0, 1),
                (0, 3),
                (0, 4),
                (1, 2),
                (1, 5),
                (3, 2),
                (3, 7),
                (4, 5),
                (4, 7),
                (2, 6),
                (5, 6),
                (6, 7),
            ]:
                cv2.line(
                    canvas,
                    coords[index, start].astype(np.int),
                    coords[index, end].astype(np.int),
                    color or OBJECT_PALETTE[name],
                    thickness,
                    cv2.LINE_AA,
                )
        canvas = canvas.astype(np.uint8)
    canvas = cv2.cvtColor(canvas, cv2.COLOR_BGR2RGB)

    mmcv.mkdir_or_exist(os.path.dirname(fpath))
    mmcv.imwrite(canvas, fpath)

def visualize_lidar(
    fpath: str,
    lidar: Optional[np.ndarray] = None,
    *,
    bboxes: Optional[LiDARInstance3DBoxes] = None,
    labels: Optional[np.ndarray] = None,
    classes: Optional[List[str]] = None,
    xlim: Tuple[float, float] = (-50, 50),
    ylim: Tuple[float, float] = (-50, 50),
    color: Optional[Tuple[int, int, int]] = None,
    radius: float = 15,
    thickness: float = 25,
) -> None:
    
    fig = plt.figure(figsize=(xlim[1] - xlim[0], ylim[1] - ylim[0]))

    ax = plt.gca()
    ax.set_xlim(*xlim)
    ax.set_ylim(*ylim)
    ax.set_aspect(1)
    ax.set_axis_off()

    if lidar is not None:
        plt.scatter(
            lidar[:, 0],
            lidar[:, 1],
            s=radius,
            c="white",
        )

    if bboxes is not None and len(bboxes) > 0:
        coords = bboxes.corners[:, [0, 3, 7, 4, 0], :2]
        for index in range(coords.shape[0]):
            name = classes[labels[index]]
            plt.plot(
                coords[index, :, 0],
                coords[index, :, 1],
                linewidth=thickness,
                color=np.array(color or OBJECT_PALETTE[name]) / 255,
            )

    mmcv.mkdir_or_exist(os.path.dirname(fpath))
    fig.savefig(
        fpath,
        dpi=10,
        facecolor="black",
        format="png",
        bbox_inches="tight",
        pad_inches=0,
    )
    plt.close()

def recursive_eval(obj, globals=None):
    if globals is None:
        globals = copy.deepcopy(obj)

    if isinstance(obj, dict):
        for key in obj:
            obj[key] = recursive_eval(obj[key], globals)
    elif isinstance(obj, list):
        for k, val in enumerate(obj):
            obj[k] = recursive_eval(val, globals)
    elif isinstance(obj, str) and obj.startswith("${") and obj.endswith("}"):
        obj = eval(obj[2:-1], globals)
        obj = recursive_eval(obj, globals)

    return obj

class BEVmodule(Node) :
    def __init__(self) :
        super().__init__('bevfusion_module')

        self.front_sub = message_filters.Subscriber(self, Image, "/cam_front/raw")
        self.front_right_sub = message_filters.Subscriber(self, Image, "/cam_front_right/raw")
        self.front_left_sub = message_filters.Subscriber(self, Image, "/cam_front_left/raw")
        self.back_sub = message_filters.Subscriber(self, Image, "/cam_back/raw")
        self.back_right_sub = message_filters.Subscriber(self, Image, "/cam_back_right/raw")
        self.back_left_sub = message_filters.Subscriber(self, Image, "/cam_back_left/raw")
        self.lidar_top_sub = message_filters.Subscriber(self, PointCloud2, "/lidar_top")

        self.ts = message_filters.ApproximateTimeSynchronizer(
           [self.front_sub, 
            self.front_right_sub, 
            self.front_left_sub,
            self.back_sub, 
            self.back_right_sub, 
            self.back_left_sub,
            self.lidar_top_sub], 
            100,
            .2, 
            allow_headerless=True
            )
        self.ts.registerCallback(self.bev_callback)
        self.get_logger().info("BEVmodule is started")

    #CALL_BACK
    def bev_callback(self, f_msg, fr_msg, fl_msg, b_msg, br_msg, bl_msg, lt_msg) :
        self.get_logger().info('Callback is started')

        ##################################################################################
        #                                IMAGE CONVERT                                   #
        ##################################################################################
        #<------LoadMultiViewImageFromFiles------>
        img_results_0=load_images(f_msg, fr_msg, fl_msg, b_msg, br_msg, bl_msg)
        # #<---------------ImageAug3D-------------->
        img_results_1=img_augmentation(img_results_0)
        # #<-------------ImageNormalize------------>
        img_results_2=img_normalize(img_results_1)

        self.f = bridge.imgmsg_to_cv2(f_msg, "bgr8")
        self.fr = bridge.imgmsg_to_cv2(fr_msg, "bgr8")
        self.fl = bridge.imgmsg_to_cv2(fl_msg, "bgr8")
        self.b = bridge.imgmsg_to_cv2(b_msg, "bgr8")
        self.br = bridge.imgmsg_to_cv2(br_msg, "bgr8")
        self.bl = bridge.imgmsg_to_cv2(bl_msg, "bgr8")

        cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_FRONT/n015-2018-07-24-11-22-45+0800__CAM_FRONT__1532402927612460.jpg', self.f)
        cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_FRONT_RIGHT/n015-2018-07-24-11-22-45+0800__CAM_FRONT_RIGHT__1532402927620339.jpg', self.fr)
        cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_FRONT_LEFT/n015-2018-07-24-11-22-45+0800__CAM_FRONT_LEFT__1532402927604844.jpg', self.fl)
        cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_BACK/n015-2018-07-24-11-22-45+0800__CAM_BACK__1532402927637525.jpg', self.b)
        cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_BACK_RIGHT/n015-2018-07-24-11-22-45+0800__CAM_BACK_RIGHT__1532402927627893.jpg', self.br)
        cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_BACK_LEFT/n015-2018-07-24-11-22-45+0800__CAM_BACK_LEFT__1532402927647423.jpg', self.bl)

        ##################################################################################
        #                                LIDAR CONVERT                                   #
        ##################################################################################
        # #Based_on_File            
        # pcdbin_path='/home/nvidia/BEVfusion/data/nuscenes/samples/LIDAR_TOP/n015-2018-07-24-11-22-45+0800__LIDAR_TOP__1532402927647951.pcd.bin'
        # #<-----------LoadPointsFromFile---------->
        # point_results_0=point_from_file(pcdbin_path)

        #Based_on_ROS
        pcd_as_numpy_array = np.array(list(read_points(lt_msg)))

        rows=pcd_as_numpy_array.shape[0]
        cols=1
        dim5_time=[]

        for row in range(rows):
            dim5_time.append([0])

        #for dimension5, put o like original model input
        pcd_dim5=np.c_[pcd_as_numpy_array, dim5_time]

        points=np.reshape(pcd_dim5,(pcd_dim5.size,))
        #<-----------LoadPointsFromFile---------->
        point_results_0=load_points(points)
        #<---------GlobalRotScaleTrans----------->
        point_results_1=global_rot_trans(point_results_0)
        #<-----------PointsRangeFilter----------->
        point_results_2=point_range_filter(point_results_1)

        ##################################################################################
        #                                FORMAT MATCH                                    #
        ##################################################################################
        results_0=OrderedDict()
        results_0['points']=point_results_2['points']
        results_0['lidar_aug_matrix']=point_results_2['lidar_aug_matrix']
        results_0['img']=img_results_2['img']
        results_0['img_aug_matrix']=img_results_2['img_aug_matrix']
        
        results_1=collect3d(results_0)
        results_2=default_format_bundle(results_1)
        results_3=gt_depth(results_2)

        ##################################################################################
        #                                MODEL START                                     #
        ##################################################################################

        parser = argparse.ArgumentParser()
        parser.add_argument("--config", type=str, default="configs/nuscenes/det/transfusion/secfpn/camera+lidar/swint_v0p075/convfuser.yaml")
        parser.add_argument("--mode", type=str, default="pred", choices=["gt", "pred"])
        parser.add_argument("--checkpoint", type=str, default="pretrained/bevfusion-det.pth")
        parser.add_argument("--split", type=str, default="test", choices=["train", "val"])
        parser.add_argument("--bbox-classes", nargs="+", type=int, default=None)
        parser.add_argument("--bbox-score", type=float, default=0.5)
        parser.add_argument("--map-score", type=float, default=0.5)
        parser.add_argument("--out-dir", type=str, default="viz")
        args, opts = parser.parse_known_args()

        configs.load(args.config, recursive=True)
        configs.update(opts)

        cfg = Config(recursive_eval(configs), filename=args.config)

        torch.backends.cudnn.benchmark = cfg.cudnn_benchmark
        torch.cuda.set_device(dist.local_rank())

        # build the dataloader
        # dataset = build_dataset(cfg.data[args.split])
        dataset = build_dataset(cfg.data.test)
        dataflow = build_dataloader(
            dataset,
            samples_per_gpu=1,
            workers_per_gpu=cfg.data.workers_per_gpu,
            dist=True,
            shuffle=False,
        )

        # build the model and load checkpoint
        if args.mode == "pred":
            model = build_model(cfg.model)
            load_checkpoint(model, args.checkpoint, map_location="cpu")

            model = MMDistributedDataParallel(
                model.cuda(),
                device_ids=[torch.cuda.current_device()],
                broadcast_buffers=False,
            )
            model.eval()

    #ROS2
        # pcd_publisher = PCDPublisher("lidar_pointcloud")
        # circle_marker_publisher = CircleMarkerPublisher("circle_markers")
        cube_publisher =Cube_Publisher("bounding_box_markers")

        for data in tqdm(dataflow):
            metas = data["metas"].data[0][0]
            name = "{}-{}".format(metas["timestamp"], metas["token"])
            
            if args.mode == "pred":
                with torch.inference_mode():

                    data["img"]=results_3['img']
                    data["points"]=results_3['points']
                    data["depths"]=results_3['depths']

                    outputs = model(**data)


            if args.mode == "pred" and "boxes_3d" in outputs[0]:
                bboxes = outputs[0]["boxes_3d"].tensor.numpy()
                scores = outputs[0]["scores_3d"].numpy()
                labels = outputs[0]["labels_3d"].numpy()

                if args.bbox_classes is not None:
                    indices = np.isin(labels, args.bbox_classes)
                    bboxes = bboxes[indices]
                    scores = scores[indices]
                    labels = labels[indices]

                if args.bbox_score is not None:
                    indices = scores >= args.bbox_score
                    bboxes = bboxes[indices]
                    scores = scores[indices]
                    labels = labels[indices]

                bboxes[..., 2] -= bboxes[..., 5] / 2
                bboxes = LiDARInstance3DBoxes(bboxes, box_dim=9)
            else:
                bboxes = None
                labels = None

            cube_publisher.publish_boxes(bboxes,labels,classes=cfg.object_classes)
            time.sleep(0.1)
            
            if "img" in data:
                for k, image_path in enumerate(metas["filename"]):
                    image = mmcv.imread(image_path)
                    visualize_camera(
                        os.path.join(args.out_dir, f"camera-{k}", f"{name}.png"),
                        image,
                        bboxes=bboxes,
                        labels=labels,
                        transform=metas["lidar2image"][k],
                        classes=cfg.object_classes,
                    )

            if "points" in data:
                # data 구조 변경에 따른 수정
                lidar = data["points"].data[0][0].numpy()
                # lidar = data["points"].data.numpy()
                visualize_lidar(
                    os.path.join(args.out_dir, "lidar", f"{name}.png"),
                    lidar,
                    bboxes=bboxes,
                    labels=labels,
                    xlim=[cfg.point_cloud_range[d] for d in [0, 3]],
                    ylim=[cfg.point_cloud_range[d] for d in [1, 4]],
                    classes=cfg.object_classes,
                )

def main() -> None:

    dist.init()
    rclpy.init()

    node = BEVmodule()
    # rclpy.spin(node)
    try :
        rclpy.spin(node)
    except KeyboardInterrupt :
        node.get_logger().info('Stopped by Keyboard')
    finally :
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
