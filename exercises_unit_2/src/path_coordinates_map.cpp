#include "robot_commander/robot_commander.h"
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "pentagon_robot");
  RobotCommander robot;

  map<int, pair<float, float>> vertices;
  float posx, posy;
  int vertex = 1;

  posx = robot.get_x_position();
  posy = robot.get_y_position();
  vertices[vertex] = make_pair(posx, posy);

  // Move robot in a pentagon shape
  for (int i = 0; i < 5; i++) {
    robot.move_forward(1);
    robot.turn(0.42, 3); // Assumed values for a pentagon turn
    posx = robot.get_x_position();
    posy = robot.get_y_position();
    vertices.insert(make_pair(vertex, make_pair(posx, posy))); // Use make_pair
    vertex++;
  }

  // Display the positions
  for (const auto &val : vertices) {

    cout << "( " << val.second.first << ", " << val.second.second << " ) -> "
         << val.first << endl;
  }

  return 0;
}
