// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cosmos_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__msg__Attitude __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__msg__Attitude __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Attitude_
{
  using Type = Attitude_<ContainerAllocator>;

  explicit Attitude_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_stamp = 0.0;
      this->q1 = 0.0f;
      this->q2 = 0.0f;
      this->q3 = 0.0f;
      this->q4 = 0.0f;
    }
  }

  explicit Attitude_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_stamp = 0.0;
      this->q1 = 0.0f;
      this->q2 = 0.0f;
      this->q3 = 0.0f;
      this->q4 = 0.0f;
    }
  }

  // field types and members
  using _time_stamp_type =
    double;
  _time_stamp_type time_stamp;
  using _q1_type =
    float;
  _q1_type q1;
  using _q2_type =
    float;
  _q2_type q2;
  using _q3_type =
    float;
  _q3_type q3;
  using _q4_type =
    float;
  _q4_type q4;

  // setters for named parameter idiom
  Type & set__time_stamp(
    const double & _arg)
  {
    this->time_stamp = _arg;
    return *this;
  }
  Type & set__q1(
    const float & _arg)
  {
    this->q1 = _arg;
    return *this;
  }
  Type & set__q2(
    const float & _arg)
  {
    this->q2 = _arg;
    return *this;
  }
  Type & set__q3(
    const float & _arg)
  {
    this->q3 = _arg;
    return *this;
  }
  Type & set__q4(
    const float & _arg)
  {
    this->q4 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::msg::Attitude_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::msg::Attitude_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::Attitude_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::Attitude_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::Attitude_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::Attitude_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::Attitude_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::Attitude_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::Attitude_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::Attitude_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__msg__Attitude
    std::shared_ptr<cosmos_interfaces::msg::Attitude_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__msg__Attitude
    std::shared_ptr<cosmos_interfaces::msg::Attitude_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Attitude_ & other) const
  {
    if (this->time_stamp != other.time_stamp) {
      return false;
    }
    if (this->q1 != other.q1) {
      return false;
    }
    if (this->q2 != other.q2) {
      return false;
    }
    if (this->q3 != other.q3) {
      return false;
    }
    if (this->q4 != other.q4) {
      return false;
    }
    return true;
  }
  bool operator!=(const Attitude_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Attitude_

// alias to use template instance with default allocator
using Attitude =
  cosmos_interfaces::msg::Attitude_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_HPP_
