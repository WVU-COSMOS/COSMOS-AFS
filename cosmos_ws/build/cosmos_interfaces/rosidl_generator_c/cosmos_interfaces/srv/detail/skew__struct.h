// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cosmos_interfaces:srv/Skew.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__SRV__DETAIL__SKEW__STRUCT_H_
#define COSMOS_INTERFACES__SRV__DETAIL__SKEW__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Skew in the package cosmos_interfaces.
typedef struct cosmos_interfaces__srv__Skew_Request
{
  double vector[3];
} cosmos_interfaces__srv__Skew_Request;

// Struct for a sequence of cosmos_interfaces__srv__Skew_Request.
typedef struct cosmos_interfaces__srv__Skew_Request__Sequence
{
  cosmos_interfaces__srv__Skew_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__srv__Skew_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Skew in the package cosmos_interfaces.
typedef struct cosmos_interfaces__srv__Skew_Response
{
  double skew[9];
} cosmos_interfaces__srv__Skew_Response;

// Struct for a sequence of cosmos_interfaces__srv__Skew_Response.
typedef struct cosmos_interfaces__srv__Skew_Response__Sequence
{
  cosmos_interfaces__srv__Skew_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__srv__Skew_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__SRV__DETAIL__SKEW__STRUCT_H_
