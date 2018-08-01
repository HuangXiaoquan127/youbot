# youbot arm moveit

- To test arm in rviz, use this:
	```
	$ roslaunch youbot_arm_moveit demo.launch
	```

- To test arm both both rviz and gazebo, use this:
	```
	$ roslaunch youbot_arm_moveit demo_gazebo.launch
	```
- To test c++ code set some task in moveit (the arm in rviz or both in rivz and gazebo should be launch first, see above):
	- plan single target:
	```
	$ rosrun youbot_arm_moveit youbot_move_group_plan_group_state
	```
	- plan random target:
	```
	$ rosrun youbot_arm_moveit youbot_move_group_plan_random_target
	```
	- plan group preset pose:
	```
	$ rosrun youbot_arm_moveit youbot_move_group_plan_group_state
	```
	- add and remove object in plan scene:
	```
	$ rosrun youbot_arm_moveit youbot_move_group_add_object
	```
	```
	$ rosrun youbot_arm_moveit youbot_move_group_remove_object
	```
- To test arm in **grasping_world** and add the point cloud:
	1. change the world value as grasping_world in `demo_gazebo.launch`
	2. add the **RGB-D sensor** in `youbot_arm_only.urdf.xacro`
	3. then launch the arm both in rviz and gazebo:
	```
	$ roslaunch youbot_arm_moveit demo_gazebo.launch
	```
	![Alt text](https://github.com/HuangXiaoquan127/MarkdownPictures/raw/master/Screenshot%20from%202018-07-31%2008-54-45.png) 

- To test arm pick and place, use these:
	1. load the arm in rviz or gazebo:
	```
	$ roslaunch youbot_arm_moveit demo.launch
	```
	or
	```
	$ roslaunch youbot_arm_moveit demo_gazebo.launch
	```
 	2. open the grasp_generator_server that runs the moveit_simple_grasps_server node of moveit_simple_grasps package: 
	```
	$ roslaunch youbot_arm_moveit grasp_generator_server.launch
	```
	3. run pick and place script:
	```
	$ rosrun youbot_arm_moveit youbot_pick_and_place.py
	```
