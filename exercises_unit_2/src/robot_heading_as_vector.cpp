#include "robot_commander/robot_commander.h"
#include <cctype>
#include <cstddef>
#include <deque>
#include <ros/ros.h>
#include <vector>

template <typename T> void display(const T& container) {
  size_t length = container.size();
  for (int i = 0; i < length; i++) {
    ROS_INFO("Value at %d: %f", i, container.at(i));
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_vector");

  RobotCommander my_robot;

  // command the robot to keep going in circles
  my_robot.move_in_circles();

  int total_values;
  std::cout << "Enter the number of heading values that you want to capture: ";
  // get user input from the keyboard
  std::cin >> total_values;
  std::vector<float> headings;
  std::deque<float> headings_deque;
  // INSERT YOUR CODE BELOW THIS LINE
  for (int i = 0; i < total_values; i++) {
    ROS_INFO("Getting headings: %d", i);
    float h = my_robot.get_heading();
    headings.push_back(h);
    headings_deque.push_front(h);
    ros::Duration(1).sleep();
  }
  ROS_INFO("Headins in vector container...");
  display(headings);
  ROS_INFO("Headins in deque container...");
  display(headings_deque);

  // INSERT YOUR CODE ABOVE THIS LINE

  // stop the robot
  my_robot.stop_moving();

  return 0;
}