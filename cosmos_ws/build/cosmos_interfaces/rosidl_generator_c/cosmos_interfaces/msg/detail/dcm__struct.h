// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cosmos_interfaces:msg/DCM.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__DCM__STRUCT_H_
#define COSMOS_INTERFACES__MSG__DETAIL__DCM__STRUCT_H_

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
// Member 'from_node'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DCM in the package cosmos_interfaces.
typedef struct cosmos_interfaces__msg__DCM
{
  rosidl_runtime_c__String to_node;
  rosidl_runtime_c__String from_node;
  bool is_start;
  bool is_target;
  bool is_abort;
  double dcm[9];
  double t;
} cosmos_interfaces__msg__DCM;

// Struct for a sequence of cosmos_interfaces__msg__DCM.
typedef struct cosmos_interfaces__msg__DCM__Sequence
{
  cosmos_interfaces__msg__DCM * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__msg__DCM__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__MSG__DETAIL__DCM__STRUCT_H_
