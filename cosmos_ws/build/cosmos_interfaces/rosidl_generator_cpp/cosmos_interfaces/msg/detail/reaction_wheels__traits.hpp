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
  // member: from_node
  {
    out << "from_node: ";
    rosidl_generator_traits::value_to_yaml(msg.from_node, out);
    out << ", ";
  }

  // member: to_node
  {
    out << "to_node: ";
    rosidl_generator_traits::value_to_yaml(msg.to_node, out);
    out << ", ";
  }

  // member: is_done
  {
    out << "is_done: ";
    rosidl_generator_traits::value_to_yaml(msg.is_done, out);
    out << ", ";
  }

  // member: motor_x
  {
    out << "motor_x: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_x, out);
    out << ", ";
  }

  // member: motor_y
  {
    out << "motor_y: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_y, out);
    out << ", ";
  }

  // member: motor_z
  {
    out << "motor_z: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_z, out);
    out << ", ";
  }

  // member: speed_x
  {
    out << "speed_x: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_x, out);
    out << ", ";
  }

  // member: speed_y
  {
    out << "speed_y: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_y, out);
    out << ", ";
  }

  // member: speed_z
  {
    out << "speed_z: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_z, out);
    out << ", ";
  }

  // member: time_x
  {
    out << "time_x: ";
    rosidl_generator_traits::value_to_yaml(msg.time_x, out);
    out << ", ";
  }

  // member: time_y
  {
    out << "time_y: ";
    rosidl_generator_traits::value_to_yaml(msg.time_y, out);
    out << ", ";
  }

  // member: time_z
  {
    out << "time_z: ";
    rosidl_generator_traits::value_to_yaml(msg.time_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ReactionWheels & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: from_node
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "from_node: ";
    rosidl_generator_traits::value_to_yaml(msg.from_node, out);
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

  // member: is_done
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_done: ";
    rosidl_generator_traits::value_to_yaml(msg.is_done, out);
    out << "\n";
  }

  // member: motor_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_x: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_x, out);
    out << "\n";
  }

  // member: motor_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_y: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_y, out);
    out << "\n";
  }

  // member: motor_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_z: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_z, out);
    out << "\n";
  }

  // member: speed_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_x: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_x, out);
    out << "\n";
  }

  // member: speed_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_y: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_y, out);
    out << "\n";
  }

  // member: speed_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_z: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_z, out);
    out << "\n";
  }

  // member: time_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_x: ";
    rosidl_generator_traits::value_to_yaml(msg.time_x, out);
    out << "\n";
  }

  // member: time_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_y: ";
    rosidl_generator_traits::value_to_yaml(msg.time_y, out);
    out << "\n";
  }

  // member: time_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_z: ";
    rosidl_generator_traits::value_to_yaml(msg.time_z, out);
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
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cosmos_interfaces::msg::ReactionWheels>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cosmos_interfaces::msg::ReactionWheels>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__TRAITS_HPP_
