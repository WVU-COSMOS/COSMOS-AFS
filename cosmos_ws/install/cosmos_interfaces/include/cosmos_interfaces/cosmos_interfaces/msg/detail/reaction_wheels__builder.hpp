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

class Init_ReactionWheels_time_z
{
public:
  explicit Init_ReactionWheels_time_z(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  ::cosmos_interfaces::msg::ReactionWheels time_z(::cosmos_interfaces::msg::ReactionWheels::_time_z_type arg)
  {
    msg_.time_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_time_y
{
public:
  explicit Init_ReactionWheels_time_y(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_time_z time_y(::cosmos_interfaces::msg::ReactionWheels::_time_y_type arg)
  {
    msg_.time_y = std::move(arg);
    return Init_ReactionWheels_time_z(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_time_x
{
public:
  explicit Init_ReactionWheels_time_x(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_time_y time_x(::cosmos_interfaces::msg::ReactionWheels::_time_x_type arg)
  {
    msg_.time_x = std::move(arg);
    return Init_ReactionWheels_time_y(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_speed_z
{
public:
  explicit Init_ReactionWheels_speed_z(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_time_x speed_z(::cosmos_interfaces::msg::ReactionWheels::_speed_z_type arg)
  {
    msg_.speed_z = std::move(arg);
    return Init_ReactionWheels_time_x(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_speed_y
{
public:
  explicit Init_ReactionWheels_speed_y(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_speed_z speed_y(::cosmos_interfaces::msg::ReactionWheels::_speed_y_type arg)
  {
    msg_.speed_y = std::move(arg);
    return Init_ReactionWheels_speed_z(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_speed_x
{
public:
  explicit Init_ReactionWheels_speed_x(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_speed_y speed_x(::cosmos_interfaces::msg::ReactionWheels::_speed_x_type arg)
  {
    msg_.speed_x = std::move(arg);
    return Init_ReactionWheels_speed_y(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_motor_z
{
public:
  explicit Init_ReactionWheels_motor_z(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_speed_x motor_z(::cosmos_interfaces::msg::ReactionWheels::_motor_z_type arg)
  {
    msg_.motor_z = std::move(arg);
    return Init_ReactionWheels_speed_x(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_motor_y
{
public:
  explicit Init_ReactionWheels_motor_y(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_motor_z motor_y(::cosmos_interfaces::msg::ReactionWheels::_motor_y_type arg)
  {
    msg_.motor_y = std::move(arg);
    return Init_ReactionWheels_motor_z(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_motor_x
{
public:
  explicit Init_ReactionWheels_motor_x(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_motor_y motor_x(::cosmos_interfaces::msg::ReactionWheels::_motor_x_type arg)
  {
    msg_.motor_x = std::move(arg);
    return Init_ReactionWheels_motor_y(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_is_done
{
public:
  explicit Init_ReactionWheels_is_done(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_motor_x is_done(::cosmos_interfaces::msg::ReactionWheels::_is_done_type arg)
  {
    msg_.is_done = std::move(arg);
    return Init_ReactionWheels_motor_x(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_to_node
{
public:
  explicit Init_ReactionWheels_to_node(::cosmos_interfaces::msg::ReactionWheels & msg)
  : msg_(msg)
  {}
  Init_ReactionWheels_is_done to_node(::cosmos_interfaces::msg::ReactionWheels::_to_node_type arg)
  {
    msg_.to_node = std::move(arg);
    return Init_ReactionWheels_is_done(msg_);
  }

private:
  ::cosmos_interfaces::msg::ReactionWheels msg_;
};

class Init_ReactionWheels_from_node
{
public:
  Init_ReactionWheels_from_node()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReactionWheels_to_node from_node(::cosmos_interfaces::msg::ReactionWheels::_from_node_type arg)
  {
    msg_.from_node = std::move(arg);
    return Init_ReactionWheels_to_node(msg_);
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
  return cosmos_interfaces::msg::builder::Init_ReactionWheels_from_node();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__BUILDER_HPP_
