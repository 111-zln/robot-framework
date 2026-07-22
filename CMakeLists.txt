cmake_minimum_required(VERSION 3.16)

project(RobotFramework)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(robot_control)
add_subdirectory(robot_hardware)
add_subdirectory(src)