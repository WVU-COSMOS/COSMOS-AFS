// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from cosmos_interfaces:msg/DCM.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/dcm__rosidl_typesupport_fastrtps_cpp.hpp"
#include "cosmos_interfaces/msg/detail/dcm__struct.hpp"

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
  const cosmos_interfaces::msg::DCM & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: to_node
  cdr << ros_message.to_node;
  // Member: from_node
  cdr << ros_message.from_node;
  // Member: is_start
  cdr << (ros_message.is_start ? true : false);
  // Member: is_target
  cdr << (ros_message.is_target ? true : false);
  // Member: is_abort
  cdr << (ros_message.is_abort ? true : false);
  // Member: dcm
  {
    cdr << ros_message.dcm;
  }
  // Member: t
  cdr << ros_message.t;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cosmos_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cosmos_interfaces::msg::DCM & ros_message)
{
  // Member: to_node
  cdr >> ros_message.to_node;

  // Member: from_node
  cdr >> ros_message.from_node;

  // Member: is_start
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_start = tmp ? true : false;
  }

  // Member: is_target
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_target = tmp ? true : false;
  }

  // Member: is_abort
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_abort = tmp ? true : false;
  }

  // Member: dcm
  {
    cdr >> ros_message.dcm;
  }

  // Member: t
  cdr >> ros_message.t;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cosmos_interfaces
get_serialized_size(
  const cosmos_interfaces::msg::DCM & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: to_node
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.to_node.size() + 1);
  // Member: from_node
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.from_node.size() + 1);
  // Member: is_start
  {
    size_t item_size = sizeof(ros_message.is_start);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_target
  {
    size_t item_size = sizeof(ros_message.is_target);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_abort
  {
    size_t item_size = sizeof(ros_message.is_abort);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dcm
  {
    size_t array_size = 9;
    size_t item_size = sizeof(ros_message.dcm[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: t
  {
    size_t item_size = sizeof(ros_message.t);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cosmos_interfaces
max_serialized_size_DCM(
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

  // Member: is_start
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_target
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_abort
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: dcm
  {
    size_t array_size = 9;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: t
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _DCM__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const cosmos_interfaces::msg::DCM *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DCM__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<cosmos_interfaces::msg::DCM *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DCM__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const cosmos_interfaces::msg::DCM *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DCM__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DCM(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DCM__callbacks = {
  "cosmos_interfaces::msg",
  "DCM",
  _DCM__cdr_serialize,
  _DCM__cdr_deserialize,
  _DCM__get_serialized_size,
  _DCM__max_serialized_size
};

static rosidl_message_type_support_t _DCM__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DCM__callbacks,
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
get_message_type_support_handle<cosmos_interfaces::msg::DCM>()
{
  return &cosmos_interfaces::msg::typesupport_fastrtps_cpp::_DCM__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cosmos_interfaces, msg, DCM)() {
  return &cosmos_interfaces::msg::typesupport_fastrtps_cpp::_DCM__handle;
}

#ifdef __cplusplus
}
#endif
