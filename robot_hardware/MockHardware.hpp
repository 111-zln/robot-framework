#pragma once

#include <vector>

#include "HardwareInterface.hpp"

class MockHardware : public HardwareInterface
{
public:

    explicit MockHardware(std::size_t joint_count = 6);

    bool connect() override;

    bool disconnect() override;

    bool enable() override;

    bool disable() override;

    bool read(RobotState& state) override;

    bool write(const RobotCommand& command,double dt) override;

private:

    bool connected_{false};
    bool enabled_{false};

    std::vector<double> joint_position_;
    std::vector<double> joint_velocity_;
    std::vector<double> joint_effort_;
    
};

