// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cosmos_interfaces:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__POSITION__STRUCT_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__msg__Position __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__msg__Position __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Position_
{
  using Type = Position_<ContainerAllocator>;

  explicit Position_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mission = 0ll;
      this->current_position = 0ll;
      this->next_position = 0ll;
      this->is_running = false;
    }
  }

  explicit Position_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mission = 0ll;
      this->current_position = 0ll;
      this->next_position = 0ll;
      this->is_running = false;
    }
  }

  // field types and members
  using _mission_type =
    int64_t;
  _mission_type mission;
  using _current_position_type =
    int64_t;
  _current_position_type current_position;
  using _next_position_type =
    int64_t;
  _next_position_type next_position;
  using _is_running_type =
    bool;
  _is_running_type is_running;

  // setters for named parameter idiom
  Type & set__mission(
    const int64_t & _arg)
  {
    this->mission = _arg;
    return *this;
  }
  Type & set__current_position(
    const int64_t & _arg)
  {
    this->current_position = _arg;
    return *this;
  }
  Type & set__next_position(
    const int64_t & _arg)
  {
    this->next_position = _arg;
    return *this;
  }
  Type & set__is_running(
    const bool & _arg)
  {
    this->is_running = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::msg::Position_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::msg::Position_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::Position_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::Position_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::Position_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::Position_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::Position_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::Position_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::Position_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::Position_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__msg__Position
    std::shared_ptr<cosmos_interfaces::msg::Position_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__msg__Position
    std::shared_ptr<cosmos_interfaces::msg::Position_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Position_ & other) const
  {
    if (this->mission != other.mission) {
      return false;
    }
    if (this->current_position != other.current_position) {
      return false;
    }
    if (this->next_position != other.next_position) {
      return false;
    }
    if (this->is_running != other.is_running) {
      return false;
    }
    return true;
  }
  bool operator!=(const Position_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Position_

// alias to use template instance with default allocator
using Position =
  cosmos_interfaces::msg::Position_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__POSITION__STRUCT_HPP_
