// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cosmos_interfaces:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__POSITION__BUILDER_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cosmos_interfaces/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cosmos_interfaces
{

namespace msg
{

namespace builder
{

class Init_Position_is_running
{
public:
  explicit Init_Position_is_running(::cosmos_interfaces::msg::Position & msg)
  : msg_(msg)
  {}
  ::cosmos_interfaces::msg::Position is_running(::cosmos_interfaces::msg::Position::_is_running_type arg)
  {
    msg_.is_running = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::msg::Position msg_;
};

class Init_Position_next_position
{
public:
  explicit Init_Position_next_position(::cosmos_interfaces::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_is_running next_position(::cosmos_interfaces::msg::Position::_next_position_type arg)
  {
    msg_.next_position = std::move(arg);
    return Init_Position_is_running(msg_);
  }

private:
  ::cosmos_interfaces::msg::Position msg_;
};

class Init_Position_current_position
{
public:
  explicit Init_Position_current_position(::cosmos_interfaces::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_next_position current_position(::cosmos_interfaces::msg::Position::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return Init_Position_next_position(msg_);
  }

private:
  ::cosmos_interfaces::msg::Position msg_;
};

class Init_Position_mission
{
public:
  Init_Position_mission()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_current_position mission(::cosmos_interfaces::msg::Position::_mission_type arg)
  {
    msg_.mission = std::move(arg);
    return Init_Position_current_position(msg_);
  }

private:
  ::cosmos_interfaces::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::msg::Position>()
{
  return cosmos_interfaces::msg::builder::Init_Position_mission();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__POSITION__BUILDER_HPP_
