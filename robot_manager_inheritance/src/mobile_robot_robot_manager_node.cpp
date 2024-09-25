#include "../include/robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "ros/node_handle.h"
int main(int argc, char **argv) {
  ros::init(argc, argv, "mobile_robot_manager_ssinheritance");
  ros::NodeHandle node_handle;
  RobotManagerMobile *rmm = new RobotManagerMobile(&node_handle);
  /*
  RobotManagerMobile rmm1 = RobotManagerMobile(&node_handle);
  RobotManagerMobile rmm2(&node_handle);
  */

  ros::spin();
  return 0;
}