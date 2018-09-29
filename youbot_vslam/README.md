# youbot_vslam

## 1. Prerequisites
- Add the path of the custom models to .bashrc:
	```
	export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$(rospack find youbot_gazebo_worlds)/models
	```
- RTAB-Map
We use RTAB-Map for test . Dowload and install instructions can be found at: https://github.com/introlab/rtabmap/wiki.

- ORB-SLAM2
We use ORB-SLAM2 for test . Dowload and install instructions can be found at: https://github.com/raulmur/ORB_SLAM2.

## 2. Examples
- Test RTAB-Map
	```
	roslaunch youbot_vslam youbot_rtabmap.launch
	```
- Test ORB-SLAM2
	```
	roslaunch youbot_vslam youbot_orb_slam.launch
	```
- Test multiple vSLAMs simultaneously
	```
	roslaunch youbot_vslam youbot_mutiple_slam.launch
	```
## 3. Other command
youbot keyboard teleoperation:
	```
	rosrun youbot_driver_ros_interface youbot_keyboard_teleop.py
	```

![](https://github.com/HuangXiaoquan127/MarkdownPictures/blob/master/2018-09-28%2016%2037%2022.png) 
![](https://github.com/HuangXiaoquan127/MarkdownPictures/blob/master/Screenshot%20from%202018-09-24%2016-33-01.png) 