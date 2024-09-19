#include "my_robot_manager/robot_manager.h"
#include "ros/node_handle.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;
  RobotManager robot(&nh, "/robot1/odom", "my_bot", "TurtleBot3");
  robot.print_specifications();
  ros::spin();
  return 0;
}