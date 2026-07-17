#include "Pid.hpp"

PID :: PID() = default ;

void PID::setGain(double kp,
                  double ki,
                  double kd) 
{
    kp_ = kp;
    ki_ = ki;
    kd_ = kd;
}

double PID::update(double target,double current,double dt)
{
    double error = target - current; //误差

    integral_ += error * dt;         //积分

    double derivative =
        (error - last_error_) / dt;  //微分

    double output =                  //输出
        kp_ * error +
        ki_ * integral_ +
        kd_ * derivative;

    last_error_ = error;

    return output;
}

void PID::reset()
{
    integral_ = 0.0;

    last_error_ = 0.0;
}