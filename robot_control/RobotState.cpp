#include "RobotState.hpp"

RobotState::RobotState(std::size_t joint_num) :
            joint_position_(joint_num,0.0),
            joint_velocity_(joint_num,0.0),
            joint_effort_(joint_num,0.0)
{
}

//关节位姿
void RobotState::setJointPosition(std::size_t index, double position)
{
    joint_position_[index] = position;
}
double RobotState::getJointPosition(std::size_t index) const
{
    return joint_position_[index];
}

//关节速度
void RobotState::setJointVelocity(std::size_t index, double velocity)
{
    joint_velocity_[index] = velocity;
}
double RobotState::getJointVelocity(std::size_t index) const
{
    return joint_velocity_[index];
}

//关节力矩
void RobotState::setJointEffort(std::size_t index,double effort)
{
    joint_effort_[index] = effort;
}
double RobotState::getJointEffort(std::size_t index) const
{
    return joint_effort_[index];
}

//机器模式
void RobotState::setRobotMode(RobotMode mode)
{
    mode_ = mode;
}
RobotMode RobotState::getRobotMode() const
{
    return mode_;
}


std::size_t RobotState::jointCount() const
{
    return joint_position_.size();
}