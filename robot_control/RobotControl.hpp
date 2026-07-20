#pragma once

#include <vector>

#include "RobotState.hpp"
#include "RobotCommand.hpp"
#include "JointController.hpp"
#include "robot_hardware/HardwareInterface.hpp"

class RobotController
{
    public:

        explicit RobotController(
            HardwareInterface& hardware,
            std::size_t joint_count);

        bool initialize();

        void start();

        void stop();

        void update(double dt);

        RobotState& state();

        RobotCommand& command();

    private:

        bool running_{false};

        RobotState robot_state_;

        RobotCommand robot_command_;

        HardwareInterface& hardware_;

        std::vector<JointController> joint_controllers_;

        double control_period_{0.001};
};