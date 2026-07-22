#pragma once

#include "RobotState.hpp"
#include "RobotCommand.hpp"

class HardwareInterface
{
    public:

        virtual ~HardwareInterface() = default;

        virtual bool connect() = 0;

        virtual bool disconnect() = 0;

        virtual bool enable() = 0;

        virtual bool disable() = 0;

        virtual bool read(RobotState& state) = 0;

        virtual bool write(const RobotCommand& command , double dt) = 0;
};