import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2, PointField, Image
import numpy as np
from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Point

from cv_bridge import CvBridge

class CircleMarkerPublisher(Node):

    def __init__(self, topic_name):
        super().__init__('circle_marker_publisher')
        self.publisher = self.create_publisher(Marker, topic_name, 10)
        self.timer = self.create_timer(0.1, self.publish_circles)  # Publish at 10 Hz

    def create_circle_marker(self, radius, marker_id):
        marker = Marker()
        marker.header.frame_id = "map"
        marker.ns = "circle_markers"
        marker.id = marker_id
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD

        marker.scale.x = 0.1  # Line width

        # Define circle color
        marker.color.a = 1.0
        marker.color.r = 0.0
        marker.color.g = 1.0
        marker.color.b = 0.0

        num_points = 100
        angle_step = 2 * np.pi / num_points

        for i in range(num_points + 1):
            angle = i * angle_step
            x = radius * np.cos(angle)
            y = radius * np.sin(angle)

            point = Point()
            point.x = x
            point.y = y
            point.z = 0.0  # Circle markers are on the ground

            marker.points.append(point)

        return marker

    def create_text_marker(self, radius, marker_id):
        marker = Marker()
        marker.header.frame_id = "map"
        marker.ns = "circle_text"
        marker.id = marker_id
        marker.type = Marker.TEXT_VIEW_FACING
        marker.action = Marker.ADD

        marker.pose.position.y = float(radius)
        marker.pose.position.x = 0.0
        marker.pose.position.z = 0.0

        marker.scale.z = 2.0  # Text height

        marker.color.a = 1.0
        marker.color.r = 0.0
        marker.color.g = 1.0
        marker.color.b = 0.0

        marker.text = f"{radius}m"

        return marker

    def publish_circles(self):
        radii = [10, 20, 30,50]
        for i, radius in enumerate(radii):
            circle_marker = self.create_circle_marker(radius, i)
            self.publisher.publish(circle_marker)

            text_marker = self.create_text_marker(radius, i)
            self.publisher.publish(text_marker)

class ImagePublisher(Node):
    def __init__(self):
        super().__init__('image_publisher')
        self.front_im_pub = self.create_publisher(Image, 'front_image', 10)
        self.back_im_pub = self.create_publisher(Image, 'back_image', 10)
        self.bridge = CvBridge()

    def publish_images(self, front_im, back_im):
        front_im_msg = self.bridge.cv2_to_imgmsg(front_im, encoding="bgr8")
        back_im_msg = self.bridge.cv2_to_imgmsg(back_im, encoding="bgr8")

        self.front_im_pub.publish(front_im_msg)
        self.back_im_pub.publish(back_im_msg)

class PCDPublisher(Node):

    def __init__(self, topic_name):
        super().__init__('pcd_publisher')
        self.publisher = self.create_publisher(PointCloud2, topic_name, 10)
        #self.bin_path = bin_path
        self.timer = self.create_timer(0.1, self.publish_pcd)  # Publish at 10 Hz
        

    def load_bin(self, bin_path):
        point_cloud = np.fromfile(bin_path, dtype=np.float32)
        point_cloud = np.reshape(point_cloud, (-1, 5))

        msg = PointCloud2()
        msg.header.frame_id = "map"
        msg.height = 1
        msg.width = len(point_cloud)
        msg.fields.append(PointField(name="x", offset=0, datatype=PointField.FLOAT32, count=1))
        msg.fields.append(PointField(name="y", offset=4, datatype=PointField.FLOAT32, count=1))
        msg.fields.append(PointField(name="z", offset=8, datatype=PointField.FLOAT32, count=1))
        msg.fields.append(PointField(name="intensity", offset=12, datatype=PointField.FLOAT32, count=1))
        msg.fields.append(PointField(name="ring", offset=16, datatype=PointField.FLOAT32, count=1))
        msg.point_step = 20
        msg.row_step = msg.point_step * msg.width
        msg.is_dense = True
        msg.data = np.asarray(point_cloud, dtype=np.float32).tobytes()

        return msg

    def publish_pcd(self, bin_path):
        # folder_path='/home/vr/Vicky/data/bevfusion/data/nuscenes/samples/LIDAR_TOP'
        # files = sorted(os.listdir(folder_path))

        # for bin in files:
        self.point_cloud2_msg = self.load_bin(bin_path)
        self.publisher.publish(self.point_cloud2_msg)

class Cube_Publisher(Node):
    def __init__(self, topic_name):
        super().__init__('cube_publisher')
        self.cube_publisher= self.create_publisher(MarkerArray, topic_name, 1)

    def publish_boxes(self,bboxes,labels,classes):
        i = 0
        marker_array = MarkerArray()


        # Delete previously published markers

        delete_marker = Marker()
        delete_marker.action = Marker.DELETEALL
        delete_marker.ns = "bboxes_delete"
        marker_array.markers.append(delete_marker)
        
        # main_car=Marker()

        
        # main_car.header.frame_id = "lidar_top"
        # main_car.id = 911
        # main_car.type = Marker.MESH_RESOURCE
        # main_car.action = Marker.ADD
        # main_car.mesh_resource = "file:/home/nvidia/BEVfusion/tools/nissan.stl"
        # main_car.pose.position.x = 0.0
        # main_car.pose.position.y = -2.0
        # main_car.pose.position.z = -2.0
        # main_car.pose.orientation.x = 0.0
        # main_car.pose.orientation.y = 0.0
        # main_car.pose.orientation.z = 0.7071068
        # main_car.pose.orientation.w = 0.7071068
        # main_car.color.a = 1.0
        # main_car.color.r = 1.0
        # main_car.color.g = 1.0
        # main_car.color.b = 1.0
        # main_car.scale.x = 1.0
        # main_car.scale.y = 1.0
        # main_car.scale.z = 1.0

        # marker_array.markers.append(main_car)    
        
        # Publish new markers
        for idx, bbox in enumerate(bboxes):
            # print(labels[idx])
            # print(classes[labels[idx]])
            if (labels[idx] == 0 or labels[idx] == 1): #only publish car/truck bboxes
                marker = Marker()
                marker.header.frame_id = "lidar_top"
                marker.ns = "bboxes"
                marker.id = i
                marker.type = Marker.CUBE
                marker.action = Marker.ADD
                marker.pose.position.x = float(bbox[0])
                marker.pose.position.y = float(bbox[1])
                marker.pose.position.z = float(bbox[2])
                marker.scale.x = float(bbox[3])
                marker.scale.y = float(bbox[4])
                marker.scale.z = float(bbox[5])
                if labels[idx] == 0:
                    marker.color.r = 0.0
                    marker.color.g = 0.0
                    marker.color.b = 1.0
                if labels[idx] == 1:
                    marker.color.r = 1.0
                    marker.color.g = 0.0
                    marker.color.b = 0.0
                marker.color.a = 1.0
                marker.lifetime.sec = 10  # 10 seconds in nanoseconds
                marker_array.markers.append(marker)
                i += 1

        self.cube_publisher.publish(marker_array)
        #print("publishing")
        
# def main(args=None):
#     rclpy.init(args=args)

#     bin_path = ""
#     topic_name = "pc"

#     pcd_publisher = PCDPublisher(bin_path, topic_name)

#     rclpy.spin(pcd_publisher)

#     pcd_publisher.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()

# def main(args=None):
#     rclpy.init(args=args)

#     topic_name = "circle_markers"

#     circle_marker_publisher = CircleMarkerPublisher(topic_name)

#     rclpy.spin(circle_marker_publisher)

#     circle_marker_publisher.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()