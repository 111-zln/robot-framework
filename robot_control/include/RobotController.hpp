#pragma once

#include <vector>

#include "RobotState.hpp"
#include "RobotCommand.hpp"
#include "JointController.hpp"
#include "HardwareInterface.hpp"
#include "robot_common/RobotMode.hpp"

class RobotController
{
    public:

        explicit RobotController(
            HardwareInterface& hardware,
            std::size_t joint_count);

        bool initialize();

        bool start();

        void stop();

        void update(double dt);

        void setJointTargetPosition(std::size_t joint,double position);

        void setJointTargetVelocity(std::size_t joint,double velocity);

        const RobotState& state() const;

        const RobotCommand& command() const;

        RobotMode mode() const;

    private:

        bool running_{false};

        RobotState robot_state_;

        RobotCommand robot_command_;

        HardwareInterface& hardware_;

        std::vector<JointController> joint_controllers_;

        double control_period_{0.001};

        RobotMode mode_{RobotMode::Created};
};