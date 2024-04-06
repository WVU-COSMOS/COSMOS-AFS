// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cosmos_interfaces:msg/StateMachine.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__BUILDER_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cosmos_interfaces/msg/detail/state_machine__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cosmos_interfaces
{

namespace msg
{

namespace builder
{

class Init_StateMachine_is_abort
{
public:
  explicit Init_StateMachine_is_abort(::cosmos_interfaces::msg::StateMachine & msg)
  : msg_(msg)
  {}
  ::cosmos_interfaces::msg::StateMachine is_abort(::cosmos_interfaces::msg::StateMachine::_is_abort_type arg)
  {
    msg_.is_abort = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::msg::StateMachine msg_;
};

class Init_StateMachine_is_done
{
public:
  explicit Init_StateMachine_is_done(::cosmos_interfaces::msg::StateMachine & msg)
  : msg_(msg)
  {}
  Init_StateMachine_is_abort is_done(::cosmos_interfaces::msg::StateMachine::_is_done_type arg)
  {
    msg_.is_done = std::move(arg);
    return Init_StateMachine_is_abort(msg_);
  }

private:
  ::cosmos_interfaces::msg::StateMachine msg_;
};

class Init_StateMachine_is_start
{
public:
  explicit Init_StateMachine_is_start(::cosmos_interfaces::msg::StateMachine & msg)
  : msg_(msg)
  {}
  Init_StateMachine_is_done is_start(::cosmos_interfaces::msg::StateMachine::_is_start_type arg)
  {
    msg_.is_start = std::move(arg);
    return Init_StateMachine_is_done(msg_);
  }

private:
  ::cosmos_interfaces::msg::StateMachine msg_;
};

class Init_StateMachine_from_node
{
public:
  explicit Init_StateMachine_from_node(::cosmos_interfaces::msg::StateMachine & msg)
  : msg_(msg)
  {}
  Init_StateMachine_is_start from_node(::cosmos_interfaces::msg::StateMachine::_from_node_type arg)
  {
    msg_.from_node = std::move(arg);
    return Init_StateMachine_is_start(msg_);
  }

private:
  ::cosmos_interfaces::msg::StateMachine msg_;
};

class Init_StateMachine_to_node
{
public:
  explicit Init_StateMachine_to_node(::cosmos_interfaces::msg::StateMachine & msg)
  : msg_(msg)
  {}
  Init_StateMachine_from_node to_node(::cosmos_interfaces::msg::StateMachine::_to_node_type arg)
  {
    msg_.to_node = std::move(arg);
    return Init_StateMachine_from_node(msg_);
  }

private:
  ::cosmos_interfaces::msg::StateMachine msg_;
};

class Init_StateMachine_mission
{
public:
  Init_StateMachine_mission()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateMachine_to_node mission(::cosmos_interfaces::msg::StateMachine::_mission_type arg)
  {
    msg_.mission = std::move(arg);
    return Init_StateMachine_to_node(msg_);
  }

private:
  ::cosmos_interfaces::msg::StateMachine msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::msg::StateMachine>()
{
  return cosmos_interfaces::msg::builder::Init_StateMachine_mission();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__BUILDER_HPP_
