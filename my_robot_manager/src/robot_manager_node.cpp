#include "my_robot_manager/robot_manager.h"
#include "ros/node_handle.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;
  RobotManager robot1(&nh, "/robot1/odom", "Turtle_1", "TurtleBot3");
  robot1.print_specifications();
  RobotManager robot2(&nh, "/robot2/odom", "Turtle_2", "TurtleBot3");
  robot2.print_specifications();
  ros::spin();
  return 0;
}