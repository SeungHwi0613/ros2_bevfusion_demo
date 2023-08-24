# BEVfusion_demo  

![녹화_2023_08_22_10_53_21_137](https://github.com/SeungHwi0613/BEVfusion_demo/assets/108920644/8d815e30-a434-4253-87ed-b964ad28273b)


## Abstract
This project is based on [BEVFusion](https://github.com/mit-han-lab/bevfusion).  
The version of bevfusion using ROS2.

## Flow


## Usage
Dataset : [nuscense bag](https://drive.google.com/file/d/1OGmt05ZW1WbtR4Xy-vVhWRRuXZ5c2iGx/view?usp=drive_link)
### Requirements
- ROS2(Foxy)

### Build

### Run
```Shell
torchpack dist-run -np 1 python tools/BEVfusion_exe.py
```

## Detail
We have several points upgrade from original BEVfusion.

- Multiple Camera & Multiple Lidar  
    We have preprocessing module because of using **3 Lidar** and **6 Camera**.  
    But this Repository is the ***DEMO*** version of our project, so we are using **1 Lidar**, and **1 Camera**
    - Lidar Preprocesing
        - Details : [Preprocessing_module](https://github.com/newintelligence4/BEVfusion_preprocess)

## Team
| Name | Mail | Role| Github |
|--|--|--|--|
|임승휘 | - | Model Transform </br> Build Orin </br> General Manager| @SeungHwi0613|
| 신지혜 | jshin0404@gmail.com | Lidar Preprocessing | @NewIntelligence4|
| 장재현 | - | Postprocessing | @JaehyunJang5216 |


