// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cosmos_interfaces:srv/Skew.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__SRV__DETAIL__SKEW__STRUCT_HPP_
#define COSMOS_INTERFACES__SRV__DETAIL__SKEW__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__srv__Skew_Request __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__srv__Skew_Request __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Skew_Request_
{
  using Type = Skew_Request_<ContainerAllocator>;

  explicit Skew_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->vector.begin(), this->vector.end(), 0.0);
    }
  }

  explicit Skew_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vector(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->vector.begin(), this->vector.end(), 0.0);
    }
  }

  // field types and members
  using _vector_type =
    std::array<double, 3>;
  _vector_type vector;

  // setters for named parameter idiom
  Type & set__vector(
    const std::array<double, 3> & _arg)
  {
    this->vector = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::srv::Skew_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::srv::Skew_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::srv::Skew_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::srv::Skew_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::srv::Skew_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::srv::Skew_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::srv::Skew_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::srv::Skew_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::srv::Skew_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::srv::Skew_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__srv__Skew_Request
    std::shared_ptr<cosmos_interfaces::srv::Skew_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__srv__Skew_Request
    std::shared_ptr<cosmos_interfaces::srv::Skew_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Skew_Request_ & other) const
  {
    if (this->vector != other.vector) {
      return false;
    }
    return true;
  }
  bool operator!=(const Skew_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Skew_Request_

// alias to use template instance with default allocator
using Skew_Request =
  cosmos_interfaces::srv::Skew_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cosmos_interfaces


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__srv__Skew_Response __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__srv__Skew_Response __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Skew_Response_
{
  using Type = Skew_Response_<ContainerAllocator>;

  explicit Skew_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 9>::iterator, double>(this->skew.begin(), this->skew.end(), 0.0);
    }
  }

  explicit Skew_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : skew(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 9>::iterator, double>(this->skew.begin(), this->skew.end(), 0.0);
    }
  }

  // field types and members
  using _skew_type =
    std::array<double, 9>;
  _skew_type skew;

  // setters for named parameter idiom
  Type & set__skew(
    const std::array<double, 9> & _arg)
  {
    this->skew = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::srv::Skew_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::srv::Skew_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::srv::Skew_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::srv::Skew_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::srv::Skew_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::srv::Skew_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::srv::Skew_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::srv::Skew_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::srv::Skew_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::srv::Skew_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__srv__Skew_Response
    std::shared_ptr<cosmos_interfaces::srv::Skew_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__srv__Skew_Response
    std::shared_ptr<cosmos_interfaces::srv::Skew_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Skew_Response_ & other) const
  {
    if (this->skew != other.skew) {
      return false;
    }
    return true;
  }
  bool operator!=(const Skew_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Skew_Response_

// alias to use template instance with default allocator
using Skew_Response =
  cosmos_interfaces::srv::Skew_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cosmos_interfaces

namespace cosmos_interfaces
{

namespace srv
{

struct Skew
{
  using Request = cosmos_interfaces::srv::Skew_Request;
  using Response = cosmos_interfaces::srv::Skew_Response;
};

}  // namespace srv

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__SRV__DETAIL__SKEW__STRUCT_HPP_
