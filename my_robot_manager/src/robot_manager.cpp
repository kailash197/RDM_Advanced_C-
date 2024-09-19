#include "my_robot_manager/robot_manager.h"

RobotManager::RobotManager(ros::NodeHandle *nh, std::string topic,
                           std::string name, std::string model)
    : odom_topic(topic), robot_name(name), robot_model(model) {
  odom_sub =
      nh->subscribe(odom_topic, 1000, &RobotManager::odom_callback, this);
  ROS_INFO("Robot %d initialized.", ++robot_count);
}
void RobotManager::odom_callback(
    const nav_msgs::Odometry::ConstPtr &msg) const {
  ROS_INFO("%s position (x,y): %.3lf , %.3lf", robot_name.c_str(),
           msg->pose.pose.position.x, msg->pose.pose.position.y);
}
void RobotManager::print_specifications() const {
  ROS_INFO("Robot Name: %s", robot_name.c_str());
  ROS_INFO("Robot Model: %s", robot_model.c_str());
  ROS_INFO("Battery Capacity (kWh): %.2f", battery_capacity_kwh);
  ROS_INFO("Total Operation Hours: %d\n", total_operation_hours);
}
int RobotManager::robot_count = 0;
