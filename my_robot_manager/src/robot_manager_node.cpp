#include "my_robot_manager/robot_manager.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  RobotManager robot("my_bot", "TurtleBot3", 0.14, 2400);
  robot.print_specification();
  return 0;
}