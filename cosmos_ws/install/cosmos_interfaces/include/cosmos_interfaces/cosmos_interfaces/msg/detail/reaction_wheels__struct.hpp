// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cosmos_interfaces:msg/ReactionWheels.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__STRUCT_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__msg__ReactionWheels __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__msg__ReactionWheels __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ReactionWheels_
{
  using Type = ReactionWheels_<ContainerAllocator>;

  explicit ReactionWheels_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0ll;
      this->speed = 0ll;
      this->running_time = 0ll;
    }
  }

  explicit ReactionWheels_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0ll;
      this->speed = 0ll;
      this->running_time = 0ll;
    }
  }

  // field types and members
  using _command_type =
    int64_t;
  _command_type command;
  using _speed_type =
    int64_t;
  _speed_type speed;
  using _running_time_type =
    int64_t;
  _running_time_type running_time;

  // setters for named parameter idiom
  Type & set__command(
    const int64_t & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__speed(
    const int64_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__running_time(
    const int64_t & _arg)
  {
    this->running_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__msg__ReactionWheels
    std::shared_ptr<cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__msg__ReactionWheels
    std::shared_ptr<cosmos_interfaces::msg::ReactionWheels_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReactionWheels_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->running_time != other.running_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReactionWheels_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReactionWheels_

// alias to use template instance with default allocator
using ReactionWheels =
  cosmos_interfaces::msg::ReactionWheels_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__STRUCT_HPP_
