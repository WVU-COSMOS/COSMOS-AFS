#ifndef REACTION_WHEELS_HPP_
#define REACTION_WHEELS_HPP_

#include "rclcpp/rclcpp.hpp"
#include "cosmos_interfaces/msg/reaction_wheels.hpp"
#include "cosmos_interfaces/msg/position.hpp"
#include "cosmos_interfaces/msg/attitude.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <Eigen/Geometry>

enum class COMMAND : int64_t
{
    MOVE_CLOCKWISE = 0,
    MOVE_COUNTERCLOCKWISE = 1
};

class AttitudeControl : public rclcpp::Node
{
public:
    AttitudeControl();

private:
    // Callbacks
    void sMachineCallback(const cosmos_interfaces::msg::Position::SharedPtr msg);

    // Publishers
    void rWheelsCommandPublisher(cosmos_interfaces::msg::ReactionWheels::SharedPtr rWheelsCommand);

    // Helper Functions
    void readAttitudeFile(size_t position);

    // Quaternions Functions
    cosmos_interfaces::msg::Attitude::SharedPtr getQuaternion(const std::string& line); // Get quaternion from file
    Eigen::Quaterniond toEigenQuaternion(const cosmos_interfaces::msg::Attitude& attitude_msg); // Change format of quaternion msg to Eigen library format
    Eigen::Quaterniond rotationQuaternion(const cosmos_interfaces::msg::Attitude& attitude_current,
                                             const cosmos_interfaces::msg::Attitude& attitude_desired); // Calculate the rotation quaternion from current to desired
    
    // Suscribers Pointers
    rclcpp::Subscription<cosmos_interfaces::msg::Position>::SharedPtr sMachineSubscriber_;

    // Publisher Pointers
    rclcpp::Publisher<cosmos_interfaces::msg::ReactionWheels>::SharedPtr rWheelsPub_;

    // Helper Variables
    std::string command_string_;
};

#endif