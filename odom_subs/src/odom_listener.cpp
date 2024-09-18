#include "../../library_velocity/include/library_velocity/library_velocity.h"
// #include "../../test_library/include/test_library/test_library.h"
#include "nav_msgs/Odometry.h"
#include "ros/ros.h"

void odomCallback(const nav_msgs::Odometry::ConstPtr &msg) {

  float x = msg->pose.pose.position.x;
  float y = msg->pose.pose.position.y;
  float linear_vel = msg->twist.twist.linear.x;
  float angular_vel = msg->twist.twist.angular.z;

  display_pos(x, y);
  display_vel(linear_vel, angular_vel);
  ros::Duration(0.5).sleep();
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "odom_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 100, odomCallback);

  ros::spin();

  return 0;
}