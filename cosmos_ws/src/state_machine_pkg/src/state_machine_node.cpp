#include "state_machine_pkg/state_machine_node.hpp"

StateMachine::StateMachine() : Node("state_machine")
{
    gSsubscriber_ = this->create_subscription<std_msgs::msg::Int32>(
            "gStation_Command", 10, std::bind(&StateMachine::gStationCallback, this, std::placeholders::_1));

    rWheelsPub_ = this->create_publisher<cosmos_interfaces::msg::ReactionWheels>("reactionWheels_Command", 10);

    RCLCPP_INFO(this->get_logger(), "State Machine has been started!");
}

void StateMachine::gStationCallback(const std_msgs::msg::Int32::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received from GStation: %d", msg->data);

    if(msg->data == 0)
    {
        auto command = cosmos_interfaces::msg::ReactionWheels();
        command.command = 0;
        command.speed = 150;
        command.running_time = 1500;
        rWheelsPub_->publish(command);
    }
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<StateMachine>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}