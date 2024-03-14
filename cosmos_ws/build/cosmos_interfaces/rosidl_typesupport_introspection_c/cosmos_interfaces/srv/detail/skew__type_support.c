// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cosmos_interfaces:srv/Skew.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cosmos_interfaces/srv/detail/skew__rosidl_typesupport_introspection_c.h"
#include "cosmos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cosmos_interfaces/srv/detail/skew__functions.h"
#include "cosmos_interfaces/srv/detail/skew__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cosmos_interfaces__srv__Skew_Request__init(message_memory);
}

void cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_fini_function(void * message_memory)
{
  cosmos_interfaces__srv__Skew_Request__fini(message_memory);
}

size_t cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__size_function__Skew_Request__vector(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__get_const_function__Skew_Request__vector(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__get_function__Skew_Request__vector(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__fetch_function__Skew_Request__vector(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__get_const_function__Skew_Request__vector(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__assign_function__Skew_Request__vector(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__get_function__Skew_Request__vector(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_message_member_array[1] = {
  {
    "vector",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__srv__Skew_Request, vector),  // bytes offset in struct
    NULL,  // default value
    cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__size_function__Skew_Request__vector,  // size() function pointer
    cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__get_const_function__Skew_Request__vector,  // get_const(index) function pointer
    cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__get_function__Skew_Request__vector,  // get(index) function pointer
    cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__fetch_function__Skew_Request__vector,  // fetch(index, &value) function pointer
    cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__assign_function__Skew_Request__vector,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_message_members = {
  "cosmos_interfaces__srv",  // message namespace
  "Skew_Request",  // message name
  1,  // number of fields
  sizeof(cosmos_interfaces__srv__Skew_Request),
  cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_message_member_array,  // message members
  cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_message_type_support_handle = {
  0,
  &cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cosmos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, Skew_Request)() {
  if (!cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_message_type_support_handle.typesupport_identifier) {
    cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cosmos_interfaces__srv__Skew_Request__rosidl_typesupport_introspection_c__Skew_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "cosmos_interfaces/srv/detail/skew__rosidl_typesupport_introspection_c.h"
// already included above
// #include "cosmos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "cosmos_interfaces/srv/detail/skew__functions.h"
// already included above
// #include "cosmos_interfaces/srv/detail/skew__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cosmos_interfaces__srv__Skew_Response__init(message_memory);
}

void cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_fini_function(void * message_memory)
{
  cosmos_interfaces__srv__Skew_Response__fini(message_memory);
}

size_t cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__size_function__Skew_Response__skew(
  const void * untyped_member)
{
  (void)untyped_member;
  return 9;
}

const void * cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__get_const_function__Skew_Response__skew(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__get_function__Skew_Response__skew(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__fetch_function__Skew_Response__skew(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__get_const_function__Skew_Response__skew(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__assign_function__Skew_Response__skew(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__get_function__Skew_Response__skew(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_message_member_array[1] = {
  {
    "skew",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    9,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__srv__Skew_Response, skew),  // bytes offset in struct
    NULL,  // default value
    cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__size_function__Skew_Response__skew,  // size() function pointer
    cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__get_const_function__Skew_Response__skew,  // get_const(index) function pointer
    cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__get_function__Skew_Response__skew,  // get(index) function pointer
    cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__fetch_function__Skew_Response__skew,  // fetch(index, &value) function pointer
    cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__assign_function__Skew_Response__skew,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_message_members = {
  "cosmos_interfaces__srv",  // message namespace
  "Skew_Response",  // message name
  1,  // number of fields
  sizeof(cosmos_interfaces__srv__Skew_Response),
  cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_message_member_array,  // message members
  cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_message_type_support_handle = {
  0,
  &cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cosmos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, Skew_Response)() {
  if (!cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_message_type_support_handle.typesupport_identifier) {
    cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cosmos_interfaces__srv__Skew_Response__rosidl_typesupport_introspection_c__Skew_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "cosmos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "cosmos_interfaces/srv/detail/skew__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers cosmos_interfaces__srv__detail__skew__rosidl_typesupport_introspection_c__Skew_service_members = {
  "cosmos_interfaces__srv",  // service namespace
  "Skew",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // cosmos_interfaces__srv__detail__skew__rosidl_typesupport_introspection_c__Skew_Request_message_type_support_handle,
  NULL  // response message
  // cosmos_interfaces__srv__detail__skew__rosidl_typesupport_introspection_c__Skew_Response_message_type_support_handle
};

static rosidl_service_type_support_t cosmos_interfaces__srv__detail__skew__rosidl_typesupport_introspection_c__Skew_service_type_support_handle = {
  0,
  &cosmos_interfaces__srv__detail__skew__rosidl_typesupport_introspection_c__Skew_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, Skew_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, Skew_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cosmos_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, Skew)() {
  if (!cosmos_interfaces__srv__detail__skew__rosidl_typesupport_introspection_c__Skew_service_type_support_handle.typesupport_identifier) {
    cosmos_interfaces__srv__detail__skew__rosidl_typesupport_introspection_c__Skew_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)cosmos_interfaces__srv__detail__skew__rosidl_typesupport_introspection_c__Skew_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, Skew_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, Skew_Response)()->data;
  }

  return &cosmos_interfaces__srv__detail__skew__rosidl_typesupport_introspection_c__Skew_service_type_support_handle;
}
