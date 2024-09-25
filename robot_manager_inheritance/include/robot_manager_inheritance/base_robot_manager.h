#pragma once
#include "ros/node_handle.h"
#include "ros/service_server.h"
#include "std_srvs/SetBoolRequest.h"
#include "std_srvs/SetBoolResponse.h"
#include <std_srvs/SetBool.h>
#include <string>

class RobotManagerBase {
private:
  ros::ServiceServer config_output_srv;
  bool ConfigOutputCallback(std_srvs::SetBoolRequest &req,
                            std_srvs::SetBoolResponse &res);

protected:
  ros::NodeHandle *nh_;
  std::string robot_name = "Lopho_base";
  std::string robot_location = "Everest";
  bool output_enabled = false;
  void init_config_output_srv();
  virtual void displayRobotDetails();

public:
  RobotManagerBase(){};
  RobotManagerBase(ros::NodeHandle *);
};