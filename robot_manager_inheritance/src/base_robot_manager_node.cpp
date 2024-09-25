#include "../include/robot_manager_inheritance/base_robot_manager.h"
#include "ros/node_handle.h"
int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager_using_inheritance");
  ros::NodeHandle node_handle;
  RobotManagerBase robot_manager_base(&node_handle);
  // or RobotManagerBase rmb = RobotManagerBase(&nh);
  ros::spin();
  return 0;
}