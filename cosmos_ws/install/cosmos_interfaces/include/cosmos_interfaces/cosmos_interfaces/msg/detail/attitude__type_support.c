// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cosmos_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cosmos_interfaces/msg/detail/attitude__rosidl_typesupport_introspection_c.h"
#include "cosmos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cosmos_interfaces/msg/detail/attitude__functions.h"
#include "cosmos_interfaces/msg/detail/attitude__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cosmos_interfaces__msg__Attitude__init(message_memory);
}

void cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_fini_function(void * message_memory)
{
  cosmos_interfaces__msg__Attitude__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_message_member_array[5] = {
  {
    "time_stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__Attitude, time_stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "q1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__Attitude, q1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "q2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__Attitude, q2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "q3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__Attitude, q3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "q4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__Attitude, q4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_message_members = {
  "cosmos_interfaces__msg",  // message namespace
  "Attitude",  // message name
  5,  // number of fields
  sizeof(cosmos_interfaces__msg__Attitude),
  cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_message_member_array,  // message members
  cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_init_function,  // function to initialize message memory (memory has to be allocated)
  cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_message_type_support_handle = {
  0,
  &cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cosmos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, msg, Attitude)() {
  if (!cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_message_type_support_handle.typesupport_identifier) {
    cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cosmos_interfaces__msg__Attitude__rosidl_typesupport_introspection_c__Attitude_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif