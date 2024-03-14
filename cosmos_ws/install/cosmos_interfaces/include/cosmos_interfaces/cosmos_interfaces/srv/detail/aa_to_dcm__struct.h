// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cosmos_interfaces:srv/AAToDCM.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__STRUCT_H_
#define COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ehat'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/AAToDCM in the package cosmos_interfaces.
typedef struct cosmos_interfaces__srv__AAToDCM_Request
{
  rosidl_runtime_c__double__Sequence ehat;
  double phimag;
} cosmos_interfaces__srv__AAToDCM_Request;

// Struct for a sequence of cosmos_interfaces__srv__AAToDCM_Request.
typedef struct cosmos_interfaces__srv__AAToDCM_Request__Sequence
{
  cosmos_interfaces__srv__AAToDCM_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__srv__AAToDCM_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AAToDCM in the package cosmos_interfaces.
typedef struct cosmos_interfaces__srv__AAToDCM_Response
{
  double dcm[9];
} cosmos_interfaces__srv__AAToDCM_Response;

// Struct for a sequence of cosmos_interfaces__srv__AAToDCM_Response.
typedef struct cosmos_interfaces__srv__AAToDCM_Response__Sequence
{
  cosmos_interfaces__srv__AAToDCM_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cosmos_interfaces__srv__AAToDCM_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__STRUCT_H_
