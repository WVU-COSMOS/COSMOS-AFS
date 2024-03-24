// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cosmos_interfaces:msg/StateMachine.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__STRUCT_H_
#define COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'to_node'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/StateMachine in the package cosmos_interfaces.
typedef struct cosmos_interfaces__msg__StateMachine
{
  int32_t mission;
  rosidl_runtime_c__String to_node;
  bool is_start;
  bool is_abort;
} cosmos_interfaces__msg__StateMachine;

// Struct for a sequence of cosmos_interfaces__msg__StateMachine.
typedef struct cosmos_interfaces__msg__StateMachine__Sequence
{
  cosmos_interfaces__msg__StateMachine * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__msg__StateMachine__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__MSG__DETAIL__STATE_MACHINE__STRUCT_H_
