// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cosmos_interfaces:srv/AAToDCM.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__STRUCT_HPP_
#define COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__srv__AAToDCM_Request __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__srv__AAToDCM_Request __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AAToDCM_Request_
{
  using Type = AAToDCM_Request_<ContainerAllocator>;

  explicit AAToDCM_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->phimag = 0.0;
    }
  }

  explicit AAToDCM_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->phimag = 0.0;
    }
  }

  // field types and members
  using _ehat_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _ehat_type ehat;
  using _phimag_type =
    double;
  _phimag_type phimag;

  // setters for named parameter idiom
  Type & set__ehat(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->ehat = _arg;
    return *this;
  }
  Type & set__phimag(
    const double & _arg)
  {
    this->phimag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__srv__AAToDCM_Request
    std::shared_ptr<cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__srv__AAToDCM_Request
    std::shared_ptr<cosmos_interfaces::srv::AAToDCM_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AAToDCM_Request_ & other) const
  {
    if (this->ehat != other.ehat) {
      return false;
    }
    if (this->phimag != other.phimag) {
      return false;
    }
    return true;
  }
  bool operator!=(const AAToDCM_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AAToDCM_Request_

// alias to use template instance with default allocator
using AAToDCM_Request =
  cosmos_interfaces::srv::AAToDCM_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cosmos_interfaces


#ifndef _WIN32
# define DEPRECATED__cosmos_interfaces__srv__AAToDCM_Response __attribute__((deprecated))
#else
# define DEPRECATED__cosmos_interfaces__srv__AAToDCM_Response __declspec(deprecated)
#endif

namespace cosmos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AAToDCM_Response_
{
  using Type = AAToDCM_Response_<ContainerAllocator>;

  explicit AAToDCM_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 9>::iterator, double>(this->dcm.begin(), this->dcm.end(), 0.0);
    }
  }

  explicit AAToDCM_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : dcm(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 9>::iterator, double>(this->dcm.begin(), this->dcm.end(), 0.0);
    }
  }

  // field types and members
  using _dcm_type =
    std::array<double, 9>;
  _dcm_type dcm;

  // setters for named parameter idiom
  Type & set__dcm(
    const std::array<double, 9> & _arg)
  {
    this->dcm = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cosmos_interfaces__srv__AAToDCM_Response
    std::shared_ptr<cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cosmos_interfaces__srv__AAToDCM_Response
    std::shared_ptr<cosmos_interfaces::srv::AAToDCM_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AAToDCM_Response_ & other) const
  {
    if (this->dcm != other.dcm) {
      return false;
    }
    return true;
  }
  bool operator!=(const AAToDCM_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AAToDCM_Response_

// alias to use template instance with default allocator
using AAToDCM_Response =
  cosmos_interfaces::srv::AAToDCM_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cosmos_interfaces

namespace cosmos_interfaces
{

namespace srv
{

struct AAToDCM
{
  using Request = cosmos_interfaces::srv::AAToDCM_Request;
  using Response = cosmos_interfaces::srv::AAToDCM_Response;
};

}  // namespace srv

}  // namespace cosmos_interfaces

#endif  // COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__STRUCT_HPP_
