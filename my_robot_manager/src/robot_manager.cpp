#include "../include/my_robot_manager/robot_manager.h"
#include <ros/ros.h>

RobotManager::RobotManager(std::string name, std::string model, float battery,
                           int hours)
    : robot_name(name), robot_model(model), battery_capacity_kwh(battery),
      total_operation_hours(hours) {
  ROS_INFO("Robot initialized.");
}

void RobotManager::print_specification() {
  ROS_INFO("Robot Name: %s", robot_name.c_str());
  ROS_INFO("Robot Model: %s", robot_model.c_str());
  ROS_INFO("Battery Capacity (kWh): %f", battery_capacity_kwh);
  ROS_INFO("Total Operation Hours: %d", total_operation_hours);
}
