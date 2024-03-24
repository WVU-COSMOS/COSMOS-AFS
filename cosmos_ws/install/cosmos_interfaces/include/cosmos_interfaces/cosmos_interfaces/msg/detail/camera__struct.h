// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cosmos_interfaces:msg/Camera.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__CAMERA__STRUCT_H_
#define COSMOS_INTERFACES__MSG__DETAIL__CAMERA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'from_node'
// Member 'to_node'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Camera in the package cosmos_interfaces.
typedef struct cosmos_interfaces__msg__Camera
{
  rosidl_runtime_c__String from_node;
  rosidl_runtime_c__String to_node;
  bool is_start;
  bool is_done;
  bool is_abort;
  bool is_target;
  int32_t img_num;
  bool next_img;
  int32_t u;
  int32_t v;
} cosmos_interfaces__msg__Camera;

// Struct for a sequence of cosmos_interfaces__msg__Camera.
typedef struct cosmos_interfaces__msg__Camera__Sequence
{
  cosmos_interfaces__msg__Camera * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__msg__Camera__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__MSG__DETAIL__CAMERA__STRUCT_H_
