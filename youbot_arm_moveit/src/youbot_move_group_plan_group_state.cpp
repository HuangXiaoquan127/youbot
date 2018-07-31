#include <moveit/move_group_interface/move_group.h>

#include <moveit_msgs/DisplayTrajectory.h>

int main(int argc, char **argv)
{
    // Initialize ROS, create the node handle and an async spinner
    ros::init(argc, argv, "move_group_plan_group_state");
    ros::NodeHandle nh;

    ros::AsyncSpinner spin(1);
    spin.start();

    // Get the arm planning group
    moveit::planning_interface::MoveGroup plan_group("arm");

    // Create a published for the arm plan visualization
    ros::Publisher display_pub = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);

    // Get the current RobotState, which will be used to set the arm
    // to one of the predefined group states, in this case home
    robot_state::RobotState current_state = *plan_group.getCurrentState();

    // We set the state values for this robot state to the predefined
    // group state values
    current_state.setToDefaultValues(current_state.getJointModelGroup("arm"), "home");

    // We set the current state values to the target values
    plan_group.setJointValueTarget(current_state);	

	//ROS_INFO_STREAM("Target pose: " << plan_group.getPoseTarget());
	//ROS_INFO_STREAM("JointValueTarget: " << plan_group.getJointValueTarget());
	
    // Perform the planning step, and if it succeeds display the current
    // arm trajectory and move the arm
    moveit::planning_interface::MoveGroup::Plan goal_plan;
    if (plan_group.plan(goal_plan))
    {
        moveit_msgs::DisplayTrajectory display_msg;
        display_msg.trajectory_start = goal_plan.start_state_;
        display_msg.trajectory.push_back(goal_plan.trajectory_);
        display_pub.publish(display_msg);		
		//ROS_INFO_STREAM("Target pose: " << plan_group.getPoseTarget());  //errro: Pose for end-effector 'gripper_palm_link' not known.
		//ROS_INFO_STREAM("Current pose: " << plan_group.getCurrentPose());
		
        sleep(5.0);

        plan_group.move();
    }

    //ROS_INFO_STREAM("Target pose: " << plan_group.getPoseTarget()); 
    ROS_INFO_STREAM("Current pose: " << plan_group.getCurrentPose());
    ros::shutdown();

    return 0;
}
