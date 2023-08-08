import message_filters
from rclpy.node import Node
from realtime_loading import *
from sensor_msgs.msg import Image
import rclpy
from collections import OrderedDict

'''

#open image using openCV2
opencv_image=cv2.imread("./learning_python.png")

#display image to GUI
cv2.imshow("PIL2OpenCV", opencv_image)

# convert from BGR to RGB
color_coverted = cv2.cvtColor(opencv_image, cv2.COLOR_BGR2RGB)

# convert from openCV2 to PIL
pil_image=Image.fromarray(color_coverted)

'''
# def load_images(root_path):
# def load_images(f_msg, fr_msg, fl_msg, b_msg, br_msg, bl_msg):

#     #file_based_custom
#     # f_path=root_path+'CAM_FRONT/n015-2018-07-24-11-22-45+0800__CAM_FRONT__1532402927612460.jpg'
#     # fr_path=root_path+'CAM_FRONT_RIGHT/n015-2018-07-24-11-22-45+0800__CAM_FRONT_RIGHT__1532402927620339.jpg'
#     # fl_path=root_path+'CAM_FRONT_LEFT/n015-2018-07-24-11-22-45+0800__CAM_FRONT_LEFT__1532402927604844.jpg'
#     # b_path=root_path+'CAM_BACK/n015-2018-07-24-11-22-45+0800__CAM_BACK__1532402927637525.jpg'
#     # br_path=root_path+'CAM_BACK_RIGHT/n015-2018-07-24-11-22-45+0800__CAM_BACK_RIGHT__1532402927627893.jpg'
#     # bl_path=root_path+'CAM_BACK_LEFT/n015-2018-07-24-11-22-45+0800__CAM_BACK_LEFT__1532402927647423.jpg'

#     # f_cv2=cv2.imread(f_path)
#     # fr_cv2=cv2.imread(fr_path)
#     # fl_cv2=cv2.imread(fl_path)
#     # b_cv2=cv2.imread(b_path)
#     # br_cv2=cv2.imread(br_path)
#     # bl_cv2=cv2.imread(bl_path)


#     #msg_based_custom
#     f_cv2 = bridge.imgmsg_to_cv2(f_msg, 'bgr8')
#     fr_cv2 = bridge.imgmsg_to_cv2(fr_msg, 'bgr8')
#     fl_cv2 = bridge.imgmsg_to_cv2(fl_msg, 'bgr8')
#     b_cv2 = bridge.imgmsg_to_cv2(b_msg, 'bgr8')
#     br_cv2 = bridge.imgmsg_to_cv2(br_msg, 'bgr8')
#     bl_cv2 = bridge.imgmsg_to_cv2(bl_msg, 'bgr8')

#     color_coverted_f = cv2.cvtColor(f_cv2, cv2.COLOR_BGR2RGB)
#     color_coverted_fr = cv2.cvtColor(fr_cv2, cv2.COLOR_BGR2RGB)
#     color_coverted_fl = cv2.cvtColor(fl_cv2, cv2.COLOR_BGR2RGB)
#     color_coverted_b = cv2.cvtColor(b_cv2, cv2.COLOR_BGR2RGB)
#     color_coverted_br = cv2.cvtColor(br_cv2, cv2.COLOR_BGR2RGB)
#     color_coverted_bl = cv2.cvtColor(bl_cv2, cv2.COLOR_BGR2RGB)

#     pil_image_f=Im.fromarray(color_coverted_f)
#     pil_image_fr=Im.fromarray(color_coverted_fr)
#     pil_image_fl=Im.fromarray(color_coverted_fl)
#     pil_image_b=Im.fromarray(color_coverted_b)
#     pil_image_br=Im.fromarray(color_coverted_br)
#     pil_image_bl=Im.fromarray(color_coverted_bl)

#     pil_img_ls=[pil_image_f, pil_image_fr, pil_image_fl, pil_image_b, pil_image_br, pil_image_bl]

#     # results=OrderedDict()
#     results=dict()
#     results["img"] = pil_img_ls

#     return results

class BEVmodule(Node) :
    def __init__(self) :
        super().__init__('bevfusion_module')

        self.front_sub = message_filters.Subscriber(self, Image, "/cam_front/raw")
        self.front_right_sub = message_filters.Subscriber(self, Image, "/cam_front_right/raw")
        self.front_left_sub = message_filters.Subscriber(self, Image, "/cam_front_left/raw")
        self.back_sub = message_filters.Subscriber(self, Image, "/cam_back/raw")
        self.back_right_sub = message_filters.Subscriber(self, Image, "/cam_back_right/raw")
        self.back_left_sub = message_filters.Subscriber(self, Image, "/cam_back_left/raw")
        # self.lidar_top_sub = message_filters.Subscriber(self, PointCloud2, "/lidar_top")

        self.ts = message_filters.ApproximateTimeSynchronizer(
           [self.front_sub, 
            self.front_right_sub, 
            self.front_left_sub,
            self.back_sub, 
            self.back_right_sub, 
            self.back_left_sub],
            # self.lidar_top_sub], 
            100,
            .2, 
            allow_headerless=True
            )
        self.ts.registerCallback(self.bev_callback)
        self.get_logger().info("BEVmodule is started")

    #CALL_BACK
    def bev_callback(self, f_msg, fr_msg, fl_msg, b_msg, br_msg, bl_msg) :
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
        # #<---------DefaultFormatBundle3D--------->
        # img_results_3=default_format_bundle(img_results_2)
        # #<---------------Collect3D--------------->
        # img_results_4=collect3d_for_img(img_results_3)

        # self.f = bridge.imgmsg_to_cv2(f_msg, "bgr8")
        # self.fr = bridge.imgmsg_to_cv2(fr_msg, "bgr8")
        # self.fl = bridge.imgmsg_to_cv2(fl_msg, "bgr8")
        # self.b = bridge.imgmsg_to_cv2(b_msg, "bgr8")
        # self.br = bridge.imgmsg_to_cv2(br_msg, "bgr8")
        # self.bl = bridge.imgmsg_to_cv2(bl_msg, "bgr8")

        # cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_FRONT/n015-2018-07-24-11-22-45+0800__CAM_FRONT__1532402927612460.jpg', self.f)
        # cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_FRONT_RIGHT/n015-2018-07-24-11-22-45+0800__CAM_FRONT_RIGHT__1532402927620339.jpg', self.fr)
        # cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_FRONT_LEFT/n015-2018-07-24-11-22-45+0800__CAM_FRONT_LEFT__1532402927604844.jpg', self.fl)
        # cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_BACK/n015-2018-07-24-11-22-45+0800__CAM_BACK__1532402927637525.jpg', self.b)
        # cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_BACK_RIGHT/n015-2018-07-24-11-22-45+0800__CAM_BACK_RIGHT__1532402927627893.jpg', self.br)
        # cv2.imwrite('/home/nvidia/BEVfusion/data/nuscenes/samples/CAM_BACK_LEFT/n015-2018-07-24-11-22-45+0800__CAM_BACK_LEFT__1532402927647423.jpg', self.bl)


        ##################################################################################
        #                                LIDAR CONVERT                                   #
        ##################################################################################
        #Based_on_File            
        pcdbin_path='/home/nvidia/BEVfusion/data/nuscenes/samples/LIDAR_TOP/n015-2018-07-24-11-22-45+0800__LIDAR_TOP__1532402927647951.pcd.bin'
        #<-----------LoadPointsFromFile---------->
        point_results_0=point_from_file(pcdbin_path)
        #<---------GlobalRotScaleTrans----------->
        point_results_1=global_rot_trans(point_results_0)
        #<-----------PointsRangeFilter----------->
        point_results_2=point_range_filter(point_results_1)
        # #<---------DefaultFormatBundle3D--------->
        # point_results_3=default_format_bundle(point_results_2)
        # #<---------------Collect3D--------------->
        # point_results_4=collect3d_for_point(point_results_3)


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





def main(args=None):
    rclpy.init(args=args)

    node  = BEVmodule()

    # rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    # minimal_publisher.destroy_node()
    # rclpy.shutdown()

    try :
        rclpy.spin(node)
    except KeyboardInterrupt :
        node.get_logger().info('Stopped by Keyboard')
    finally :
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()