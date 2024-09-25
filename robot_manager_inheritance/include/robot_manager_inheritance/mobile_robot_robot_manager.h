#pragma once
#include "base_robot_manager.h"
#include "ros/node_handle.h"
#include "ros/subscriber.h"
#include <nav_msgs/Odometry.h>
#include <string>

class RobotManagerMobile : public RobotManagerBase {
private:
  float battery_charge_level = 0.55;
  std::string type_of_battery = "Lead acid batteries";
  ros::Subscriber odom_subscriber;
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);

protected:
  void init_odom_subscriber();
  std::string odometry_topic = "/robot1/odom";
  void displayRobotDetails() override;

public:
  RobotManagerMobile(){};
  RobotManagerMobile(ros::NodeHandle *nh_);
};