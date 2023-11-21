// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cosmos_interfaces:msg/ReactionWheels.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__BUILDER_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cosmos_interfaces/msg/detail/reaction_wheels__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cosmos_interfaces
{

namespace msg
{

namespace builder
{

class Init_ReactionWheels_running_time
{
public:
  explicit Init_ReactionWheels_running_time(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  ::cosmos_interfaces::msg::ReactionWheels running_time(::cosmos_interfaces::msg::ReactionWheels::_running_time_type arg)
  {
    msg_.running_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_speed
{
public:
  explicit Init_ReactionWheels_speed(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_running_time speed(::cosmos_interfaces::msg::ReactionWheels::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_ReactionWheels_running_time(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_command
{
public:
  Init_ReactionWheels_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReactionWheels_speed command(::cosmos_interfaces::msg::ReactionWheels::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_ReactionWheels_speed(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::msg::ReactionWheels>()
{
  return cosmos_interfaces::msg::builder::Init_ReactionWheels_command();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__BUILDER_HPP_
