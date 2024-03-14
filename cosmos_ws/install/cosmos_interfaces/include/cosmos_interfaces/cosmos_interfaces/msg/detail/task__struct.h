// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cosmos_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_
#define COSMOS_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Task in the package cosmos_interfaces.
typedef struct cosmos_interfaces__msg__Task
{
  int32_t mission;
  int32_t node;
  bool is_done;
} cosmos_interfaces__msg__Task;

// Struct for a sequence of cosmos_interfaces__msg__Task.
typedef struct cosmos_interfaces__msg__Task__Sequence
{
  cosmos_interfaces__msg__Task * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__msg__Task__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_
