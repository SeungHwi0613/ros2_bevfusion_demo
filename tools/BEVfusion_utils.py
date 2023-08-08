import rclpy

from rclpy.node import Node

from sensor_msgs.msg import PointCloud2, PointField, Image

import numpy as np

from visualization_msgs.msg import Marker, MarkerArray

from geometry_msgs.msg import Point

from bev_msgs.msg import OutputArray, Bbox, Output

from cv_bridge import CvBridge

from matplotlib import pyplot as plt

from typing import List, Optional, Tuple

import cv2

import os

import mmcv

import copy

from mmdet3d.core import LiDARInstance3DBoxes

id = 0

class Output_Module(Node):

    def __init__(self, topic_name):

        super().__init__('bev_output')
        self.get_logger().info('|||||||    OUTPUT MODULE IS STARTED     ||||||||')

        self.cube_publisher= self.create_publisher(OutputArray, topic_name, 1)

    def publish_boxes(self,bboxes,labels, scores):

        global id

        # marker_array = MarkerArray()

        output_array=OutputArray()

        output_array.header.frame_id = "frame"+str(id)

        output_array.header.stamp=self.get_clock().now().to_msg()

        # print(output_array.header.frame_id)

        

        

        # # Delete previously published markers

        # # delete_marker = Marker()

        # delete_marker = Output()

        # delete_bbox = Bbox()

        # delete_bbox.pos_x=0.0

        # delete_bbox.pos_y=0.0

        # delete_bbox.width=0.0

        # delete_bbox.length=0.0

        # delete_bbox.height=0.0

        # delete_bbox.yaw=0.0

        # # delete_marker.action = Marker.DELETEALL

        # delete_marker.box = delete_bbox

        # delete_marker.score = 0.0

        # delete_marker.label = 0

        # # delete_marker.ns = "bboxes"

        # marker_array.outputs.append(delete_marker)

        

        # Publish new markers

        for idx, bbox in enumerate(bboxes):

            # print(labels[idx])

            # print(classes[labels[idx]])

            if (labels[idx] == 0 or labels[idx] == 1): #only publish car/truck bboxes

                # marker = Marker()

                output=Output()

                # marker.header.frame_id = "map"

                bbox_msg=Bbox()

                bbox_msg.pos_x=float(bbox[0])

                bbox_msg.pos_y=float(bbox[1])

                bbox_msg.width=float(bbox[3])

                bbox_msg.length=float(bbox[4])

                bbox_msg.height=float(bbox[5])

                bbox_msg.yaw=-float(bbox[6])

                

                output.box=bbox_msg

                output.score=round(float(scores[idx]),4)

                output.label=int(labels[idx])

                

                # if labels[idx] == 0:

                #     marker.color.r = 0.0

                #     marker.color.g = 0.0

                #     marker.color.b = 1.0

                # if labels[idx] == 1:

                #     marker.color.r = 1.0

                #     marker.color.g = 0.0

                #     marker.color.b = 0.0

                # marker.color.a = 1.0

                # marker.lifetime.sec = 10  # 10 seconds in nanoseconds

                output_array.outputs.append(output)

        id += 1

        self.cube_publisher.publish(output_array)
