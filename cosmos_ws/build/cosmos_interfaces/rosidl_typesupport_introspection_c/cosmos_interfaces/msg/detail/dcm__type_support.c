// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cosmos_interfaces:msg/DCM.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cosmos_interfaces/msg/detail/dcm__rosidl_typesupport_introspection_c.h"
#include "cosmos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cosmos_interfaces/msg/detail/dcm__functions.h"
#include "cosmos_interfaces/msg/detail/dcm__struct.h"


// Include directives for member types
// Member `to_node`
// Member `from_node`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cosmos_interfaces__msg__DCM__init(message_memory);
}

void cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_fini_function(void * message_memory)
{
  cosmos_interfaces__msg__DCM__fini(message_memory);
}

size_t cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__size_function__DCM__dcm(
  const void * untyped_member)
{
  (void)untyped_member;
  return 9;
}

const void * cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__get_const_function__DCM__dcm(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__get_function__DCM__dcm(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__fetch_function__DCM__dcm(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__get_const_function__DCM__dcm(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__assign_function__DCM__dcm(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__get_function__DCM__dcm(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_message_member_array[7] = {
  {
    "to_node",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__DCM, to_node),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "from_node",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__DCM, from_node),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__DCM, is_start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__DCM, is_target),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_abort",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__DCM, is_abort),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dcm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    9,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__DCM, dcm),  // bytes offset in struct
    NULL,  // default value
    cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__size_function__DCM__dcm,  // size() function pointer
    cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__get_const_function__DCM__dcm,  // get_const(index) function pointer
    cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__get_function__DCM__dcm,  // get(index) function pointer
    cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__fetch_function__DCM__dcm,  // fetch(index, &value) function pointer
    cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__assign_function__DCM__dcm,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "t",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__msg__DCM, t),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_message_members = {
  "cosmos_interfaces__msg",  // message namespace
  "DCM",  // message name
  7,  // number of fields
  sizeof(cosmos_interfaces__msg__DCM),
  cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_message_member_array,  // message members
  cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_init_function,  // function to initialize message memory (memory has to be allocated)
  cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_message_type_support_handle = {
  0,
  &cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cosmos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, msg, DCM)() {
  if (!cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_message_type_support_handle.typesupport_identifier) {
    cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cosmos_interfaces__msg__DCM__rosidl_typesupport_introspection_c__DCM_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
