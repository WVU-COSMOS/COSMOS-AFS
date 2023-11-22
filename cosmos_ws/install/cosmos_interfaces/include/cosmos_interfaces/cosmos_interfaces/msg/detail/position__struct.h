// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cosmos_interfaces:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__POSITION__STRUCT_H_
#define COSMOS_INTERFACES__MSG__DETAIL__POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Position in the package cosmos_interfaces.
typedef struct cosmos_interfaces__msg__Position
{
  int64_t mission;
  int64_t current_position;
  int64_t next_position;
  bool is_running;
} cosmos_interfaces__msg__Position;

// Struct for a sequence of cosmos_interfaces__msg__Position.
typedef struct cosmos_interfaces__msg__Position__Sequence
{
  cosmos_interfaces__msg__Position * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__msg__Position__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__MSG__DETAIL__POSITION__STRUCT_H_
