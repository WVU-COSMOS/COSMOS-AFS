// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cosmos_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cosmos_interfaces/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cosmos_interfaces
{

namespace msg
{

namespace builder
{

class Init_Task_is_done
{
public:
  explicit Init_Task_is_done(::cosmos_interfaces::msg::Task & msg)
  : msg_(msg)
  {}
  ::cosmos_interfaces::msg::Task is_done(::cosmos_interfaces::msg::Task::_is_done_type arg)
  {
    msg_.is_done = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::msg::Task msg_;
};

class Init_Task_node
{
public:
  explicit Init_Task_node(::cosmos_interfaces::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_is_done node(::cosmos_interfaces::msg::Task::_node_type arg)
  {
    msg_.node = std::move(arg);
    return Init_Task_is_done(msg_);
  }

private:
  ::cosmos_interfaces::msg::Task msg_;
};

class Init_Task_mission
{
public:
  Init_Task_mission()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Task_node mission(::cosmos_interfaces::msg::Task::_mission_type arg)
  {
    msg_.mission = std::move(arg);
    return Init_Task_node(msg_);
  }

private:
  ::cosmos_interfaces::msg::Task msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::msg::Task>()
{
  return cosmos_interfaces::msg::builder::Init_Task_mission();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__TASK__BUILDER_HPP_
