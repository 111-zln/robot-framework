#pragma once

#include "robot_hardware/HardwareInterface.hpp"
#include "robot_control/RobotState.hpp"
#include "robot_control/Pid.hpp"

class JointControl
{
    public:

        JointControl(std::size_t joint_id,
                RobotState& state,
                RobotCommand& command);

        void setTargetPosition(double position);

        double getTargetPosition() const;

        void setTargetVelocity(double velocity);

        double getTargetVelocity() const;

        void update(double dt);

        void stop();

    private:

        std::size_t joint_id_;

        double target_position_{0.0};

        double target_velocity_{0.0};

        RobotState& robot_state_;

        RobotCommand& robot_command_;

        ControlMode control_mode_{ControlMode::Position};

        std::size_t jointId() const;
};