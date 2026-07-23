#include "RobotController.hpp"

RobotController::RobotController(
    HardwareInterface& hardware,
    std::size_t joint_count)

    : robot_state_(joint_count),
      robot_command_(joint_count),
      hardware_(hardware)
{
}


//初始化
bool RobotController::initialize()
{
   if( !hardware_.connect())
   {
    return false ; 
   }
    
   if( !hardware_.enable())
   {
    return false ;
   }

   for (std::size_t i = 0; i < robot_state_.jointCount(); ++i)
   {
    joint_controllers_.emplace_back(i,robot_state_,robot_command_);
   }

   mode_ = RobotMode::Initialized;

   return true ;
    
}

//更新
void RobotController::update(double dt)
{
   if(!hardware_.read(robot_state_))
   {
      return;
   }

   for(auto& controller : joint_controllers_)
   {
      controller.update(dt);
   }

   if (!hardware_.write(robot_command_, dt))
   {
      return;
   }
   
}

//启动
void RobotController :: start()
{
   mode_ = RobotMode::Running;
}

//停止
void RobotController::stop()
{
    mode_ = RobotMode::Stopped;
}


void RobotController::setJointTargetPosition(std::size_t joint,double position)
{
   if (joint >= joint_controllers_.size())
   {
      return;
   }

   joint_controllers_[joint].setTargetPosition(position);
}

void RobotController::setJointTargetVelocity(std::size_t joint,double velocity)
{
     if (joint >= joint_controllers_.size())
   {
      return;
   }

   joint_controllers_[joint].setTargetVelocity(velocity);
}