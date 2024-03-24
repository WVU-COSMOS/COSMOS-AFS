// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cosmos_interfaces:msg/Camera.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__CAMERA__STRUCT_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__CAMERA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__msg__Camera __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__msg__Camera __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Camera_
{
  using Type = Camera_<ContainerAllocator>;

  explicit Camera_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->from_node = "";
      this->to_node = "";
      this->is_start = false;
      this->is_done = false;
      this->is_abort = false;
      this->is_target = false;
      this->img_num = 0l;
      this->next_img = false;
      this->u = 0l;
      this->v = 0l;
    }
  }

  explicit Camera_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : from_node(_alloc),
    to_node(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->from_node = "";
      this->to_node = "";
      this->is_start = false;
      this->is_done = false;
      this->is_abort = false;
      this->is_target = false;
      this->img_num = 0l;
      this->next_img = false;
      this->u = 0l;
      this->v = 0l;
    }
  }

  // field types and members
  using _from_node_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _from_node_type from_node;
  using _to_node_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _to_node_type to_node;
  using _is_start_type =
    bool;
  _is_start_type is_start;
  using _is_done_type =
    bool;
  _is_done_type is_done;
  using _is_abort_type =
    bool;
  _is_abort_type is_abort;
  using _is_target_type =
    bool;
  _is_target_type is_target;
  using _img_num_type =
    int32_t;
  _img_num_type img_num;
  using _next_img_type =
    bool;
  _next_img_type next_img;
  using _u_type =
    int32_t;
  _u_type u;
  using _v_type =
    int32_t;
  _v_type v;

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
  Type & set__is_start(
    const bool & _arg)
  {
    this->is_start = _arg;
    return *this;
  }
  Type & set__is_done(
    const bool & _arg)
  {
    this->is_done = _arg;
    return *this;
  }
  Type & set__is_abort(
    const bool & _arg)
  {
    this->is_abort = _arg;
    return *this;
  }
  Type & set__is_target(
    const bool & _arg)
  {
    this->is_target = _arg;
    return *this;
  }
  Type & set__img_num(
    const int32_t & _arg)
  {
    this->img_num = _arg;
    return *this;
  }
  Type & set__next_img(
    const bool & _arg)
  {
    this->next_img = _arg;
    return *this;
  }
  Type & set__u(
    const int32_t & _arg)
  {
    this->u = _arg;
    return *this;
  }
  Type & set__v(
    const int32_t & _arg)
  {
    this->v = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::msg::Camera_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::msg::Camera_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::Camera_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::msg::Camera_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::Camera_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::Camera_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::msg::Camera_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::msg::Camera_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::Camera_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::msg::Camera_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__msg__Camera
    std::shared_ptr<cosmos_interfaces::msg::Camera_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__msg__Camera
    std::shared_ptr<cosmos_interfaces::msg::Camera_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Camera_ & other) const
  {
    if (this->from_node != other.from_node) {
      return false;
    }
    if (this->to_node != other.to_node) {
      return false;
    }
    if (this->is_start != other.is_start) {
      return false;
    }
    if (this->is_done != other.is_done) {
      return false;
    }
    if (this->is_abort != other.is_abort) {
      return false;
    }
    if (this->is_target != other.is_target) {
      return false;
    }
    if (this->img_num != other.img_num) {
      return false;
    }
    if (this->next_img != other.next_img) {
      return false;
    }
    if (this->u != other.u) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    return true;
  }
  bool operator!=(const Camera_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Camera_

// alias to use template instance with default allocator
using Camera =
  cosmos_interfaces::msg::Camera_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__MSG__DETAIL__CAMERA__STRUCT_HPP_
