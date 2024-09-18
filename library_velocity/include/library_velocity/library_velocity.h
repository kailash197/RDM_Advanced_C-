#ifndef VELOCITY_LIBRARY_H
#define VELOCIT_LIBRARY_H

#include <ros/ros.h>

void display_pos(float x, float y);
void display_vel(float linear_vel, float angular_vel);

// void display_pos(const float &x, const float &y);
// void display_vel(const float &linear_vel, const float &angular_vel);

#endif