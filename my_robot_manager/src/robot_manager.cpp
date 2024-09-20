#include "my_robot_manager/robot_manager.h"

int RobotManager::robot_count = 0;

RobotManager::RobotManager(ros::NodeHandle *nh, std::string topic,
                           std::string name, std::string model)
    : odom_topic(topic), robot_name(name), robot_model(model) {
  odom_sub =
      nh->subscribe(odom_topic, 1000, &RobotManager::odom_callback, this);
  std::string log_service_name = name + "/log_current_position";
  pos_log_service_server = nh->advertiseService(
      log_service_name, &RobotManager::log_service_callback, this);

  ROS_INFO("Robot %d initialized.", ++robot_count);
  if (pos_log_service_server) {
    ROS_INFO("Service %s created successfully", log_service_name.c_str());
  } else {
    ROS_ERROR("Failed to create service %s", log_service_name.c_str());
  }
}
void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg) {
  this->current_x_position = msg->pose.pose.position.x;
  this->current_y_position = msg->pose.pose.position.y;
}

bool RobotManager::log_service_callback(std_srvs::Trigger::Request &req,
                                        std_srvs::Trigger::Response &res) {
  ROS_INFO("%s position (x,y): %.3lf , %.3lf", robot_name.c_str(),
           this->current_x_position, this->current_y_position);
  res.success = true;
  res.message = "Position logged";
  return true;
}
void RobotManager::print_specifications() const {
  ROS_INFO("Robot Name: %s", robot_name.c_str());
  ROS_INFO("Robot Model: %s", robot_model.c_str());
  ROS_INFO("Battery Capacity (kWh): %.2f", battery_capacity_kwh);
  ROS_INFO("Total Operation Hours: %d\n", total_operation_hours);
}
