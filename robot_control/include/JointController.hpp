#pragma once

#include "HardwareInterface.hpp"
#include "RobotState.hpp"
#include "Pid.hpp"

class JointController
{
    public:

        JointController(std::size_t joint_id,
                RobotState& state,
                RobotCommand& command);

        void setTargetPosition(double position);

        double getTargetPosition() const;

        void setTargetVelocity(double velocity);

        double getTargetVelocity() const;

        void update(double dt);

        void stop();

        void setControlMode(ControlMode mode);

        ControlMode getControlMode() const;

    private:

        std::size_t joint_id_  ;

        double target_position_{0.0};

        double target_velocity_{0.0};

        RobotState& robot_state_;

        RobotCommand& robot_command_;

        ControlMode control_mode_{ControlMode::Position}; //以后用

        PID pid_;

        
};