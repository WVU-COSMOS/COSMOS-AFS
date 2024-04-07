// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cosmos_interfaces:msg/DCM.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__DCM__BUILDER_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__DCM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cosmos_interfaces/msg/detail/dcm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cosmos_interfaces
{

namespace msg
{

namespace builder
{

class Init_DCM_t
{
public:
  explicit Init_DCM_t(::cosmos_interfaces::msg::DCM & msg)
  : msg_(msg)
  {}
  ::cosmos_interfaces::msg::DCM t(::cosmos_interfaces::msg::DCM::_t_type arg)
  {
    msg_.t = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::msg::DCM msg_;
};

class Init_DCM_dcm
{
public:
  explicit Init_DCM_dcm(::cosmos_interfaces::msg::DCM & msg)
  : msg_(msg)
  {}
  Init_DCM_t dcm(::cosmos_interfaces::msg::DCM::_dcm_type arg)
  {
    msg_.dcm = std::move(arg);
    return Init_DCM_t(msg_);
  }

private:
  ::cosmos_interfaces::msg::DCM msg_;
};

class Init_DCM_is_abort
{
public:
  explicit Init_DCM_is_abort(::cosmos_interfaces::msg::DCM & msg)
  : msg_(msg)
  {}
  Init_DCM_dcm is_abort(::cosmos_interfaces::msg::DCM::_is_abort_type arg)
  {
    msg_.is_abort = std::move(arg);
    return Init_DCM_dcm(msg_);
  }

private:
  ::cosmos_interfaces::msg::DCM msg_;
};

class Init_DCM_is_target
{
public:
  explicit Init_DCM_is_target(::cosmos_interfaces::msg::DCM & msg)
  : msg_(msg)
  {}
  Init_DCM_is_abort is_target(::cosmos_interfaces::msg::DCM::_is_target_type arg)
  {
    msg_.is_target = std::move(arg);
    return Init_DCM_is_abort(msg_);
  }

private:
  ::cosmos_interfaces::msg::DCM msg_;
};

class Init_DCM_is_start
{
public:
  explicit Init_DCM_is_start(::cosmos_interfaces::msg::DCM & msg)
  : msg_(msg)
  {}
  Init_DCM_is_target is_start(::cosmos_interfaces::msg::DCM::_is_start_type arg)
  {
    msg_.is_start = std::move(arg);
    return Init_DCM_is_target(msg_);
  }

private:
  ::cosmos_interfaces::msg::DCM msg_;
};

class Init_DCM_from_node
{
public:
  explicit Init_DCM_from_node(::cosmos_interfaces::msg::DCM & msg)
  : msg_(msg)
  {}
  Init_DCM_is_start from_node(::cosmos_interfaces::msg::DCM::_from_node_type arg)
  {
    msg_.from_node = std::move(arg);
    return Init_DCM_is_start(msg_);
  }

private:
  ::cosmos_interfaces::msg::DCM msg_;
};

class Init_DCM_to_node
{
public:
  Init_DCM_to_node()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DCM_from_node to_node(::cosmos_interfaces::msg::DCM::_to_node_type arg)
  {
    msg_.to_node = std::move(arg);
    return Init_DCM_from_node(msg_);
  }

private:
  ::cosmos_interfaces::msg::DCM msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::msg::DCM>()
{
  return cosmos_interfaces::msg::builder::Init_DCM_to_node();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__DCM__BUILDER_HPP_
