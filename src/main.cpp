#include "robot_control/RobotState.hpp"
#include "robot_control/RobotCommand.hpp"
#include "robot_control/RobotController.hpp"
#include "robot_control/JointController.hpp"
#include "robot_control/Pid.hpp"

#include "robot_hardware/HardwareInterface.hpp"
#include "robot_hardware/MockHardware.hpp"

#include <chrono>
#include <iostream>
#include <thread>


int main()
{
    constexpr std::size_t joint_count = 6;

    MockHardware hardware(joint_count);

    RobotController robot(hardware, joint_count);

    if (!robot.initialize())
    {
        std::cout << "Initialize Failed!" << std::endl;
        return -1;
    }

    robot.start();

    robot.setJointTargetPosition(0, 1.57);

    while (true)
    {
        robot.update(0.001);

        std::cout
            << "Joint0 Position : "
            << robot.state().getJointPosition(0)
            << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1));//当前线程暂停 1 毫秒
    }

    return 0;
}