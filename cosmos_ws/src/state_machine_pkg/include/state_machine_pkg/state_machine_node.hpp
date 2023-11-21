#ifndef STATE_MACHINE_HPP_
#define STATE_MACHINE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

enum class Mission
{
    MOVE = 1,
    ORBIT = 2,
    FOLLOW = 3
};

class StateMachine : public rclcpp::Node
{
public:
    StateMachine();

private:
    void gStationCallback(const std_msgs::msg::Int32::SharedPtr msg);

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr gSsubscriber_;
};

#endif // STATE_MACHINE_HPP_