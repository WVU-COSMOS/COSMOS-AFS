// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from cosmos_interfaces:msg/ReactionWheels.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/reaction_wheels__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "cosmos_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cosmos_interfaces/msg/detail/reaction_wheels__struct.h"
#include "cosmos_interfaces/msg/detail/reaction_wheels__functions.h"
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


using _ReactionWheels__ros_msg_type = cosmos_interfaces__msg__ReactionWheels;

static bool _ReactionWheels__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ReactionWheels__ros_msg_type * ros_message = static_cast<const _ReactionWheels__ros_msg_type *>(untyped_ros_message);
  // Field name: is_done
  {
    cdr << (ros_message->is_done ? true : false);
  }

  // Field name: motor_x
  {
    cdr << (ros_message->motor_x ? true : false);
  }

  // Field name: motor_y
  {
    cdr << (ros_message->motor_y ? true : false);
  }

  // Field name: motor_z
  {
    cdr << (ros_message->motor_z ? true : false);
  }

  // Field name: speed_x
  {
    cdr << ros_message->speed_x;
  }

  // Field name: speed_y
  {
    cdr << ros_message->speed_y;
  }

  // Field name: speed_z
  {
    cdr << ros_message->speed_z;
  }

  // Field name: time_x
  {
    cdr << ros_message->time_x;
  }

  // Field name: time_y
  {
    cdr << ros_message->time_y;
  }

  // Field name: time_z
  {
    cdr << ros_message->time_z;
  }

  return true;
}

static bool _ReactionWheels__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ReactionWheels__ros_msg_type * ros_message = static_cast<_ReactionWheels__ros_msg_type *>(untyped_ros_message);
  // Field name: is_done
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_done = tmp ? true : false;
  }

  // Field name: motor_x
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->motor_x = tmp ? true : false;
  }

  // Field name: motor_y
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->motor_y = tmp ? true : false;
  }

  // Field name: motor_z
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->motor_z = tmp ? true : false;
  }

  // Field name: speed_x
  {
    cdr >> ros_message->speed_x;
  }

  // Field name: speed_y
  {
    cdr >> ros_message->speed_y;
  }

  // Field name: speed_z
  {
    cdr >> ros_message->speed_z;
  }

  // Field name: time_x
  {
    cdr >> ros_message->time_x;
  }

  // Field name: time_y
  {
    cdr >> ros_message->time_y;
  }

  // Field name: time_z
  {
    cdr >> ros_message->time_z;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t get_serialized_size_cosmos_interfaces__msg__ReactionWheels(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ReactionWheels__ros_msg_type * ros_message = static_cast<const _ReactionWheels__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name is_done
  {
    size_t item_size = sizeof(ros_message->is_done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_x
  {
    size_t item_size = sizeof(ros_message->motor_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_y
  {
    size_t item_size = sizeof(ros_message->motor_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_z
  {
    size_t item_size = sizeof(ros_message->motor_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed_x
  {
    size_t item_size = sizeof(ros_message->speed_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed_y
  {
    size_t item_size = sizeof(ros_message->speed_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed_z
  {
    size_t item_size = sizeof(ros_message->speed_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name time_x
  {
    size_t item_size = sizeof(ros_message->time_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name time_y
  {
    size_t item_size = sizeof(ros_message->time_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name time_z
  {
    size_t item_size = sizeof(ros_message->time_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ReactionWheels__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_cosmos_interfaces__msg__ReactionWheels(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t max_serialized_size_cosmos_interfaces__msg__ReactionWheels(
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

  // member: is_done
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: speed_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: time_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: time_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: time_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ReactionWheels__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_cosmos_interfaces__msg__ReactionWheels(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ReactionWheels = {
  "cosmos_interfaces::msg",
  "ReactionWheels",
  _ReactionWheels__cdr_serialize,
  _ReactionWheels__cdr_deserialize,
  _ReactionWheels__get_serialized_size,
  _ReactionWheels__max_serialized_size
};

static rosidl_message_type_support_t _ReactionWheels__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ReactionWheels,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cosmos_interfaces, msg, ReactionWheels)() {
  return &_ReactionWheels__type_support;
}

#if defined(__cplusplus)
}
#endif
