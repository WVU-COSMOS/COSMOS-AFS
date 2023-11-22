// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cosmos_interfaces:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__POSITION__TRAITS_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cosmos_interfaces/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cosmos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Position & msg,
  std::ostream & out)
{
  out << "{";
  // member: mission
  {
    out << "mission: ";
    rosidl_generator_traits::value_to_yaml(msg.mission, out);
    out << ", ";
  }

  // member: current_position
  {
    out << "current_position: ";
    rosidl_generator_traits::value_to_yaml(msg.current_position, out);
    out << ", ";
  }

  // member: next_position
  {
    out << "next_position: ";
    rosidl_generator_traits::value_to_yaml(msg.next_position, out);
    out << ", ";
  }

  // member: is_running
  {
    out << "is_running: ";
    rosidl_generator_traits::value_to_yaml(msg.is_running, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mission
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission: ";
    rosidl_generator_traits::value_to_yaml(msg.mission, out);
    out << "\n";
  }

  // member: current_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_position: ";
    rosidl_generator_traits::value_to_yaml(msg.current_position, out);
    out << "\n";
  }

  // member: next_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "next_position: ";
    rosidl_generator_traits::value_to_yaml(msg.next_position, out);
    out << "\n";
  }

  // member: is_running
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_running: ";
    rosidl_generator_traits::value_to_yaml(msg.is_running, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Position & msg, bool use_flow_style = false)
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
  const cosmos_interfaces::msg::Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  cosmos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cosmos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const cosmos_interfaces::msg::Position & msg)
{
  return cosmos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cosmos_interfaces::msg::Position>()
{
  return "cosmos_interfaces::msg::Position";
}

template<>
inline const char * name<cosmos_interfaces::msg::Position>()
{
  return "cosmos_interfaces/msg/Position";
}

template<>
struct has_fixed_size<cosmos_interfaces::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cosmos_interfaces::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cosmos_interfaces::msg::Position>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COSMOS_INTERFACES__MSG__DETAIL__POSITION__TRAITS_HPP_
