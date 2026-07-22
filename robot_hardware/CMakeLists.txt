add_library(robot_hardware

    src/MockHardware.cpp
)

target_include_directories(robot_hardware
    PUBLIC
        include
        ../robot_interfaces
)