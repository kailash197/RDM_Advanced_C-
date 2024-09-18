#include "robot_commander/robot_commander.h"
#include <iostream>
#include <set>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "pentagon_robot");
  RobotCommander robot;

  set<pair<float, float>> vertices;
  float posx, posy;

  robot.move_backwards(2);
  posx = robot.get_x_position();
  posy = robot.get_y_position();
  vertices.insert(make_pair(posx, posy)); // Use make_pair

  // Move robot in a pentagon shape
  for (int i = 0; i < 5; i++) {
    robot.move_forward(1);
    robot.turn(0.42, 3); // Assumed values for a pentagon turn
    posx = robot.get_x_position();
    posy = robot.get_y_position();
    vertices.insert(make_pair(posx, posy)); // Use make_pair
  }

  // Display the positions
  for (const auto &val : vertices) {
    cout << "Position X: " << val.first << " Position Y: " << val.second
         << endl;
  }

  return 0;
}
