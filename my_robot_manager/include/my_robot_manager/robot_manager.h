#pragma once
#include "nav_msgs/Odometry.h"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>

class RobotManager {
private:
  std::string robot_name, robot_model, odom_topic = "/odom";
  float battery_capacity_kwh = 0.0;
  int total_operation_hours = 0;

  float current_x_position = 0.0, current_y_position = 0.0;

  ros::Subscriber odom_sub;
  ros::ServiceServer pos_log_service_server;

  static int robot_count;

public:
  RobotManager(ros::NodeHandle *nh, std::string topic, std::string name,
               std::string model);
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
  bool log_service_callback(std_srvs::Trigger::Request &req,
                            std_srvs::Trigger::Response &res);
  void print_specifications() const;
};