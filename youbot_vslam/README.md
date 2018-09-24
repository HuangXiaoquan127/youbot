# youbot_vslam
- Add path of the custom models:
```
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$(rospack find youbot_gazebo_worlds)/models
```

- Other test
```
roslaunch rtabmap_ros rtabmap.launch rtabmap_args:="--delete_db_on_start" rgb_topic:=/tower_cam3d/rgb/image_raw depth_topic:=/tower_cam3d/depth/image_raw camera_info_topic:=/tower_cam3d/rgb/camera_info approx_sync:=false
```