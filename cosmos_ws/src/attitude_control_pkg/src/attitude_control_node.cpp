#include "attitude_control_pkg/attitude_control_node.hpp"

AttitudeControl::AttitudeControl() : Node("attitude_control")
{
    sMachineSub_= this->create_subscription<cosmos_interfaces::msg::StateMachine>(
            "sm_command", 10, std::bind(&AttitudeControl::sMachineCallback, this, std::placeholders::_1));

    rWheelsSub_= this->create_subscription<cosmos_interfaces::msg::ReactionWheels>(
            "esp32_command", 10, std::bind(&AttitudeControl::rWheelsCallback, this, std::placeholders::_1));

    rWheelsPub_ = this->create_publisher<cosmos_interfaces::msg::ReactionWheels>("esp32_command", 10);
    sMachinePub_ = this->create_publisher<cosmos_interfaces::msg::StateMachine>("sm_command", 10);

    RCLCPP_INFO(this->get_logger(), "Attitude Control has been started!");
}

void AttitudeControl::sMachineCallback(const cosmos_interfaces::msg::StateMachine::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received:: Mission: %d", msg->mission);
    MISSION mission = static_cast<MISSION>(msg->mission);
    current_mission = msg->mission;
    if(mission == MISSION::MOVE_BY_TARGET)
    {
        auto rWheel_msg = cosmos_interfaces::msg::ReactionWheels();
        rWheel_msg.is_done = false;
        rWheel_msg.motor_x = true;
        rWheel_msg.motor_y = false;
        rWheel_msg.motor_z = false;
        rWheel_msg.speed_x = 1700;
        rWheel_msg.speed_y = 0;
        rWheel_msg.speed_z = 0;
        rWheel_msg.time_x = 3000;
        rWheel_msg.time_y = 0;
        rWheel_msg.time_z = 0;

        rWheelsPub_->publish(rWheel_msg);
        RCLCPP_INFO(this->get_logger(), "Published to esp32_command!");
    }
}

void AttitudeControl::rWheelsCallback(const cosmos_interfaces::msg::ReactionWheels::SharedPtr msg)
{
    if(msg->is_done)
    {
        auto sMachine_msg = cosmos_interfaces::msg::StateMachine();
        sMachine_msg.from_node = node_name;
        sMachine_msg.to_node = "StateMachine";
        sMachine_msg.is_abort = false;
        sMachine_msg.mission = current_mission;
        sMachine_msg.is_done = true;
        sMachinePub_->publish(sMachine_msg);
        RCLCPP_INFO(this->get_logger(), "Published to State Machine!");
    }
}

void AttitudeControl::readAttitudeFile(size_t position)
{
    std::string path = "../Attitude_Control/Satellite1_Attitude_Quaternions.csv";
    std::ifstream file(path);
    if(!file.is_open())
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to open CSV file");
        return;
    }

    std::string line;
    for (size_t current_line = 1; std::getline(file, line); ++current_line) {
      if (current_line == position) {
        auto attitude_msg = getQuaternion(line);
        break;
      }
    }

}

cosmos_interfaces::msg::Attitude::SharedPtr AttitudeControl::getQuaternion(const std::string& line)
{
    std::istringstream iss(line);
    double time;
    float q1, q2, q3, q4;

    if (!(iss >> time >> q1 >> q2 >> q3 >> q4)) {
      RCLCPP_ERROR(this->get_logger(), "Error reading CSV line: %s", line.c_str());
      return NULL;
    }

    auto attitude_msg = std::make_shared<cosmos_interfaces::msg::Attitude>();
    attitude_msg->time_stamp = time;
    attitude_msg->q1 = q1;
    attitude_msg->q2 = q2;
    attitude_msg->q3 = q3;
    attitude_msg->q4 = q4;

    RCLCPP_INFO(this->get_logger(), "Time=%.6f, Attitude: q1=%.6f, q2=%.6f, q3=%.6f, q4=%.6f", time, q1, q2, q3, q4);

    return attitude_msg;
}

Eigen::Quaterniond AttitudeControl::toEigenQuaternion(const cosmos_interfaces::msg::Attitude& attitude_msg)
{
    return Eigen::Quaterniond(attitude_msg.q4, attitude_msg.q1, attitude_msg.q2, attitude_msg.q3);
}

Eigen::Quaterniond AttitudeControl::rotationQuaternion(const cosmos_interfaces::msg::Attitude& attitude_current,
                                             const cosmos_interfaces::msg::Attitude& attitude_desired) {
    Eigen::Quaterniond q_current = toEigenQuaternion(attitude_current);
    Eigen::Quaterniond q_desired = toEigenQuaternion(attitude_desired);

    Eigen::Quaterniond q_rotation = q_desired * q_current.inverse();
    return q_rotation;
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AttitudeControl>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}