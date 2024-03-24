// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from cosmos_interfaces:msg/Camera.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/camera__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "cosmos_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cosmos_interfaces/msg/detail/camera__struct.h"
#include "cosmos_interfaces/msg/detail/camera__functions.h"
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

#include "rosidl_runtime_c/string.h"  // from_node, to_node
#include "rosidl_runtime_c/string_functions.h"  // from_node, to_node

// forward declare type support functions


using _Camera__ros_msg_type = cosmos_interfaces__msg__Camera;

static bool _Camera__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Camera__ros_msg_type * ros_message = static_cast<const _Camera__ros_msg_type *>(untyped_ros_message);
  // Field name: from_node
  {
    const rosidl_runtime_c__String * str = &ros_message->from_node;
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

  // Field name: is_done
  {
    cdr << (ros_message->is_done ? true : false);
  }

  // Field name: is_abort
  {
    cdr << (ros_message->is_abort ? true : false);
  }

  // Field name: is_target
  {
    cdr << (ros_message->is_target ? true : false);
  }

  // Field name: img_num
  {
    cdr << ros_message->img_num;
  }

  // Field name: next_img
  {
    cdr << (ros_message->next_img ? true : false);
  }

  // Field name: u
  {
    cdr << ros_message->u;
  }

  // Field name: v
  {
    cdr << ros_message->v;
  }

  return true;
}

static bool _Camera__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Camera__ros_msg_type * ros_message = static_cast<_Camera__ros_msg_type *>(untyped_ros_message);
  // Field name: from_node
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->from_node.data) {
      rosidl_runtime_c__String__init(&ros_message->from_node);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->from_node,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'from_node'\n");
      return false;
    }
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

  // Field name: is_done
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_done = tmp ? true : false;
  }

  // Field name: is_abort
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_abort = tmp ? true : false;
  }

  // Field name: is_target
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_target = tmp ? true : false;
  }

  // Field name: img_num
  {
    cdr >> ros_message->img_num;
  }

  // Field name: next_img
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->next_img = tmp ? true : false;
  }

  // Field name: u
  {
    cdr >> ros_message->u;
  }

  // Field name: v
  {
    cdr >> ros_message->v;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t get_serialized_size_cosmos_interfaces__msg__Camera(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Camera__ros_msg_type * ros_message = static_cast<const _Camera__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name from_node
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->from_node.size + 1);
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
  // field.name is_done
  {
    size_t item_size = sizeof(ros_message->is_done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_abort
  {
    size_t item_size = sizeof(ros_message->is_abort);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_target
  {
    size_t item_size = sizeof(ros_message->is_target);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name img_num
  {
    size_t item_size = sizeof(ros_message->img_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name next_img
  {
    size_t item_size = sizeof(ros_message->next_img);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name u
  {
    size_t item_size = sizeof(ros_message->u);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v
  {
    size_t item_size = sizeof(ros_message->v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Camera__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_cosmos_interfaces__msg__Camera(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cosmos_interfaces
size_t max_serialized_size_cosmos_interfaces__msg__Camera(
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

  // member: from_node
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
  // member: is_done
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_abort
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_target
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: img_num
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: next_img
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: u
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: v
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Camera__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_cosmos_interfaces__msg__Camera(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Camera = {
  "cosmos_interfaces::msg",
  "Camera",
  _Camera__cdr_serialize,
  _Camera__cdr_deserialize,
  _Camera__get_serialized_size,
  _Camera__max_serialized_size
};

static rosidl_message_type_support_t _Camera__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Camera,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cosmos_interfaces, msg, Camera)() {
  return &_Camera__type_support;
}

#if defined(__cplusplus)
}
#endif
