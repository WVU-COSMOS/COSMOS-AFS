#ifndef KINEMATICS_HPP_
#define KINEMATICS_HPP_

#include "rclcpp/rclcpp.hpp"
#include "cosmos_interfaces/msg/reaction_wheels.hpp"
#include "cosmos_interfaces/msg/position.hpp"
#include "cosmos_interfaces/msg/attitude.hpp"
#include "cosmos_interfaces/msg/dcm.hpp"
#include "cosmos_interfaces/msg/state_machine.hpp"

class Kinematics : public rclcpp::Node
{
public:
    Kinematics();

private:
    std::string node_name = "Kinematics";
    int current_mission = 0;
};

#endif