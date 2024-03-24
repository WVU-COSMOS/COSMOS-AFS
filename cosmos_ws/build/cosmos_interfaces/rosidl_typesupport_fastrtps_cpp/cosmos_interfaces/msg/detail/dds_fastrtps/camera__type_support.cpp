// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from cosmos_interfaces:msg/Camera.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/camera__rosidl_typesupport_fastrtps_cpp.hpp"
#include "cosmos_interfaces/msg/detail/camera__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace cosmos_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cosmos_interfaces
cdr_serialize(
  const cosmos_interfaces::msg::Camera & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: from_node
  cdr << ros_message.from_node;
  // Member: to_node
  cdr << ros_message.to_node;
  // Member: is_start
  cdr << (ros_message.is_start ? true : false);
  // Member: is_done
  cdr << (ros_message.is_done ? true : false);
  // Member: is_abort
  cdr << (ros_message.is_abort ? true : false);
  // Member: is_target
  cdr << (ros_message.is_target ? true : false);
  // Member: img_num
  cdr << ros_message.img_num;
  // Member: next_img
  cdr << (ros_message.next_img ? true : false);
  // Member: u
  cdr << ros_message.u;
  // Member: v
  cdr << ros_message.v;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cosmos_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cosmos_interfaces::msg::Camera & ros_message)
{
  // Member: from_node
  cdr >> ros_message.from_node;

  // Member: to_node
  cdr >> ros_message.to_node;

  // Member: is_start
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_start = tmp ? true : false;
  }

  // Member: is_done
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_done = tmp ? true : false;
  }

  // Member: is_abort
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_abort = tmp ? true : false;
  }

  // Member: is_target
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_target = tmp ? true : false;
  }

  // Member: img_num
  cdr >> ros_message.img_num;

  // Member: next_img
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.next_img = tmp ? true : false;
  }

  // Member: u
  cdr >> ros_message.u;

  // Member: v
  cdr >> ros_message.v;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cosmos_interfaces
get_serialized_size(
  const cosmos_interfaces::msg::Camera & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: from_node
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.from_node.size() + 1);
  // Member: to_node
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.to_node.size() + 1);
  // Member: is_start
  {
    size_t item_size = sizeof(ros_message.is_start);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_done
  {
    size_t item_size = sizeof(ros_message.is_done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_abort
  {
    size_t item_size = sizeof(ros_message.is_abort);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_target
  {
    size_t item_size = sizeof(ros_message.is_target);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: img_num
  {
    size_t item_size = sizeof(ros_message.img_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: next_img
  {
    size_t item_size = sizeof(ros_message.next_img);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: u
  {
    size_t item_size = sizeof(ros_message.u);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v
  {
    size_t item_size = sizeof(ros_message.v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cosmos_interfaces
max_serialized_size_Camera(
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


  // Member: from_node
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

  // Member: to_node
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

  // Member: is_start
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_done
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_abort
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_target
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: img_num
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: next_img
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: u
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: v
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Camera__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const cosmos_interfaces::msg::Camera *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Camera__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<cosmos_interfaces::msg::Camera *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Camera__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const cosmos_interfaces::msg::Camera *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Camera__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Camera(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Camera__callbacks = {
  "cosmos_interfaces::msg",
  "Camera",
  _Camera__cdr_serialize,
  _Camera__cdr_deserialize,
  _Camera__get_serialized_size,
  _Camera__max_serialized_size
};

static rosidl_message_type_support_t _Camera__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Camera__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace cosmos_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_cosmos_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<cosmos_interfaces::msg::Camera>()
{
  return &cosmos_interfaces::msg::typesupport_fastrtps_cpp::_Camera__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cosmos_interfaces, msg, Camera)() {
  return &cosmos_interfaces::msg::typesupport_fastrtps_cpp::_Camera__handle;
}

#ifdef __cplusplus
}
#endif
