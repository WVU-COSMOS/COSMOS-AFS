// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cosmos_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_H_
#define COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Attitude in the package cosmos_interfaces.
typedef struct cosmos_interfaces__msg__Attitude
{
  double time_stamp;
  float q1;
  float q2;
  float q3;
  float q4;
} cosmos_interfaces__msg__Attitude;

// Struct for a sequence of cosmos_interfaces__msg__Attitude.
typedef struct cosmos_interfaces__msg__Attitude__Sequence
{
  cosmos_interfaces__msg__Attitude * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__msg__Attitude__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__MSG__DETAIL__ATTITUDE__STRUCT_H_
