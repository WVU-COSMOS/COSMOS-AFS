// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cosmos_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__BUILDER_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cosmos_interfaces/msg/detail/attitude__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cosmos_interfaces
{

namespace msg
{

namespace builder
{

class Init_Attitude_q4
{
public:
  explicit Init_Attitude_q4(::cosmos_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  ::cosmos_interfaces::msg::Attitude q4(::cosmos_interfaces::msg::Attitude::_q4_type arg)
  {
    msg_.q4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::msg::Attitude msg_;
};

class Init_Attitude_q3
{
public:
  explicit Init_Attitude_q3(::cosmos_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_q4 q3(::cosmos_interfaces::msg::Attitude::_q3_type arg)
  {
    msg_.q3 = std::move(arg);
    return Init_Attitude_q4(msg_);
  }

private:
  ::cosmos_interfaces::msg::Attitude msg_;
};

class Init_Attitude_q2
{
public:
  explicit Init_Attitude_q2(::cosmos_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_q3 q2(::cosmos_interfaces::msg::Attitude::_q2_type arg)
  {
    msg_.q2 = std::move(arg);
    return Init_Attitude_q3(msg_);
  }

private:
  ::cosmos_interfaces::msg::Attitude msg_;
};

class Init_Attitude_q1
{
public:
  explicit Init_Attitude_q1(::cosmos_interfaces::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_q2 q1(::cosmos_interfaces::msg::Attitude::_q1_type arg)
  {
    msg_.q1 = std::move(arg);
    return Init_Attitude_q2(msg_);
  }

private:
  ::cosmos_interfaces::msg::Attitude msg_;
};

class Init_Attitude_time_stamp
{
public:
  Init_Attitude_time_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Attitude_q1 time_stamp(::cosmos_interfaces::msg::Attitude::_time_stamp_type arg)
  {
    msg_.time_stamp = std::move(arg);
    return Init_Attitude_q1(msg_);
  }

private:
  ::cosmos_interfaces::msg::Attitude msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::msg::Attitude>()
{
  return cosmos_interfaces::msg::builder::Init_Attitude_time_stamp();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__BUILDER_HPP_
