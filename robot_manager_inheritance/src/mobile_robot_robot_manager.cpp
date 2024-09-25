#include "../include/robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "../include/robot_manager_inheritance/base_robot_manager.h"

RobotManagerMobile::RobotManagerMobile(ros::NodeHandle *node_handle_) {
  nh_ = node_handle_;
  init_config_output_srv();
  init_odom_subscriber();
}

void RobotManagerMobile::init_odom_subscriber() {
  odom_subscriber = nh_->subscribe(odometry_topic, 1000,
                                   &RobotManagerMobile::odom_callback, this);
  ROS_INFO("Base Odometry Subscriber Initialized: %s", odometry_topic.c_str());
}

void RobotManagerMobile::odom_callback(
    const nav_msgs::Odometry::ConstPtr &msg) {
  if (output_enabled) {
    float x = msg->pose.pose.position.x;
    float y = msg->pose.pose.position.y;
    ROS_INFO("Position (x,y): %.6f , %.6f", x, y);
  }
}

void RobotManagerMobile::displayRobotDetails() {
  ROS_INFO("Robot Name: %s", robot_name.c_str());
  ROS_INFO("Robot Location: %s", robot_location.c_str());
  ROS_INFO("Battery Charge Level: %lf", battery_charge_level);
  ROS_INFO("Type of Battery: %s", type_of_battery.c_str());
}
