add_executable(robot_demo
    main.cpp
)

target_link_libraries(robot_demo

    PRIVATE

        robot_control
        robot_hardware
)