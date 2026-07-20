#include "RobotControl.hpp"

RobotController::RobotController(
    HardwareInterface& hardware,
    std::size_t joint_count)

    : robot_state_(joint_count),
      robot_command_(joint_count),
      hardware_(hardware)
{
}

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

   return true ;
    
}


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

   if (!hardware_.write(robot_command_))
   {
      return;
   }
}