cmake_minimum_required(VERSION 3.16)

project(RobotFramework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RobotFramework
    src/main.cpp

    robot_control/RobotController.cpp
    robot_control/RobotState.cpp
    robot_control/RobotCommand.cpp
    robot_control/JointController.cpp
    robot_control/Pid.cpp

    robot_hardware/MockHardware.cpp
)

target_include_directories(RobotFramework PRIVATE
    robot_control
    robot_hardware
    robot_interfaces
)