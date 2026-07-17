#include "JointControl.hpp"
#include "Pid.hpp"
#include "RobotState.hpp"

JointControl::JointControl(
    std::size_t joint_id,
    RobotState& state,
    RobotCommand& command)

    : joint_id_(joint_id),
      robot_state_(state),
      robot_command_(command)
{
}


void JointControl::setTargetPosition(double position)
{
    target_position_ = position;
}

double JointControl::getTargetPosition() const
{
    return target_position_;
}

void JointControl::setTargetVelocity(double velocity)
{
    target_velocity_ = velocity;
}

double JointControl::getTargetVelocity() const
{
    return target_velocity_;
}

void JointControl::update(double dt)
{
    robot_command_.setJointPositionCommand(
        joint_id_,
        target_position_);

}

void JointControl::stop()
{
    target_position_ =
        robot_state_.getJointPosition(joint_id_);

    robot_command_.setJointPositionCommand(
        joint_id_,
        target_position_);
}

