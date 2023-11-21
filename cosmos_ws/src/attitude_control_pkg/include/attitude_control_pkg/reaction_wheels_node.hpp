#ifndef REACTION_WHEELS_HPP_
#define REACTION_WHEELS_HPP_

#include "rclcpp/rclcpp.hpp"
#include "cosmos_interfaces/msg/reaction_wheels.hpp"

enum class COMMAND : int64_t
{
    MOVE_CLOCKWISE = 0,
    MOVE_COUNTERCLOCKWISE = 1
};

class ReactionWheels : public rclcpp::Node
{
public:
    ReactionWheels();

private:
    void sMachineCallback(const cosmos_interfaces::msg::ReactionWheels::SharedPtr msg);
    void rWheelsCommandPublisher(cosmos_interfaces::msg::ReactionWheels::SharedPtr rWheelsCommand);

    rclcpp::Subscription<cosmos_interfaces::msg::ReactionWheels>::SharedPtr sMachineSubscriber_;
    rclcpp::Publisher<cosmos_interfaces::msg::ReactionWheels>::SharedPtr rWheelsPub_;
    
    std::string command_string_;
};

#endif