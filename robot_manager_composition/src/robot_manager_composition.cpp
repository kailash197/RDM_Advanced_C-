#include "robot_manager_composition/robot_manager_composition.h"

RobotManagerComposition::RobotManagerComposition()
    : nh_(), service_server_(nh_.advertiseService(
                 "/robot_manager_output",
                 &RobotManagerComposition::service_callback_, this)) {
  ROS_INFO("Service started: /robot_manager_output");
}

bool RobotManagerComposition::service_callback_(
    std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {
  this->output_enabled = req.data;
  res.success = true;
  res.message =
      (req.data) ? "Console output enabled." : "Console output disabled.";
  ROS_INFO("Console output enabled: %s",
           this->output_enabled ? "true" : "false");
  return true;
}