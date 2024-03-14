// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from cosmos_interfaces:srv/AAToDCM.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/srv/detail/aa_to_dcm__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "cosmos_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cosmos_interfaces/srv/detail/aa_to_dcm__struct.h"
#include "cosmos_interfaces/srv/detail/aa_to_dcm__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // ehat
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // ehat

// forward declare type support functions


using _AAToDCM_Request__ros_msg_type = cosmos_interfaces__srv__AAToDCM_Request;

static bool _AAToDCM_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AAToDCM_Request__ros_msg_type * ros_message = static_cast<const _AAToDCM_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: ehat
  {
    size_t size = ros_message->ehat.size;
    auto array_ptr = ros_message->ehat.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: phimag
  {
    cdr << ros_message->phimag;
  }

  return true;
}

static bool _AAToDCM_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AAToDCM_Request__ros_msg_type * ros_message = static_cast<_AAToDCM_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: ehat
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->ehat.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->ehat);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->ehat, size)) {
      fprintf(stderr, "failed to create array for field 'ehat'");
      return false;
    }
    auto array_ptr = ros_message->ehat.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: phimag
  {
    cdr >> ros_message->phimag;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t get_serialized_size_cosmos_interfaces__srv__AAToDCM_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AAToDCM_Request__ros_msg_type * ros_message = static_cast<const _AAToDCM_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ehat
  {
    size_t array_size = ros_message->ehat.size;
    auto array_ptr = ros_message->ehat.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name phimag
  {
    size_t item_size = sizeof(ros_message->phimag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AAToDCM_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_cosmos_interfaces__srv__AAToDCM_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t max_serialized_size_cosmos_interfaces__srv__AAToDCM_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: ehat
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: phimag
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _AAToDCM_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_cosmos_interfaces__srv__AAToDCM_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AAToDCM_Request = {
  "cosmos_interfaces::srv",
  "AAToDCM_Request",
  _AAToDCM_Request__cdr_serialize,
  _AAToDCM_Request__cdr_deserialize,
  _AAToDCM_Request__get_serialized_size,
  _AAToDCM_Request__max_serialized_size
};

static rosidl_message_type_support_t _AAToDCM_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AAToDCM_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cosmos_interfaces, srv, AAToDCM_Request)() {
  return &_AAToDCM_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "cosmos_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "cosmos_interfaces/srv/detail/aa_to_dcm__struct.h"
// already included above
// #include "cosmos_interfaces/srv/detail/aa_to_dcm__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _AAToDCM_Response__ros_msg_type = cosmos_interfaces__srv__AAToDCM_Response;

static bool _AAToDCM_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AAToDCM_Response__ros_msg_type * ros_message = static_cast<const _AAToDCM_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: dcm
  {
    size_t size = 9;
    auto array_ptr = ros_message->dcm;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _AAToDCM_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AAToDCM_Response__ros_msg_type * ros_message = static_cast<_AAToDCM_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: dcm
  {
    size_t size = 9;
    auto array_ptr = ros_message->dcm;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t get_serialized_size_cosmos_interfaces__srv__AAToDCM_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AAToDCM_Response__ros_msg_type * ros_message = static_cast<const _AAToDCM_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name dcm
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->dcm;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AAToDCM_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_cosmos_interfaces__srv__AAToDCM_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t max_serialized_size_cosmos_interfaces__srv__AAToDCM_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: dcm
  {
    size_t array_size = 9;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _AAToDCM_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_cosmos_interfaces__srv__AAToDCM_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AAToDCM_Response = {
  "cosmos_interfaces::srv",
  "AAToDCM_Response",
  _AAToDCM_Response__cdr_serialize,
  _AAToDCM_Response__cdr_deserialize,
  _AAToDCM_Response__get_serialized_size,
  _AAToDCM_Response__max_serialized_size
};

static rosidl_message_type_support_t _AAToDCM_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AAToDCM_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cosmos_interfaces, srv, AAToDCM_Response)() {
  return &_AAToDCM_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "cosmos_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cosmos_interfaces/srv/aa_to_dcm.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t AAToDCM__callbacks = {
  "cosmos_interfaces::srv",
  "AAToDCM",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cosmos_interfaces, srv, AAToDCM_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cosmos_interfaces, srv, AAToDCM_Response)(),
};

static rosidl_service_type_support_t AAToDCM__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &AAToDCM__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cosmos_interfaces, srv, AAToDCM)() {
  return &AAToDCM__handle;
}

#if defined(__cplusplus)
}
#endif
