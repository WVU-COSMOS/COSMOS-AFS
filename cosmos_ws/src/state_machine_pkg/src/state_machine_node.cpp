#include "rclcpp/rclcpp.hpp"

class StateMachine : public rclcpp::Node // MODIFY NAME
{
public:
    StateMachine() : Node("state_machine"), counter_(0) // MODIFY NAME
    {
        RCLCPP_INFO(this->get_logger(), "Hello from State Machine");

        timer_ = this->create_wall_timer(std::chrono::seconds(1),
                                         std::bind(&StateMachine::timerCallback, this));
    }

private:

    void timerCallback()
    {
        counter_++;
        RCLCPP_INFO(this->get_logger(), "Hello from State Machine %d", counter_);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    int counter_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<StateMachine>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}