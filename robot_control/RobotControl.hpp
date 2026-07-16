#pragma once

#include "RobotState.hpp"
#include "JointController.hpp"
#include "robot_hardware/HardwareInterface.hpp"
#include <vector>

class RobotController
{
    public:

        explicit RobotController(HardwareInterface& hardware, std::size_t joint_count);

        bool initialize();

        void start();

        void stop();

        void update(double dt);

        RobotState& state();

    private:

        std::size_t joint_count_;

        RobotState robot_state_;

        HardwareInterface& hardware_;

        std::vector<JointController> joint_controllers_;

        double control_period_{0.001};
};