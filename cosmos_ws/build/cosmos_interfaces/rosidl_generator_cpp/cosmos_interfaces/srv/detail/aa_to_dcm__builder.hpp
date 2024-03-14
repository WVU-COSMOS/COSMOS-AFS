// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cosmos_interfaces:srv/AAToDCM.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__BUILDER_HPP_
#define COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cosmos_interfaces/srv/detail/aa_to_dcm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cosmos_interfaces
{

namespace srv
{

namespace builder
{

class Init_AAToDCM_Request_phimag
{
public:
  explicit Init_AAToDCM_Request_phimag(::cosmos_interfaces::srv::AAToDCM_Request & msg)
  : msg_(msg)
  {}
  ::cosmos_interfaces::srv::AAToDCM_Request phimag(::cosmos_interfaces::srv::AAToDCM_Request::_phimag_type arg)
  {
    msg_.phimag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::srv::AAToDCM_Request msg_;
};

class Init_AAToDCM_Request_ehat
{
public:
  Init_AAToDCM_Request_ehat()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AAToDCM_Request_phimag ehat(::cosmos_interfaces::srv::AAToDCM_Request::_ehat_type arg)
  {
    msg_.ehat = std::move(arg);
    return Init_AAToDCM_Request_phimag(msg_);
  }

private:
  ::cosmos_interfaces::srv::AAToDCM_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::srv::AAToDCM_Request>()
{
  return cosmos_interfaces::srv::builder::Init_AAToDCM_Request_ehat();
}

}  // namespace cosmos_interfaces


namespace cosmos_interfaces
{

namespace srv
{

namespace builder
{

class Init_AAToDCM_Response_dcm
{
public:
  Init_AAToDCM_Response_dcm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cosmos_interfaces::srv::AAToDCM_Response dcm(::cosmos_interfaces::srv::AAToDCM_Response::_dcm_type arg)
  {
    msg_.dcm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::srv::AAToDCM_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::srv::AAToDCM_Response>()
{
  return cosmos_interfaces::srv::builder::Init_AAToDCM_Response_dcm();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__BUILDER_HPP_
