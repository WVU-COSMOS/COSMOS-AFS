// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cosmos_interfaces:srv/AAToDCM.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cosmos_interfaces/srv/detail/aa_to_dcm__rosidl_typesupport_introspection_c.h"
#include "cosmos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cosmos_interfaces/srv/detail/aa_to_dcm__functions.h"
#include "cosmos_interfaces/srv/detail/aa_to_dcm__struct.h"


// Include directives for member types
// Member `ehat`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cosmos_interfaces__srv__AAToDCM_Request__init(message_memory);
}

void cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_fini_function(void * message_memory)
{
  cosmos_interfaces__srv__AAToDCM_Request__fini(message_memory);
}

size_t cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__size_function__AAToDCM_Request__ehat(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__get_const_function__AAToDCM_Request__ehat(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__get_function__AAToDCM_Request__ehat(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__fetch_function__AAToDCM_Request__ehat(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__get_const_function__AAToDCM_Request__ehat(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__assign_function__AAToDCM_Request__ehat(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__get_function__AAToDCM_Request__ehat(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__resize_function__AAToDCM_Request__ehat(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_message_member_array[2] = {
  {
    "ehat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__srv__AAToDCM_Request, ehat),  // bytes offset in struct
    NULL,  // default value
    cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__size_function__AAToDCM_Request__ehat,  // size() function pointer
    cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__get_const_function__AAToDCM_Request__ehat,  // get_const(index) function pointer
    cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__get_function__AAToDCM_Request__ehat,  // get(index) function pointer
    cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__fetch_function__AAToDCM_Request__ehat,  // fetch(index, &value) function pointer
    cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__assign_function__AAToDCM_Request__ehat,  // assign(index, value) function pointer
    cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__resize_function__AAToDCM_Request__ehat  // resize(index) function pointer
  },
  {
    "phimag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__srv__AAToDCM_Request, phimag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_message_members = {
  "cosmos_interfaces__srv",  // message namespace
  "AAToDCM_Request",  // message name
  2,  // number of fields
  sizeof(cosmos_interfaces__srv__AAToDCM_Request),
  cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_message_member_array,  // message members
  cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_message_type_support_handle = {
  0,
  &cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cosmos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, AAToDCM_Request)() {
  if (!cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_message_type_support_handle.typesupport_identifier) {
    cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cosmos_interfaces__srv__AAToDCM_Request__rosidl_typesupport_introspection_c__AAToDCM_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "cosmos_interfaces/srv/detail/aa_to_dcm__rosidl_typesupport_introspection_c.h"
// already included above
// #include "cosmos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "cosmos_interfaces/srv/detail/aa_to_dcm__functions.h"
// already included above
// #include "cosmos_interfaces/srv/detail/aa_to_dcm__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cosmos_interfaces__srv__AAToDCM_Response__init(message_memory);
}

void cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_fini_function(void * message_memory)
{
  cosmos_interfaces__srv__AAToDCM_Response__fini(message_memory);
}

size_t cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__size_function__AAToDCM_Response__dcm(
  const void * untyped_member)
{
  (void)untyped_member;
  return 9;
}

const void * cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__get_const_function__AAToDCM_Response__dcm(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__get_function__AAToDCM_Response__dcm(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__fetch_function__AAToDCM_Response__dcm(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__get_const_function__AAToDCM_Response__dcm(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__assign_function__AAToDCM_Response__dcm(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__get_function__AAToDCM_Response__dcm(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_message_member_array[1] = {
  {
    "dcm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    9,  // array size
    false,  // is upper bound
    offsetof(cosmos_interfaces__srv__AAToDCM_Response, dcm),  // bytes offset in struct
    NULL,  // default value
    cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__size_function__AAToDCM_Response__dcm,  // size() function pointer
    cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__get_const_function__AAToDCM_Response__dcm,  // get_const(index) function pointer
    cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__get_function__AAToDCM_Response__dcm,  // get(index) function pointer
    cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__fetch_function__AAToDCM_Response__dcm,  // fetch(index, &value) function pointer
    cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__assign_function__AAToDCM_Response__dcm,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_message_members = {
  "cosmos_interfaces__srv",  // message namespace
  "AAToDCM_Response",  // message name
  1,  // number of fields
  sizeof(cosmos_interfaces__srv__AAToDCM_Response),
  cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_message_member_array,  // message members
  cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_message_type_support_handle = {
  0,
  &cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cosmos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, AAToDCM_Response)() {
  if (!cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_message_type_support_handle.typesupport_identifier) {
    cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cosmos_interfaces__srv__AAToDCM_Response__rosidl_typesupport_introspection_c__AAToDCM_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "cosmos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "cosmos_interfaces/srv/detail/aa_to_dcm__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers cosmos_interfaces__srv__detail__aa_to_dcm__rosidl_typesupport_introspection_c__AAToDCM_service_members = {
  "cosmos_interfaces__srv",  // service namespace
  "AAToDCM",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // cosmos_interfaces__srv__detail__aa_to_dcm__rosidl_typesupport_introspection_c__AAToDCM_Request_message_type_support_handle,
  NULL  // response message
  // cosmos_interfaces__srv__detail__aa_to_dcm__rosidl_typesupport_introspection_c__AAToDCM_Response_message_type_support_handle
};

static rosidl_service_type_support_t cosmos_interfaces__srv__detail__aa_to_dcm__rosidl_typesupport_introspection_c__AAToDCM_service_type_support_handle = {
  0,
  &cosmos_interfaces__srv__detail__aa_to_dcm__rosidl_typesupport_introspection_c__AAToDCM_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, AAToDCM_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, AAToDCM_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cosmos_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, AAToDCM)() {
  if (!cosmos_interfaces__srv__detail__aa_to_dcm__rosidl_typesupport_introspection_c__AAToDCM_service_type_support_handle.typesupport_identifier) {
    cosmos_interfaces__srv__detail__aa_to_dcm__rosidl_typesupport_introspection_c__AAToDCM_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)cosmos_interfaces__srv__detail__aa_to_dcm__rosidl_typesupport_introspection_c__AAToDCM_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, AAToDCM_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cosmos_interfaces, srv, AAToDCM_Response)()->data;
  }

  return &cosmos_interfaces__srv__detail__aa_to_dcm__rosidl_typesupport_introspection_c__AAToDCM_service_type_support_handle;
}
