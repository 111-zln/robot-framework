#include "JointController.hpp"
#include "Pid.hpp"
#include "RobotState.hpp"

JointController::JointController(
    std::size_t joint_id,
    RobotState& state,
    RobotCommand& command)

    : joint_id_(joint_id),
      robot_state_(state),
      robot_command_(command)
{
}

//关节目标位姿控制
void JointController::setTargetPosition(double position)
{
    target_position_ = position;
}

double JointController::getTargetPosition() const
{
    return target_position_;
}

//关节目标速度控制
void JointController::setTargetVelocity(double velocity)
{
    target_velocity_ = velocity;
}

double JointController::getTargetVelocity() const
{
    return target_velocity_;
}

//关节更新
void JointController::update(double dt)
{
    switch(control_mode_)
    {
    case ControlMode::Position:

        double current =robot_state_.getJointPosition(joint_id_);

        double velocity =pid_.update(target_position_, current, dt); //输入位姿，输出速度

        robot_command_.setJointVelocityCommand(joint_id_, velocity);

        break;

    case ControlMode::Velocity:

        robot_command_.setJointVelocityCommand(joint_id_,target_velocity_);

        break;

    case ControlMode::Torque:

        // 以后实现

        break;
    }
}

void JointController::stop()
{
    target_position_ =
        robot_state_.getJointPosition(joint_id_);

    robot_command_.setJointPositionCommand(
        joint_id_,
        target_position_);
}


void JointController::setControlMode(ControlMode mode)
{
    control_mode_ = mode;
}

ControlMode JointController::getControlMode() const
{
    return control_mode_;
}
