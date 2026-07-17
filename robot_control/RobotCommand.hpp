#pragma once

#include <cstddef>
#include <vector>

class RobotCommand
{
    public:

        explicit RobotCommand(std::size_t joint_num = 6);

        void setJointPositionCommand(std::size_t index, double position);
        double getJointPositionCommand(std::size_t index) const;

        void setJointVelocityCommand(std::size_t index, double velocity);
        double getJointVelocityCommand(std::size_t index) const;

        void setJointTorqueCommand(std::size_t index, double torque);
        double getJointTorqueCommand(std::size_t index) const;

    std::size_t jointCount() const;

    private:

        std::vector<double> joint_position_command_;

        std::vector<double> joint_velocity_command_;

        std::vector<double> joint_torque_command_;
};