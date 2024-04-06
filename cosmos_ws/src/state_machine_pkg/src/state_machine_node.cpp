#include "state_machine_pkg/state_machine_node.hpp"

StateMachine::StateMachine() : Node("state_machine")
{
    gSsubscriber_ = this->create_subscription<std_msgs::msg::Int32>(
            "gStation_Command", 10, std::bind(&StateMachine::gStationCallback, this, std::placeholders::_1));

    stateMachineSub_ = this->create_subscription<cosmos_interfaces::msg::StateMachine>(
            "sm_command", 10, std::bind(&StateMachine::stateMachineCallback, this, std::placeholders::_1));

    positionPub_ = this->create_publisher<cosmos_interfaces::msg::Position>("attitude_command", 10);

    stateMachinePub_ = this->create_publisher<cosmos_interfaces::msg::StateMachine>("sm_command", 10);

    RCLCPP_INFO(this->get_logger(), "State Machine has been started!");
}

void StateMachine::gStationCallback(const std_msgs::msg::Int32::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Mission Selected: %d", msg->data);

    MISSION mission = static_cast<MISSION>(msg->data);

    switch(mission)
    {
        case MISSION::MOVE:
            break;

        case MISSION::ORBIT:
            break;

        case MISSION::FOLLOW:
            break;
        
        case MISSION::TRACK:

            if(!is_running)
            {
                mission_status.mission = msg->data;
                mission_status.to_node = "Camera";
                mission_status.is_start = true;
                mission_status.is_abort = false;
                stateMachinePub_->publish(mission_status);
                RCLCPP_INFO(this->get_logger(), "Mission %d Started!", msg->data);
                is_running = 1;
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "Mission %d Running!", msg->data);
            }

            break;

        case MISSION::MOVE_BY_TARGET:

            if(!is_running)
            {
                RCLCPP_INFO(this->get_logger(), "Mission %d Started!", msg->data);
                move_by_target(msg->data);
                is_running = 1;
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "Mission %d Running!", msg->data);
            }

            break;

        case MISSION::STOP:
            break;
    }
}

void StateMachine::stateMachineCallback(const cosmos_interfaces::msg::StateMachine::SharedPtr msg)
{
    if(msg->to_node == "StateMachine")
    {
        RCLCPP_INFO(this->get_logger(), "Response From: %s", msg->from_node.c_str());

        MISSION mission = static_cast<MISSION>(msg->mission);
        switch(mission)
        {
            case MISSION::MOVE:
                break;

            case MISSION::ORBIT:
                break;

            case MISSION::FOLLOW:
                break;
            
            case MISSION::TRACK:

                break;

            case MISSION::MOVE_BY_TARGET:

                if(msg->from_node == "Camera" && msg->is_done)
                {
                    is_target = true;
                    move_by_target(msg->mission);
                }

                if(msg->from_node == "Attitude_Control" && msg->is_done)
                {
                    is_target = false;
                    move_by_target(msg->mission);
                }

                break;

            case MISSION::STOP:
                break;
        }
    }
}

void StateMachine::move_by_target(int mission) 
{
    switch(StateMachine::state)
    {
        case MOVE_TARGET_MISSION::FIND_TARGET:
            if(!is_target)
            {
                mission_status.mission = mission;
                mission_status.to_node = "Camera";
                mission_status.is_start = true;
                mission_status.is_abort = false;
                stateMachinePub_->publish(mission_status);
                RCLCPP_INFO(this->get_logger(), "Looking for target!");
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "Target Found!");
                StateMachine::state = MOVE_TARGET_MISSION::MOVE;
                move_by_target(mission);
            }
            
            break;

        case MOVE_TARGET_MISSION::MOVE:
            RCLCPP_INFO(this->get_logger(), "Moving!");
            StateMachine::state = MOVE_TARGET_MISSION::MISSION_END;
            move_by_target(mission);
            break;
        
        case MOVE_TARGET_MISSION::MISSION_END:
            RCLCPP_INFO(this->get_logger(), "Mission Done!");
            break;
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