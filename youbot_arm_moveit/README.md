# youbot arm moveit

To test arm in rviz, use this:
roslaunch youbot_arm_moveit demo.launch

To test arm in both rviz and gazebo, use this:
roslaunch youbot_arm_moveit demo_gazebo.launch

To test arm pick and place, use these:
1.load the arm in rviz or gazebo:
roslaunch youbot_arm_moveit demo.launch or
roslaunch youbot_arm_moveit demo_gazebo.launch
2.open the grasp_generator_server that runs the moveit_simple_grasps_server node of moveit_simple_grasps package: 
roslaunch youbot_arm_moveit grasp_generator_server.launch
3.run pick and place script:
rosrun youbot_arm_moveit youbot_pick_and_place.py