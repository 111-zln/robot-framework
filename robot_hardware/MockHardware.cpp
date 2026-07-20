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

void MockHardware::disconnect()
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