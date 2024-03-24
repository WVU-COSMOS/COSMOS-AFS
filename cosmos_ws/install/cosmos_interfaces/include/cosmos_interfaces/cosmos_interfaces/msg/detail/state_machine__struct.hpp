// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cosmos_interfaces:msg/StateMachine.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__STRUCT_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__msg__StateMachine __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__msg__StateMachine __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StateMachine_
{
  using Type = StateMachine_<ContainerAllocator>;

  explicit StateMachine_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mission = 0l;
      this->to_node = "";
      this->is_start = false;
      this->is_abort = false;
    }
  }

  explicit StateMachine_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : to_node(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mission = 0l;
      this->to_node = "";
      this->is_start = false;
      this->is_abort = false;
    }
  }

  // field types and members
  using _mission_type =
    int32_t;
  _mission_type mission;
  using _to_node_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _to_node_type to_node;
  using _is_start_type =
    bool;
  _is_start_type is_start;
  using _is_abort_type =
    bool;
  _is_abort_type is_abort;

  // setters for named parameter idiom
  Type & set__mission(
    const int32_t & _arg)
  {
    this->mission = _arg;
    return *this;
  }
  Type & set__to_node(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->to_node = _arg;
    return *this;
  }
  Type & set__is_start(
    const bool & _arg)
  {
    this->is_start = _arg;
    return *this;
  }
  Type & set__is_abort(
    const bool & _arg)
  {
    this->is_abort = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::msg::StateMachine_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::msg::StateMachine_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::StateMachine_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::StateMachine_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::StateMachine_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::StateMachine_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::StateMachine_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::StateMachine_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::StateMachine_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::StateMachine_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__msg__StateMachine
    std::shared_ptr<cosmos_interfaces::msg::StateMachine_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__msg__StateMachine
    std::shared_ptr<cosmos_interfaces::msg::StateMachine_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateMachine_ & other) const
  {
    if (this->mission != other.mission) {
      return false;
    }
    if (this->to_node != other.to_node) {
      return false;
    }
    if (this->is_start != other.is_start) {
      return false;
    }
    if (this->is_abort != other.is_abort) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateMachine_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateMachine_

// alias to use template instance with default allocator
using StateMachine =
  cosmos_interfaces::msg::StateMachine_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__STRUCT_HPP_
