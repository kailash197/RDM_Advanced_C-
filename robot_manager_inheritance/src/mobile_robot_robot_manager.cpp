#include "../include/robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "../include/robot_manager_inheritance/base_robot_manager.h"

RobotManagerMobile::RobotManagerMobile(ros::NodeHandle *node_handle_) {
  nh_ = node_handle_;
  init_config_output_srv();
}