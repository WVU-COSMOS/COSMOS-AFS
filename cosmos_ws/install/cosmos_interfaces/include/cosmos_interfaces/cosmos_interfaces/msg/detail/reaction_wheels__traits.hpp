// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cosmos_interfaces:msg/ReactionWheels.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__TRAITS_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cosmos_interfaces/msg/detail/reaction_wheels__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cosmos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ReactionWheels & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: running_time
  {
    out << "running_time: ";
    rosidl_generator_traits::value_to_yaml(msg.running_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ReactionWheels & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: running_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "running_time: ";
    rosidl_generator_traits::value_to_yaml(msg.running_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ReactionWheels & msg, bool use_flow_style = false)
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
  const cosmos_interfaces::msg::ReactionWheels & msg,
  std::ostream & out, size_t indentation = 0)
{
  cosmos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cosmos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const cosmos_interfaces::msg::ReactionWheels & msg)
{
  return cosmos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cosmos_interfaces::msg::ReactionWheels>()
{
  return "cosmos_interfaces::msg::ReactionWheels";
}

template<>
inline const char * name<cosmos_interfaces::msg::ReactionWheels>()
{
  return "cosmos_interfaces/msg/ReactionWheels";
}

template<>
struct has_fixed_size<cosmos_interfaces::msg::ReactionWheels>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cosmos_interfaces::msg::ReactionWheels>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cosmos_interfaces::msg::ReactionWheels>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__TRAITS_HPP_
