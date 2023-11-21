#ifndef STATE_MACHINE_HPP_
#define STATE_MACHINE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "cosmos_interfaces/msg/reaction_wheels.hpp"

enum class MISSION
{
    MOVE = 1,
    ORBIT = 2,
    FOLLOW = 3
};

enum class COMMAND : int64_t
{
    MOVE_CLOCKWISE = 0,
    MOVE_COUNTERCLOCKWISE = 1
};

class StateMachine : public rclcpp::Node
{
public:
    StateMachine();

private:
    void gStationCallback(const std_msgs::msg::Int32::SharedPtr msg);

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr gSsubscriber_;
    rclcpp::Publisher<cosmos_interfaces::msg::ReactionWheels>::SharedPtr rWheelsPub_;
};

#endif // STATE_MACHINE_HPP_