add_library(robot_control

    src/RobotState.cpp
    src/RobotCommand.cpp
    src/Pid.cpp
    src/JointController.cpp
    src/RobotController.cpp
)

target_include_directories(robot_control
    PUBLIC
        include
        ../robot_interfaces
        ../robot_common
)

target_link_libraries(robot_control
    PUBLIC
        robot_hardware
)