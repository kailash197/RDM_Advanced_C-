#pragma once
#include "nav_msgs/Odometry.h"
#include <ros/ros.h>

class RobotManager {
private:
  std::string robot_name, robot_model, odom_topic = "/odom";
  float battery_capacity_kwh = 0.0;
  int total_operation_hours = 0;
  ros::Subscriber odom_sub;
  static int robot_count;

public:
  RobotManager(ros::NodeHandle *nh, std::string topic, std::string name,
               std::string model);
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg) const;
  void print_specifications() const;
};