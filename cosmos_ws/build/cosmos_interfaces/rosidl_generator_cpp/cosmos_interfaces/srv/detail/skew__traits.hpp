// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cosmos_interfaces:srv/Skew.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__SRV__DETAIL__SKEW__TRAITS_HPP_
#define COSMOS_INTERFACES__SRV__DETAIL__SKEW__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cosmos_interfaces/srv/detail/skew__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cosmos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Skew_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: vector
  {
    if (msg.vector.size() == 0) {
      out << "vector: []";
    } else {
      out << "vector: [";
      size_t pending_items = msg.vector.size();
      for (auto item : msg.vector) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Skew_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vector
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vector.size() == 0) {
      out << "vector: []\n";
    } else {
      out << "vector:\n";
      for (auto item : msg.vector) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Skew_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cosmos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use cosmos_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cosmos_interfaces::srv::Skew_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cosmos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cosmos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cosmos_interfaces::srv::Skew_Request & msg)
{
  return cosmos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cosmos_interfaces::srv::Skew_Request>()
{
  return "cosmos_interfaces::srv::Skew_Request";
}

template<>
inline const char * name<cosmos_interfaces::srv::Skew_Request>()
{
  return "cosmos_interfaces/srv/Skew_Request";
}

template<>
struct has_fixed_size<cosmos_interfaces::srv::Skew_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cosmos_interfaces::srv::Skew_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cosmos_interfaces::srv::Skew_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cosmos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Skew_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: skew
  {
    if (msg.skew.size() == 0) {
      out << "skew: []";
    } else {
      out << "skew: [";
      size_t pending_items = msg.skew.size();
      for (auto item : msg.skew) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Skew_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: skew
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.skew.size() == 0) {
      out << "skew: []\n";
    } else {
      out << "skew:\n";
      for (auto item : msg.skew) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Skew_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cosmos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use cosmos_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cosmos_interfaces::srv::Skew_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cosmos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cosmos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cosmos_interfaces::srv::Skew_Response & msg)
{
  return cosmos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cosmos_interfaces::srv::Skew_Response>()
{
  return "cosmos_interfaces::srv::Skew_Response";
}

template<>
inline const char * name<cosmos_interfaces::srv::Skew_Response>()
{
  return "cosmos_interfaces/srv/Skew_Response";
}

template<>
struct has_fixed_size<cosmos_interfaces::srv::Skew_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cosmos_interfaces::srv::Skew_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cosmos_interfaces::srv::Skew_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cosmos_interfaces::srv::Skew>()
{
  return "cosmos_interfaces::srv::Skew";
}

template<>
inline const char * name<cosmos_interfaces::srv::Skew>()
{
  return "cosmos_interfaces/srv/Skew";
}

template<>
struct has_fixed_size<cosmos_interfaces::srv::Skew>
  : std::integral_constant<
    bool,
    has_fixed_size<cosmos_interfaces::srv::Skew_Request>::value &&
    has_fixed_size<cosmos_interfaces::srv::Skew_Response>::value
  >
{
};

template<>
struct has_bounded_size<cosmos_interfaces::srv::Skew>
  : std::integral_constant<
    bool,
    has_bounded_size<cosmos_interfaces::srv::Skew_Request>::value &&
    has_bounded_size<cosmos_interfaces::srv::Skew_Response>::value
  >
{
};

template<>
struct is_service<cosmos_interfaces::srv::Skew>
  : std::true_type
{
};

template<>
struct is_service_request<cosmos_interfaces::srv::Skew_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cosmos_interfaces::srv::Skew_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COSMOS_INTERFACES__SRV__DETAIL__SKEW__TRAITS_HPP_
