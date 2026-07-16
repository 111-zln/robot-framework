#pragma once


enum class RobotMode
{
    Idle,
    Moving,
    Paused,
    Error
};
enum class ControlMode
{
    Position,
    Velocity,
    Torque
};