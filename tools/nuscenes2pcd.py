import os
import struct

import numpy as np
from nuscenes.nuscenes import NuScenes
from nuscenes.utils.data_classes import LidarPointCloud
import open3d as o3d


# nusc = NuScenes(version='v1.0-mini', dataroot='/home/nvidia/BEVfusion/data/nuscenes/samples/LIDAR_TOP/', verbose=False)

# # Get some random .pcd.bin file from nuScenes.
# pcd_bin_file = os.path.join(nusc.dataroot, nusc.get('sample_data', '9d9bf11fb0e144c8b446d54a8a00184f')['filename'])

pcd_bin_file= '/home/nvidia/BEVfusion/data/nuscenes/samples/LIDAR_TOP/LIDAR_TOP.pcd.bin'
# Load the .pcd.bin file.


# Reshape and get only values for x, y and z.
# But i want to get Intensity data too

#################################################
#                 ORIGINAL WAY                  #
#################################################
# pc = LidarPointCloud.from_file(pcd_bin_file)
# bin_pcd = pc.points.T
# bin_pcd = bin_pcd.reshape((-1, 4))[:, 0:3]
# print(bin_pcd)
# # Convert to Open3D point cloud.
# o3d_pcd = o3d.geometry.PointCloud(o3d.utility.Vector3dVector(bin_pcd))
# print(o3d_pcd)
# # Save to a .pcd file.
# o3d.io.write_point_cloud(os.path.expanduser("/home/nvidia/BEVfusion/data/nuscenes/samples/LIDAR_TOP/LIDAR_TOP.pcd"), o3d_pcd)

# # Read the saved .pcd file from the previous step.
# pcd = o3d.io.read_point_cloud(os.path.expanduser("/home/nvidia/BEVfusion/data/nuscenes/samples/LIDAR_TOP/LIDAR_TOP.pcd"))
# out_arr = np.asarray(pcd.points)  

# # Load the original point cloud data from nuScenes, and check that the saved .pcd matches the original data.
# pc = LidarPointCloud.from_file(pcd_bin_file)
# points = pc.points.T
# assert np.array_equal(out_arr, points[:, :3])

#################################################
#                 INTENSITY WAY                 #
#################################################
#참고: https://stackoverflow.com/questions/71370478/save-4d-numpy-array-as-pcdpoint-cloud-file

pc = LidarPointCloud.from_file(pcd_bin_file)
bin_pcd = pc.points.T

xyz = bin_pcd[:,0:3]
i = [[i] for i in bin_pcd[:,3]]
t = [[j] for j in bin_pcd[:,3]]

o3d_pcd = o3d.t.geometry.PointCloud()

o3d_pcd.point["positions"] = o3d.core.Tensor(xyz)
o3d_pcd.point["intensities"] = o3d.core.Tensor(i)
o3d_pcd.point["timestamps"] = o3d.core.Tensor(t)

print(o3d_pcd)
pcd_path="/home/nvidia/BEVfusion/data/nuscenes/samples/LIDAR_TOP/LIDAR_TOP.pcd"
o3d.t.io.write_point_cloud(os.path.expanduser(pcd_path), o3d_pcd)

points = np.fromfile(pcd_path, dtype=np.float32)
# print(points)
# print(type(points))
# print(points.shape)

pcdbin_path="/home/nvidia/BEVfusion/data/nuscenes/samples/LIDAR_TOP/LIDAR_TOP.pcd.bin"
points = np.fromfile(pcdbin_path, dtype=np.float32)
print(points)
print(type(points))
print(points.shape)

import numpy as np

#이걸 역으로 이용하자
# with open(pcdbin_path, "rb") as f:
#     number = f.read(4)
#     while number != b"":
#         print(np.frombuffer(number, dtype=np.float32))
#         number = f.read(4)