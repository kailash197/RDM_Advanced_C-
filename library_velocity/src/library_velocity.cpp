#include "../include/library_velocity/library_velocity.h"

void display_pos(float pos_x, float pos_y) {
  std::cout << "Position X: " << pos_x << " Position Y: " << pos_y << std::endl;
}

void display_vel(float linear_vel, float angular_vel) {

  std::cout << "Linear velocity: " << linear_vel
            << " Angular Velocity: " << angular_vel << std::endl;
}