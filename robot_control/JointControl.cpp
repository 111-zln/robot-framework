#include "JointController.hpp"
#include "Pid.hpp"
#include "RobotState.hpp"
JointController::JointController(std::size_t joint_id,
                        RobotState& state,
                        HardwareInterface& hardware)

                :joint_id_(joint_id),
                robot_state_(state),
                hardware_(hardware)
{

}


void JointController::setTargetPosition(double position)
{
    target_position_ = position;
}

double JointController::getTargetPosition() const
{
    return target_position_;
}

void JointController::setTargetVelocity(double velocity)
{
    target_velocity_ = velocity;
}

double JointController::getTargetVelocity() const
{
    return target_velocity_;
}

void JointController::update(double dt)
{
    double current =
        robot_state_.getJointPosition(joint_id_);

    double output =
        pid_.update(
            target_position_,
            current,
            dt);

    hardware_.writeJointCommand(
        joint_id_,
        output);
}

void JointController::stop()
{
    target_velocity_ = 0.0;

    pid_.reset();
}

