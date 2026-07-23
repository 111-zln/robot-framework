#pragma once

#include <cstddef>
#include <vector>

#include "robot_common/RobotType.hpp"
#include "robot_common/RobotMode.hpp"

class RobotState
{
    public:

        explicit RobotState(std::size_t joint_num = 6);


        void setJointPosition(std::size_t index, double position);
        double getJointPosition(std::size_t index) const;

        void setJointVelocity(std::size_t index, double velocity);
        double getJointVelocity(std::size_t index) const;

        void setJointEffort(std::size_t index,double effort);
        double getJointEffort(std::size_t index) const;

        std::size_t jointCount() const;

    private:

        std::vector<double>  joint_position_;

        std::vector<double>  joint_velocity_;

        std::vector<double>  joint_effort_;


};