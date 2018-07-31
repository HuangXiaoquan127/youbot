#include <moveit/move_group_interface/move_group.h>

#include <moveit_msgs/DisplayTrajectory.h>

int main(int argc, char **argv)
{
    // Initialize ROS, create the node handle and an async spinner
    ros::init(argc, argv, "move_group_plan_single_target");
    ros::NodeHandle nh;

    ros::AsyncSpinner spin(1); //Use 1 threads, AsyncSpinner() can open more than one thread.
    spin.start();

    // Get the arm planning group
    moveit::planning_interface::MoveGroup plan_group("arm");  //the name of group come from the moveit setup_assistant

    // Create a published for the arm plan visualization
    ros::Publisher display_pub = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);

    // Set a goal message as a pose of the end effector
    geometry_msgs::Pose goal;
	
	//home pose
    goal.orientation.x = -0.00396755;
    goal.orientation.y = 0.18637;
    goal.orientation.z = -0.192282;
    goal.orientation.w = 0.963472;
    goal.position.x = 0.0472537;
    goal.position.y = -0.00412819;
    goal.position.z = 0.321848;

    // Set the tolerance to consider the goal achieved
    plan_group.setGoalTolerance(0.2);
	plan_group.setPlannerId("RRTConnectkConfigDefault");

    // Set the target pose, which is the goal we already defined
    //bool isSetPoseTarget = plan_group.setPoseTarget(goal);
	//plan_group.setPoseTarget(goal);
	//plan_group.setPositionTarget(goal.position.x, goal.position.y, goal.position.z);
	plan_group.setJointValueTarget(goal);  //add by hxq, using setJointValueTarget in youbot will not occur error

	//ROS_INFO_STREAM("isSetPoseTarget: " << isSetPoseTarget);
	//ROS_INFO_STREAM("Target pose: " << plan_group.getPoseTarget());
	
    // Perform the planning step, and if it succeeds display the current
    // arm trajectory and move the arm
    moveit::planning_interface::MoveGroup::Plan goal_plan;
    if (plan_group.plan(goal_plan))
    {
        moveit_msgs::DisplayTrajectory display_msg;
        display_msg.trajectory_start = goal_plan.start_state_;
        display_msg.trajectory.push_back(goal_plan.trajectory_);
        display_pub.publish(display_msg);
		//ROS_INFO_STREAM("Target pose: " << plan_group.getPoseTarget());

        sleep(5.0);

        plan_group.move();
    }

    ROS_INFO_STREAM("Current pose: " << plan_group.getCurrentPose());
    ros::shutdown();

    return 0;
}
