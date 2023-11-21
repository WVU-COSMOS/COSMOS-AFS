#include "attitude_control_pkg/reaction_wheels_node.hpp"

ReactionWheels::ReactionWheels() : Node("reaction_wheels")
{
    sMachineSubscriber_= this->create_subscription<cosmos_interfaces::msg::ReactionWheels>(
            "rWheels_Command", 10, std::bind(&ReactionWheels::sMachineCallback, this, std::placeholders::_1));

    rWheelsPub_ = this->create_publisher<cosmos_interfaces::msg::ReactionWheels>("reactionWheels_Command", 10);

    RCLCPP_INFO(this->get_logger(), "Reaction Wheels has been started!");
}

void ReactionWheels::sMachineCallback(const cosmos_interfaces::msg::ReactionWheels::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received: Command: %ld, Speed: %ld, Time: %ld.",
                         msg->command, msg->speed, msg->running_time);

    command_string_ = std::to_string(msg->command) + "," +
                                    std::to_string(msg->speed) + "," +
                                    std::to_string(msg->running_time) + "\n";
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ReactionWheels>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}