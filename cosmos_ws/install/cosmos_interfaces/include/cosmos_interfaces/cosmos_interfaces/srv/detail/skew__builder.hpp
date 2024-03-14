// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cosmos_interfaces:srv/Skew.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__SRV__DETAIL__SKEW__BUILDER_HPP_
#define COSMOS_INTERFACES__SRV__DETAIL__SKEW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cosmos_interfaces/srv/detail/skew__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cosmos_interfaces
{

namespace srv
{

namespace builder
{

class Init_Skew_Request_vector
{
public:
  Init_Skew_Request_vector()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cosmos_interfaces::srv::Skew_Request vector(::cosmos_interfaces::srv::Skew_Request::_vector_type arg)
  {
    msg_.vector = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::srv::Skew_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::srv::Skew_Request>()
{
  return cosmos_interfaces::srv::builder::Init_Skew_Request_vector();
}

}  // namespace cosmos_interfaces


namespace cosmos_interfaces
{

namespace srv
{

namespace builder
{

class Init_Skew_Response_skew
{
public:
  Init_Skew_Response_skew()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cosmos_interfaces::srv::Skew_Response skew(::cosmos_interfaces::srv::Skew_Response::_skew_type arg)
  {
    msg_.skew = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::srv::Skew_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::srv::Skew_Response>()
{
  return cosmos_interfaces::srv::builder::Init_Skew_Response_skew();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__SRV__DETAIL__SKEW__BUILDER_HPP_
