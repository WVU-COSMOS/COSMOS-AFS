// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cosmos_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__TRAITS_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cosmos_interfaces/msg/detail/attitude__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cosmos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Attitude & msg,
  std::ostream & out)
{
  out << "{";
  // member: time_stamp
  {
    out << "time_stamp: ";
    rosidl_generator_traits::value_to_yaml(msg.time_stamp, out);
    out << ", ";
  }

  // member: q1
  {
    out << "q1: ";
    rosidl_generator_traits::value_to_yaml(msg.q1, out);
    out << ", ";
  }

  // member: q2
  {
    out << "q2: ";
    rosidl_generator_traits::value_to_yaml(msg.q2, out);
    out << ", ";
  }

  // member: q3
  {
    out << "q3: ";
    rosidl_generator_traits::value_to_yaml(msg.q3, out);
    out << ", ";
  }

  // member: q4
  {
    out << "q4: ";
    rosidl_generator_traits::value_to_yaml(msg.q4, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Attitude & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: time_stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_stamp: ";
    rosidl_generator_traits::value_to_yaml(msg.time_stamp, out);
    out << "\n";
  }

  // member: q1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q1: ";
    rosidl_generator_traits::value_to_yaml(msg.q1, out);
    out << "\n";
  }

  // member: q2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q2: ";
    rosidl_generator_traits::value_to_yaml(msg.q2, out);
    out << "\n";
  }

  // member: q3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q3: ";
    rosidl_generator_traits::value_to_yaml(msg.q3, out);
    out << "\n";
  }

  // member: q4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q4: ";
    rosidl_generator_traits::value_to_yaml(msg.q4, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Attitude & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cosmos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use cosmos_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cosmos_interfaces::msg::Attitude & msg,
  std::ostream & out, size_t indentation = 0)
{
  cosmos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cosmos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const cosmos_interfaces::msg::Attitude & msg)
{
  return cosmos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cosmos_interfaces::msg::Attitude>()
{
  return "cosmos_interfaces::msg::Attitude";
}

template<>
inline const char * name<cosmos_interfaces::msg::Attitude>()
{
  return "cosmos_interfaces/msg/Attitude";
}

template<>
struct has_fixed_size<cosmos_interfaces::msg::Attitude>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cosmos_interfaces::msg::Attitude>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cosmos_interfaces::msg::Attitude>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__TRAITS_HPP_
