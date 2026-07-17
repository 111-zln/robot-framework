#include "RobotCommand.hpp"

RobotCommand::RobotCommand(std::size_t joint_num)
    : joint_position_command_(joint_num, 0.0),
      joint_velocity_command_(joint_num, 0.0),
      joint_torque_command_(joint_num, 0.0)
{
}

//位姿指令
void RobotCommand::setJointPositionCommand(std::size_t index,double position)
{
    joint_position_command_[index] = position;
}
double RobotCommand::getJointPositionCommand(std::size_t index) const
{
    return joint_position_command_[index];
}

//速度指令
void RobotCommand::setJointVelocityCommand(std::size_t index,double velocity)
{
    joint_velocity_command_[index] = velocity;
}

double RobotCommand::getJointVelocityCommand(std::size_t index) const
{
    return joint_velocity_command_[index];
}

//力矩指令
void RobotCommand::setJointTorqueCommand(std::size_t index, double torque)
{
    joint_torque_command_[index] = torque;
}

double RobotCommand::getJointTorqueCommand(std::size_t index) const
{
    return joint_torque_command_[index];
}


std::size_t RobotCommand::jointCount() const
{
    return joint_position_command_.size();
}