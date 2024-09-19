cmake_minimum_required(VERSION 3.0.2)
project(my_robot_manager)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  nav_msgs
)



###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
 INCLUDE_DIRS include/${PROJECT_NAME}
 LIBRARIES my_robot_manager
 CATKIN_DEPENDS roscpp nav_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(${PROJECT_NAME}_lib
  src/robot_manager.cpp
)

add_executable(robot_manager_node src/robot_manager_node.cpp src/robot_manager.cpp)
target_link_libraries(robot_manager_node ${catkin_LIBRARIES} my_robot_manager_lib)



