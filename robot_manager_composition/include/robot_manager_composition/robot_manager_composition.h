#pragma once
#include "robot_manager_composition/system_information.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotManagerComposition {

public:
  RobotManagerComposition(){};
  RobotManagerComposition(ros::NodeHandle *node_handle);
  RobotManagerComposition(ros::NodeHandle *node_handle,
                          ComputerUnit computer_unit);

protected:
  ros::NodeHandle *nh;
  void init_config_output_srv();
  bool output_enabled = false;

private:
  ComputerUnit c_unit;
  ros::ServiceServer config_output_srv;
  bool ConfigOutputCallback(std_srvs::SetBoolRequest &req,
                            std_srvs::SetBoolResponse &response);
};