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
      this->from_node = "";
      this->to_node = "";
      this->is_done = false;
      this->motor_x = false;
      this->motor_y = false;
      this->motor_z = false;
      this->speed_x = 0l;
      this->speed_y = 0l;
      this->speed_z = 0l;
      this->time_x = 0ll;
      this->time_y = 0ll;
      this->time_z = 0ll;
    }
  }

  explicit ReactionWheels_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : from_node(_alloc),
    to_node(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->from_node = "";
      this->to_node = "";
      this->is_done = false;
      this->motor_x = false;
      this->motor_y = false;
      this->motor_z = false;
      this->speed_x = 0l;
      this->speed_y = 0l;
      this->speed_z = 0l;
      this->time_x = 0ll;
      this->time_y = 0ll;
      this->time_z = 0ll;
    }
  }

  // field types and members
  using _from_node_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _from_node_type from_node;
  using _to_node_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _to_node_type to_node;
  using _is_done_type =
    bool;
  _is_done_type is_done;
  using _motor_x_type =
    bool;
  _motor_x_type motor_x;
  using _motor_y_type =
    bool;
  _motor_y_type motor_y;
  using _motor_z_type =
    bool;
  _motor_z_type motor_z;
  using _speed_x_type =
    int32_t;
  _speed_x_type speed_x;
  using _speed_y_type =
    int32_t;
  _speed_y_type speed_y;
  using _speed_z_type =
    int32_t;
  _speed_z_type speed_z;
  using _time_x_type =
    int64_t;
  _time_x_type time_x;
  using _time_y_type =
    int64_t;
  _time_y_type time_y;
  using _time_z_type =
    int64_t;
  _time_z_type time_z;

  // setters for named parameter idiom
  Type & set__from_node(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->from_node = _arg;
    return *this;
  }
  Type & set__to_node(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->to_node = _arg;
    return *this;
  }
  Type & set__is_done(
    const bool & _arg)
  {
    this->is_done = _arg;
    return *this;
  }
  Type & set__motor_x(
    const bool & _arg)
  {
    this->motor_x = _arg;
    return *this;
  }
  Type & set__motor_y(
    const bool & _arg)
  {
    this->motor_y = _arg;
    return *this;
  }
  Type & set__motor_z(
    const bool & _arg)
  {
    this->motor_z = _arg;
    return *this;
  }
  Type & set__speed_x(
    const int32_t & _arg)
  {
    this->speed_x = _arg;
    return *this;
  }
  Type & set__speed_y(
    const int32_t & _arg)
  {
    this->speed_y = _arg;
    return *this;
  }
  Type & set__speed_z(
    const int32_t & _arg)
  {
    this->speed_z = _arg;
    return *this;
  }
  Type & set__time_x(
    const int64_t & _arg)
  {
    this->time_x = _arg;
    return *this;
  }
  Type & set__time_y(
    const int64_t & _arg)
  {
    this->time_y = _arg;
    return *this;
  }
  Type & set__time_z(
    const int64_t & _arg)
  {
    this->time_z = _arg;
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
    if (this->from_node != other.from_node) {
      return false;
    }
    if (this->to_node != other.to_node) {
      return false;
    }
    if (this->is_done != other.is_done) {
      return false;
    }
    if (this->motor_x != other.motor_x) {
      return false;
    }
    if (this->motor_y != other.motor_y) {
      return false;
    }
    if (this->motor_z != other.motor_z) {
      return false;
    }
    if (this->speed_x != other.speed_x) {
      return false;
    }
    if (this->speed_y != other.speed_y) {
      return false;
    }
    if (this->speed_z != other.speed_z) {
      return false;
    }
    if (this->time_x != other.time_x) {
      return false;
    }
    if (this->time_y != other.time_y) {
      return false;
    }
    if (this->time_z != other.time_z) {
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
