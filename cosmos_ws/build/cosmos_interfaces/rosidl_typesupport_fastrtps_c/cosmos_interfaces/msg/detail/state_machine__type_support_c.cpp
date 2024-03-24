// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from cosmos_interfaces:msg/StateMachine.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/state_machine__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "cosmos_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cosmos_interfaces/msg/detail/state_machine__struct.h"
#include "cosmos_interfaces/msg/detail/state_machine__functions.h"
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

#include "rosidl_runtime_c/string.h"  // to_node
#include "rosidl_runtime_c/string_functions.h"  // to_node

// forward declare type support functions


using _StateMachine__ros_msg_type = cosmos_interfaces__msg__StateMachine;

static bool _StateMachine__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StateMachine__ros_msg_type * ros_message = static_cast<const _StateMachine__ros_msg_type *>(untyped_ros_message);
  // Field name: mission
  {
    cdr << ros_message->mission;
  }

  // Field name: to_node
  {
    const rosidl_runtime_c__String * str = &ros_message->to_node;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: is_start
  {
    cdr << (ros_message->is_start ? true : false);
  }

  // Field name: is_abort
  {
    cdr << (ros_message->is_abort ? true : false);
  }

  return true;
}

static bool _StateMachine__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StateMachine__ros_msg_type * ros_message = static_cast<_StateMachine__ros_msg_type *>(untyped_ros_message);
  // Field name: mission
  {
    cdr >> ros_message->mission;
  }

  // Field name: to_node
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->to_node.data) {
      rosidl_runtime_c__String__init(&ros_message->to_node);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->to_node,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'to_node'\n");
      return false;
    }
  }

  // Field name: is_start
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_start = tmp ? true : false;
  }

  // Field name: is_abort
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_abort = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t get_serialized_size_cosmos_interfaces__msg__StateMachine(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StateMachine__ros_msg_type * ros_message = static_cast<const _StateMachine__ros_msg_type *>(untyped_ros_message);
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
  // field.name to_node
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->to_node.size + 1);
  // field.name is_start
  {
    size_t item_size = sizeof(ros_message->is_start);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_abort
  {
    size_t item_size = sizeof(ros_message->is_abort);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StateMachine__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_cosmos_interfaces__msg__StateMachine(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t max_serialized_size_cosmos_interfaces__msg__StateMachine(
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

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: to_node
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: is_start
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_abort
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _StateMachine__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_cosmos_interfaces__msg__StateMachine(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StateMachine = {
  "cosmos_interfaces::msg",
  "StateMachine",
  _StateMachine__cdr_serialize,
  _StateMachine__cdr_deserialize,
  _StateMachine__get_serialized_size,
  _StateMachine__max_serialized_size
};

static rosidl_message_type_support_t _StateMachine__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StateMachine,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cosmos_interfaces, msg, StateMachine)() {
  return &_StateMachine__type_support;
}

#if defined(__cplusplus)
}
#endif
