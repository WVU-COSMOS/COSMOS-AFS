#ifndef STATE_MACHINE_HPP_
#define STATE_MACHINE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "cosmos_interfaces/msg/reaction_wheels.hpp"
#include "cosmos_interfaces/msg/position.hpp"
#include "cosmos_interfaces/msg/task.hpp"
#include "cosmos_interfaces/msg/state_machine.hpp"

enum class MISSION : int32_t
{
    MOVE = 1,
    ORBIT = 2,
    FOLLOW = 3,
    TRACK = 4,
    MOVE_BY_TARGET = 5,
    STOP = 6
};

enum class MOVE_TARGET_MISSION : int32_t
{
    FIND_TARGET = 1,
    MOVE = 2,
    MISSION_END = 3
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
    void stateMachineCallback(const cosmos_interfaces::msg::StateMachine::SharedPtr msg);
    void move_by_target(int mission);

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr gSsubscriber_;
    rclcpp::Subscription<cosmos_interfaces::msg::StateMachine>::SharedPtr stateMachineSub_;
    rclcpp::Publisher<cosmos_interfaces::msg::Position>::SharedPtr positionPub_;
    rclcpp::Publisher<cosmos_interfaces::msg::StateMachine>::SharedPtr stateMachinePub_;

    int curr_position_ = 0;
    bool is_running = 0;
    bool is_target = 0;
    cosmos_interfaces::msg::StateMachine mission_status = cosmos_interfaces::msg::StateMachine();

    MOVE_TARGET_MISSION state = MOVE_TARGET_MISSION::FIND_TARGET;
};

#endif // STATE_MACHINE_HPP_