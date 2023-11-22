// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from cosmos_interfaces:msg/Position.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/position__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "cosmos_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cosmos_interfaces/msg/detail/position__struct.h"
#include "cosmos_interfaces/msg/detail/position__functions.h"
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


// forward declare type support functions


using _Position__ros_msg_type = cosmos_interfaces__msg__Position;

static bool _Position__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Position__ros_msg_type * ros_message = static_cast<const _Position__ros_msg_type *>(untyped_ros_message);
  // Field name: mission
  {
    cdr << ros_message->mission;
  }

  // Field name: current_position
  {
    cdr << ros_message->current_position;
  }

  // Field name: next_position
  {
    cdr << ros_message->next_position;
  }

  // Field name: is_running
  {
    cdr << (ros_message->is_running ? true : false);
  }

  return true;
}

static bool _Position__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Position__ros_msg_type * ros_message = static_cast<_Position__ros_msg_type *>(untyped_ros_message);
  // Field name: mission
  {
    cdr >> ros_message->mission;
  }

  // Field name: current_position
  {
    cdr >> ros_message->current_position;
  }

  // Field name: next_position
  {
    cdr >> ros_message->next_position;
  }

  // Field name: is_running
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_running = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t get_serialized_size_cosmos_interfaces__msg__Position(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Position__ros_msg_type * ros_message = static_cast<const _Position__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name mission
  {
    size_t item_size = sizeof(ros_message->mission);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_position
  {
    size_t item_size = sizeof(ros_message->current_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name next_position
  {
    size_t item_size = sizeof(ros_message->next_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_running
  {
    size_t item_size = sizeof(ros_message->is_running);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Position__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_cosmos_interfaces__msg__Position(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t max_serialized_size_cosmos_interfaces__msg__Position(
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

  // member: mission
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: current_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: next_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: is_running
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _Position__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_cosmos_interfaces__msg__Position(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Position = {
  "cosmos_interfaces::msg",
  "Position",
  _Position__cdr_serialize,
  _Position__cdr_deserialize,
  _Position__get_serialized_size,
  _Position__max_serialized_size
};

static rosidl_message_type_support_t _Position__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Position,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cosmos_interfaces, msg, Position)() {
  return &_Position__type_support;
}

#if defined(__cplusplus)
}
#endif
