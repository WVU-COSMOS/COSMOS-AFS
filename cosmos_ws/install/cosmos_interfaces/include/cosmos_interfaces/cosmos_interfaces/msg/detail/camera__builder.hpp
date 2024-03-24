// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cosmos_interfaces:msg/Camera.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__CAMERA__BUILDER_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__CAMERA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cosmos_interfaces/msg/detail/camera__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cosmos_interfaces
{

namespace msg
{

namespace builder
{

class Init_Camera_v
{
public:
  explicit Init_Camera_v(::cosmos_interfaces::msg::Camera & msg)
  : msg_(msg)
  {}
  ::cosmos_interfaces::msg::Camera v(::cosmos_interfaces::msg::Camera::_v_type arg)
  {
    msg_.v = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

class Init_Camera_u
{
public:
  explicit Init_Camera_u(::cosmos_interfaces::msg::Camera & msg)
  : msg_(msg)
  {}
  Init_Camera_v u(::cosmos_interfaces::msg::Camera::_u_type arg)
  {
    msg_.u = std::move(arg);
    return Init_Camera_v(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

class Init_Camera_next_img
{
public:
  explicit Init_Camera_next_img(::cosmos_interfaces::msg::Camera & msg)
  : msg_(msg)
  {}
  Init_Camera_u next_img(::cosmos_interfaces::msg::Camera::_next_img_type arg)
  {
    msg_.next_img = std::move(arg);
    return Init_Camera_u(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

class Init_Camera_img_num
{
public:
  explicit Init_Camera_img_num(::cosmos_interfaces::msg::Camera & msg)
  : msg_(msg)
  {}
  Init_Camera_next_img img_num(::cosmos_interfaces::msg::Camera::_img_num_type arg)
  {
    msg_.img_num = std::move(arg);
    return Init_Camera_next_img(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

class Init_Camera_is_target
{
public:
  explicit Init_Camera_is_target(::cosmos_interfaces::msg::Camera & msg)
  : msg_(msg)
  {}
  Init_Camera_img_num is_target(::cosmos_interfaces::msg::Camera::_is_target_type arg)
  {
    msg_.is_target = std::move(arg);
    return Init_Camera_img_num(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

class Init_Camera_is_abort
{
public:
  explicit Init_Camera_is_abort(::cosmos_interfaces::msg::Camera & msg)
  : msg_(msg)
  {}
  Init_Camera_is_target is_abort(::cosmos_interfaces::msg::Camera::_is_abort_type arg)
  {
    msg_.is_abort = std::move(arg);
    return Init_Camera_is_target(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

class Init_Camera_is_done
{
public:
  explicit Init_Camera_is_done(::cosmos_interfaces::msg::Camera & msg)
  : msg_(msg)
  {}
  Init_Camera_is_abort is_done(::cosmos_interfaces::msg::Camera::_is_done_type arg)
  {
    msg_.is_done = std::move(arg);
    return Init_Camera_is_abort(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

class Init_Camera_is_start
{
public:
  explicit Init_Camera_is_start(::cosmos_interfaces::msg::Camera & msg)
  : msg_(msg)
  {}
  Init_Camera_is_done is_start(::cosmos_interfaces::msg::Camera::_is_start_type arg)
  {
    msg_.is_start = std::move(arg);
    return Init_Camera_is_done(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

class Init_Camera_to_node
{
public:
  explicit Init_Camera_to_node(::cosmos_interfaces::msg::Camera & msg)
  : msg_(msg)
  {}
  Init_Camera_is_start to_node(::cosmos_interfaces::msg::Camera::_to_node_type arg)
  {
    msg_.to_node = std::move(arg);
    return Init_Camera_is_start(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

class Init_Camera_from_node
{
public:
  Init_Camera_from_node()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Camera_to_node from_node(::cosmos_interfaces::msg::Camera::_from_node_type arg)
  {
    msg_.from_node = std::move(arg);
    return Init_Camera_to_node(msg_);
  }

private:
  ::cosmos_interfaces::msg::Camera msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cosmos_interfaces::msg::Camera>()
{
  return cosmos_interfaces::msg::builder::Init_Camera_from_node();
}

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__CAMERA__BUILDER_HPP_
