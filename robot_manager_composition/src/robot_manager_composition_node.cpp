#include "robot_manager_composition/robot_manager_composition.h"
#include <iostream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "Service_server_node");
  RobotManagerComposition robotManComposition;
  ros::spin();
  return 0;
}