#include "state_machine_pkg/state_machine_node.hpp"

StateMachine::StateMachine() : Node("state_machine")
{
    gSsubscriber_ = this->create_subscription<std_msgs::msg::Int32>(
            "gStation_Command", 10, std::bind(&StateMachine::gStationCallback, this, std::placeholders::_1));

    positionPub_ = this->create_publisher<cosmos_interfaces::msg::Position>("attitude_command", 10);

    RCLCPP_INFO(this->get_logger(), "State Machine has been started!");
}

void StateMachine::gStationCallback(const std_msgs::msg::Int32::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Mission Selected: %d", msg->data);

    if(msg->data == 1)
    {
        auto command = cosmos_interfaces::msg::Position();
        command.mission = msg->data;
        command.current_position = curr_position_;
        command.next_position = curr_position_ + 1;
        command.is_running = true;
        positionPub_->publish(command);
        RCLCPP_INFO(this->get_logger(), "Mission Published: %d", msg->data);
        curr_position_ += 1; 
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