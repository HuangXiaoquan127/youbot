youbot_navigation
=================

The ROS navigation stack configured for the KUKA youBot.

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
## Reality
- Mapping
	```
	$ roslaunch youbot_mapping youbot_gmapping_reality.launch
	```
- Global navigation
	```
	$ roslaunch youbot_navigation_global youbot_move_base_global.launch
	```
	