cmake_minimum_required(VERSION 3.0)
project(example)

set(CMAKE_CXX_STANDARD 17)

# use without ROS, and pure fmt
# first install fmt from https://github.com/fmtlib/fmt
 find_package(fmt REQUIRED)
add_executable(example example.cpp)
target_link_libraries(example
        fmt::fmt
)


# use with rosfmt
# first install rosfmt with: sudo apt install ros-noetic-rosfmt

#set(rosfmt_DIR /opt/ros/noetic/share/rosfmt/cmake)
#find_package(rosfmt REQUIRED)
#include_directories(${rosfmt_INCLUDE_DIRS})
#add_executable(example example.cpp)
#target_link_libraries(example
#  ${rosfmt_LIBRARIES}
#)


# use with catkin and rosfmt
# first install rosfmt with: sudo apt install ros-noetic-rosfmt
# catkin_make
#find_package(catkin REQUIRED COMPONENTS
#        roscpp
#        rosfmt)
#include_directories(${catkin_INCLUDE_DIRS})
#add_executable(example example.cpp)
#target_link_libraries(example
#        ${catkin_LIBRARIES}
#)