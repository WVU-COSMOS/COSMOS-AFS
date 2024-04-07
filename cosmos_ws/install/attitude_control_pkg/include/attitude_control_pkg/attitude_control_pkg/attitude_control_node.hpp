#ifndef ATTITUDE_CONTROL_HPP_
#define ATTITUDE_CONTROL_HPP_

#include "rclcpp/rclcpp.hpp"
#include "cosmos_interfaces/msg/reaction_wheels.hpp"
#include "cosmos_interfaces/msg/position.hpp"
#include "cosmos_interfaces/msg/attitude.hpp"
#include "cosmos_interfaces/msg/state_machine.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <Eigen/Geometry>

enum class COMMAND : int64_t
{
    MOVE_CLOCKWISE = 0,
    MOVE_COUNTERCLOCKWISE = 1
};

enum class MISSION : int32_t
{
    MOVE = 1,
    ORBIT = 2,
    FOLLOW = 3,
    TRACK = 4,
    MOVE_BY_TARGET = 5,
    STOP = 6
};

class AttitudeControl : public rclcpp::Node
{
public:
    AttitudeControl();

private:
    // Callbacks
    void sMachineCallback(const cosmos_interfaces::msg::StateMachine::SharedPtr msg);
    void rWheelsCallback(const cosmos_interfaces::msg::ReactionWheels::SharedPtr msg);

    // Publishers
    void rWheelsCommandPublisher(cosmos_interfaces::msg::ReactionWheels::SharedPtr rWheelsCommand);

    // Helper Functions
    void readAttitudeFile(size_t position);

    // Quaternions Functions
    cosmos_interfaces::msg::Attitude::SharedPtr getQuaternion(const std::string& line); // Get quaternion from file
    Eigen::Quaterniond toEigenQuaternion(const cosmos_interfaces::msg::Attitude& attitude_msg); // Change format of quaternion msg to Eigen library format
    Eigen::Quaterniond rotationQuaternion(const cosmos_interfaces::msg::Attitude& attitude_current,
                                             const cosmos_interfaces::msg::Attitude& attitude_desired); // Calculate the rotation quaternion from current to desired
    
    // Suscribers
    rclcpp::Subscription<cosmos_interfaces::msg::StateMachine>::SharedPtr sMachineSub_;
    rclcpp::Subscription<cosmos_interfaces::msg::ReactionWheels>::SharedPtr rWheelsSub_;

    // Publisher
    rclcpp::Publisher<cosmos_interfaces::msg::ReactionWheels>::SharedPtr rWheelsPub_;
    rclcpp::Publisher<cosmos_interfaces::msg::StateMachine>::SharedPtr sMachinePub_;

    // Helper Variables
    std::string command_string_;
    std::string node_name = "AttitudeControl";
    int current_mission = 0;
};

#endif