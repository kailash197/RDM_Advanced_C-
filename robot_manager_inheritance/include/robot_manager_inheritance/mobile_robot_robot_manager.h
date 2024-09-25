#pragma once
#include "base_robot_manager.h"
#include "ros/node_handle.h"
#include "ros/subscriber.h"
#include <nav_msgs/Odometry.h>
#include <string>

class RobotManagerMobile : public RobotManagerBase {
private:
  ros::Subscriber odom_subscriber;
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);

protected:
  void init_odom_subscriber();
  std::string odometry_topic = "/robot1/odom";

public:
  RobotManagerMobile(){};
  RobotManagerMobile(ros::NodeHandle *nh_);
};