#pragma once
#include "base_robot_manager.h"
#include "ros/node_handle.h"

class RobotManagerMobile : public RobotManagerBase {
public:
  RobotManagerMobile(){};
  RobotManagerMobile(ros::NodeHandle *nh_);
};