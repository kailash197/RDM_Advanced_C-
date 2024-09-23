#pragma once
#include "ros/service_server.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotManagerComposition {
private:
  ros::NodeHandle nh_;
  ros::ServiceServer service_server_;
  bool output_enabled;

public:
  RobotManagerComposition();
  bool service_callback_(std_srvs::SetBool::Request &req,
                         std_srvs::SetBool::Response &res);
};