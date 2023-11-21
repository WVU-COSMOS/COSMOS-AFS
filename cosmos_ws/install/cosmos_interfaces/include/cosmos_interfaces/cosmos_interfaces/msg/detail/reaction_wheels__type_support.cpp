// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cosmos_interfaces:msg/ReactionWheels.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cosmos_interfaces/msg/detail/reaction_wheels__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cosmos_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ReactionWheels_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cosmos_interfaces::msg::ReactionWheels(_init);
}

void ReactionWheels_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cosmos_interfaces::msg::ReactionWheels *>(message_memory);
  typed_message->~ReactionWheels();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ReactionWheels_message_member_array[3] = {
  {
    "command",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces::msg::ReactionWheels, command),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces::msg::ReactionWheels, speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "running_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces::msg::ReactionWheels, running_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ReactionWheels_message_members = {
  "cosmos_interfaces::msg",  // message namespace
  "ReactionWheels",  // message name
  3,  // number of fields
  sizeof(cosmos_interfaces::msg::ReactionWheels),
  ReactionWheels_message_member_array,  // message members
  ReactionWheels_init_function,  // function to initialize message memory (memory has to be allocated)
  ReactionWheels_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ReactionWheels_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ReactionWheels_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cosmos_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cosmos_interfaces::msg::ReactionWheels>()
{
  return &::cosmos_interfaces::msg::rosidl_typesupport_introspection_cpp::ReactionWheels_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cosmos_interfaces, msg, ReactionWheels)() {
  return &::cosmos_interfaces::msg::rosidl_typesupport_introspection_cpp::ReactionWheels_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
