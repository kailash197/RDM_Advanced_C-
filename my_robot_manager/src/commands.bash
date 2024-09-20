# Terminal 1
cd ~/catkin_ws
catkin_make
source devel/setup.bash

#terminal 2
rosrun my_robot_manager robot_manager_node

#termianl 3
rosservice call /Turtle_1/log_current_position "{}"