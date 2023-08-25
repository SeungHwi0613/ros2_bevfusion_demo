# BEVfusion_demo  

![녹화_2023_08_22_10_53_21_137](https://github.com/SeungHwi0613/BEVfusion_demo/assets/108920644/8d815e30-a434-4253-87ed-b964ad28273b)


## Abstract
This project is based on [BEVFusion](https://github.com/mit-han-lab/bevfusion).  
The version of bevfusion using ROS2.


## Flow
<img src='./assets/bevfusion.png' />

## Usage
Dataset : [nuscense ros2 bag](https://drive.google.com/file/d/1OGmt05ZW1WbtR4Xy-vVhWRRuXZ5c2iGx/view?usp=drive_link)
### Requirements
- ROS2(Foxy)
- Pytorch
- CUDA 11.4

### How to start
***Data Preperation***  
This project is using nuscense dataset  

1. Make `.pkl` file contains calibration results.  
(Details [HERE](https://github.com/open-mmlab/mmdetection3d/blob/1.0/docs/en/datasets/nuscenes_det.md))  

2. Make `calibration_parameter.yaml` using `.pkl` file  
`sensor2lidar rotation`(3x3 matrix),  
`sensor2lidar traslation`(3x1 matrix),  
`intrinsic matrix`(3x3 matrix)

3. Make four 4x4 matrix below and update `calibration_parameter.yaml`  
format :  
<img src='./assets/matrix.png' width="50%"/>
</br>

    - 6 camera intrinsic 4x4 matrix
        - rotation : camera intrinsic matrix
        - translation : zero matrix


    - 6 camera2lidar 4x4 matrix
        - rotation : sensor2lidar rotation matrix
        - translation : sensor2lidar translation matrix

    - 6 lidar2camera 4x4 matrix
        - rotation : Transformation of sensor2lidar rotation matrix
        - translation : convolution of Transformation sensor2lidar translation and sensor2lidar rotation matrix

    - 6 lidar2image 4x4 matrix
        - using file `./tools/lidar2image.py`
            - input : the `calibration_parameter.yaml` file which has the information of 3 matrix ubove.
            - output : the lidar2image 4x4 matrix
        - add this output matrix to `calibration_parameter.yaml` file which used in input


</br>

4. convert to `.bag` file using [nuscenes2bag](https://github.com/clynamen/nuscenes2bag)
    > This converts nuscenes dataset to ROS1 bag file, so you have to convert it to ROS2 format.  
    > we used the library [rosbag_convert](https://ternaris.gitlab.io/rosbags/topics/convert.html)


***Run***
```Shell
torchpack dist-run -np 1 python tools/BEVfusion_exe.py
```

## Detail
We have several points upgrade from original BEVfusion.
</br>

***Number of Sensors***  
> Multiple Camera & Multiple Lidar  
    We have preprocessing module because of using **3 Lidar** and **6 Camera**.  
    But this Repository is the ***DEMO*** version of our project, so we are using **1 Lidar**, and **1 Camera**

***Lidar Preprocesing***
>   Details : [Preprocessing_module](https://github.com/newintelligence4/BEVfusion_preprocess) branch `1Lidar`
</br>

***Difference***  
Original BEVfusion:
> using **static** Dataset  
> - Large size of data  
>- calibration all sensors with it's own ego_frame(IMU)  
>- no Tracking ID  
>- object detection using Map information inside model's own map segmentation 
</br>

BEVfusion with ROS2
> using **Realtime** Dataset
> - It is necessary to manage data efficiently when using realtime data   
    -> reduce the data size by preprocessing sensor's raw data
> - Remove the IMU dependencies for ego_frame(IMU)  
-> Direct Calibration of Camera to Lidar and transform to Model as parameter type(`.yaml`)  
-> 
> - Add detected object's own ID using 2D Object Tracking(`SORT` Algorithm) in Bird-eye view plane
> - Remove the *map segmentation* part, and visualize object's information using *HD map*

## Team
| Name | Mail | Role| Github |
|--|--|--|--|
|임승휘 | iish613613@gmail.com | Model Transform </br> Build Orin </br> General Manager| @SeungHwi0613|
| 신지혜 | jshin0404@gmail.com | Lidar Preprocessing | @NewIntelligence4|
| 장재현 | wogus5216@gmail.com | Postprocessing | @JaehyunJang5216 |


