// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cosmos_interfaces:msg/StateMachine.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__TRAITS_HPP_
#define COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cosmos_interfaces/msg/detail/state_machine__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cosmos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const StateMachine & msg,
  std::ostream & out)
{
  out << "{";
  // member: mission
  {
    out << "mission: ";
    rosidl_generator_traits::value_to_yaml(msg.mission, out);
    out << ", ";
  }

  // member: to_node
  {
    out << "to_node: ";
    rosidl_generator_traits::value_to_yaml(msg.to_node, out);
    out << ", ";
  }

  // member: from_node
  {
    out << "from_node: ";
    rosidl_generator_traits::value_to_yaml(msg.from_node, out);
    out << ", ";
  }

  // member: is_start
  {
    out << "is_start: ";
    rosidl_generator_traits::value_to_yaml(msg.is_start, out);
    out << ", ";
  }

  // member: is_done
  {
    out << "is_done: ";
    rosidl_generator_traits::value_to_yaml(msg.is_done, out);
    out << ", ";
  }

  // member: is_abort
  {
    out << "is_abort: ";
    rosidl_generator_traits::value_to_yaml(msg.is_abort, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StateMachine & msg,
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

  // member: to_node
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "to_node: ";
    rosidl_generator_traits::value_to_yaml(msg.to_node, out);
    out << "\n";
  }

  // member: from_node
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "from_node: ";
    rosidl_generator_traits::value_to_yaml(msg.from_node, out);
    out << "\n";
  }

  // member: is_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_start: ";
    rosidl_generator_traits::value_to_yaml(msg.is_start, out);
    out << "\n";
  }

  // member: is_done
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_done: ";
    rosidl_generator_traits::value_to_yaml(msg.is_done, out);
    out << "\n";
  }

  // member: is_abort
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_abort: ";
    rosidl_generator_traits::value_to_yaml(msg.is_abort, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StateMachine & msg, bool use_flow_style = false)
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
  const cosmos_interfaces::msg::StateMachine & msg,
  std::ostream & out, size_t indentation = 0)
{
  cosmos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cosmos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const cosmos_interfaces::msg::StateMachine & msg)
{
  return cosmos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cosmos_interfaces::msg::StateMachine>()
{
  return "cosmos_interfaces::msg::StateMachine";
}

template<>
inline const char * name<cosmos_interfaces::msg::StateMachine>()
{
  return "cosmos_interfaces/msg/StateMachine";
}

template<>
struct has_fixed_size<cosmos_interfaces::msg::StateMachine>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cosmos_interfaces::msg::StateMachine>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cosmos_interfaces::msg::StateMachine>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__TRAITS_HPP_
