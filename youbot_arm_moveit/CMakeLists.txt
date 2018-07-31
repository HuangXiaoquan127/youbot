cmake_minimum_required(VERSION 2.8.3)
project(youbot_arm_moveit)

add_definitions(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS moveit_core moveit_ros_planning moveit_ros_planning_interface pluginlib cmake_modules)
find_package(Boost REQUIRED system filesystem date_time thread)
find_package(Eigen REQUIRED)

include_directories(SYSTEM ${Boost_INCLUDE_DIR} ${EIGEN_INCLUDE_DIRS})
include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(
  CATKIN_DEPENDS
    moveit_core
    moveit_ros_planning_interface
)

add_executable(youbot_move_group_plan_single_target src/youbot_move_group_plan_single_target.cpp)
target_link_libraries(youbot_move_group_plan_single_target ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(youbot_move_group_plan_group_state src/youbot_move_group_plan_group_state.cpp)
target_link_libraries(youbot_move_group_plan_group_state ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(youbot_move_group_plan_random_target src/youbot_move_group_plan_random_target.cpp)
target_link_libraries(youbot_move_group_plan_random_target ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(youbot_move_group_add_object src/youbot_move_group_add_object.cpp)
target_link_libraries(youbot_move_group_add_object ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(youbot_move_group_remove_object src/youbot_move_group_remove_object.cpp)
target_link_libraries(youbot_move_group_remove_object ${catkin_LIBRARIES} ${Boost_LIBRARIES})

install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  PATTERN "setup_assistant.launch" EXCLUDE)
install(DIRECTORY config DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
