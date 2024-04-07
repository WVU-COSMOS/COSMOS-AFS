// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cosmos_interfaces:msg/DCM.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__DCM__STRUCT_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__DCM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__msg__DCM __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__msg__DCM __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DCM_
{
  using Type = DCM_<ContainerAllocator>;

  explicit DCM_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->to_node = "";
      this->from_node = "";
      this->is_start = false;
      this->is_target = false;
      this->is_abort = false;
      std::fill<typename std::array<double, 9>::iterator, double>(this->dcm.begin(), this->dcm.end(), 0.0);
      this->t = 0.0;
    }
  }

  explicit DCM_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : to_node(_alloc),
    from_node(_alloc),
    dcm(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->to_node = "";
      this->from_node = "";
      this->is_start = false;
      this->is_target = false;
      this->is_abort = false;
      std::fill<typename std::array<double, 9>::iterator, double>(this->dcm.begin(), this->dcm.end(), 0.0);
      this->t = 0.0;
    }
  }

  // field types and members
  using _to_node_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _to_node_type to_node;
  using _from_node_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _from_node_type from_node;
  using _is_start_type =
    bool;
  _is_start_type is_start;
  using _is_target_type =
    bool;
  _is_target_type is_target;
  using _is_abort_type =
    bool;
  _is_abort_type is_abort;
  using _dcm_type =
    std::array<double, 9>;
  _dcm_type dcm;
  using _t_type =
    double;
  _t_type t;

  // setters for named parameter idiom
  Type & set__to_node(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->to_node = _arg;
    return *this;
  }
  Type & set__from_node(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->from_node = _arg;
    return *this;
  }
  Type & set__is_start(
    const bool & _arg)
  {
    this->is_start = _arg;
    return *this;
  }
  Type & set__is_target(
    const bool & _arg)
  {
    this->is_target = _arg;
    return *this;
  }
  Type & set__is_abort(
    const bool & _arg)
  {
    this->is_abort = _arg;
    return *this;
  }
  Type & set__dcm(
    const std::array<double, 9> & _arg)
  {
    this->dcm = _arg;
    return *this;
  }
  Type & set__t(
    const double & _arg)
  {
    this->t = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::msg::DCM_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::msg::DCM_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::DCM_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::DCM_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::DCM_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::DCM_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::DCM_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::DCM_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::DCM_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::DCM_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__msg__DCM
    std::shared_ptr<cosmos_interfaces::msg::DCM_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__msg__DCM
    std::shared_ptr<cosmos_interfaces::msg::DCM_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DCM_ & other) const
  {
    if (this->to_node != other.to_node) {
      return false;
    }
    if (this->from_node != other.from_node) {
      return false;
    }
    if (this->is_start != other.is_start) {
      return false;
    }
    if (this->is_target != other.is_target) {
      return false;
    }
    if (this->is_abort != other.is_abort) {
      return false;
    }
    if (this->dcm != other.dcm) {
      return false;
    }
    if (this->t != other.t) {
      return false;
    }
    return true;
  }
  bool operator!=(const DCM_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DCM_

// alias to use template instance with default allocator
using DCM =
  cosmos_interfaces::msg::DCM_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__DCM__STRUCT_HPP_
