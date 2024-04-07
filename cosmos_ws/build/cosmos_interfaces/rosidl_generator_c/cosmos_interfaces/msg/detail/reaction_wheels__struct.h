// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cosmos_interfaces:msg/ReactionWheels.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__STRUCT_H_
#define COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ReactionWheels in the package cosmos_interfaces.
typedef struct cosmos_interfaces__msg__ReactionWheels
{
  bool is_done;
  bool motor_x;
  bool motor_y;
  bool motor_z;
  int32_t speed_x;
  int32_t speed_y;
  int32_t speed_z;
  int64_t time_x;
  int64_t time_y;
  int64_t time_z;
} cosmos_interfaces__msg__ReactionWheels;

// Struct for a sequence of cosmos_interfaces__msg__ReactionWheels.
typedef struct cosmos_interfaces__msg__ReactionWheels__Sequence
{
  cosmos_interfaces__msg__ReactionWheels * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__msg__ReactionWheels__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__MSG__DETAIL__REACTION_WHEELS__STRUCT_H_
