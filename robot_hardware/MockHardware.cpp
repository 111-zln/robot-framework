#include "MockHardware.hpp"


MockHardware::MockHardware(std::size_t joint_count) 
            :joint_position_(joint_count),
            joint_velocity_(joint_count),
            joint_effort_(joint_count)
{
}

bool MockHardware::connect()
{
    connected_ = true;

    return true;
}

bool MockHardware::disconnect()
{
    connected_ = false;

    enabled_ = false;
}

bool MockHardware::enable()
{
    if (!connected_)
    {
        return false;
    }

    enabled_ = true;

    return true;
}

bool MockHardware::disable()
{
    enabled_ = false;

    return true;
}

bool MockHardware::read(RobotState& state)
{
   if (!enabled_)
    {
        return false;
    }

    for (std::size_t i = 0; i < joint_position_.size(); ++i)
    {
        state.setJointPosition(i, joint_position_[i]);
        state.setJointVelocity(i, joint_velocity_[i]);
    }

    return true;
}

bool MockHardware::write(const RobotCommand& command)
{
    if (!enabled_)
    {
        return false;
    }

    for (std::size_t i = 0; i < joint_position_.size(); ++i)
    {
        joint_position_[i] =
            command.getJointPositionCommand(i);

        joint_velocity_[i] =
            command.getJointVelocityCommand(i);

        joint_effort_[i] =
            command.getJointTorqueCommand(i);
    }

    return true;
}