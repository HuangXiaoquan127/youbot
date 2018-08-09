youbot_navigation
=================

The ROS navigation stack configured for the KUKA youBot.

## Dependency
- Dependency package:
 	```
 	sudo apt-get install ros-kinetic-amcl ros-kinetic-move-base
 	```

## Simulation
- Mapping
	```
	$ roslaunch youbot_mapping youbot_gmapping.launch
	```
- Global navigation 
	```
	$ roslaunch youbot_navigation_global youbot_navigation_global.launch
	```
- Local navigation
	```
	$ roslaunch youbot_navigation_local move_base_local.launch
	```
	
![](https://github.com/HuangXiaoquan127/MarkdownPictures/raw/master/Screenshot%20from%202018-07-19%2010-56-57.png) 

## Reality
- Mapping
	```
	$ roslaunch youbot_mapping youbot_gmapping_reality.launch
	```
- Global navigation
	```
	$ roslaunch youbot_navigation_global youbot_move_base_global.launch
	```
	