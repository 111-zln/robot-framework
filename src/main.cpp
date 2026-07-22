#include "RobotState.hpp"
#include "RobotCommand.hpp"
#include "RobotController.hpp"
#include "JointController.hpp"
#include "Pid.hpp"

#include "HardwareInterface.hpp"
#include "MockHardware.hpp"

#include <chrono>
#include <iostream>
#include <thread>


int main()
{
    constexpr std::size_t joint_count = 6;
    constexpr double target_position = 1.57;
    constexpr double control_period = 0.001;

    MockHardware hardware(joint_count);

    RobotController robot(hardware, joint_count);

    if (!robot.initialize())
    {
        std::cout << "Initialize Failed!" << std::endl;
        return -1;
    }

    robot.start();

    robot.setJointTargetPosition(0, target_position);

    bool running = true;
    int print_count = 0;

    while (true)
    {
        robot.update(control_period);

        if (++print_count >= 100)
        {
            print_count = 0;

            std::cout
                << "Joint0 Position: "
                << robot.state().getJointPosition(0)
                << '\n';
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));//当前线程暂停 1 毫秒
    }

    robot.stop();

    return 0;
}