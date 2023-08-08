// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from bev_msgs:msg/Output.idl
// generated code does not contain a copyright notice
#include "bev_msgs/msg/detail/output__rosidl_typesupport_fastrtps_cpp.hpp"
#include "bev_msgs/msg/detail/output__struct.hpp"

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
namespace bev_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const bev_msgs::msg::Bbox &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  bev_msgs::msg::Bbox &);
size_t get_serialized_size(
  const bev_msgs::msg::Bbox &,
  size_t current_alignment);
size_t
max_serialized_size_Bbox(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace bev_msgs


namespace bev_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bev_msgs
cdr_serialize(
  const bev_msgs::msg::Output & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: id
  cdr << ros_message.id;
  // Member: score
  cdr << ros_message.score;
  // Member: label
  cdr << ros_message.label;
  // Member: box
  bev_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.box,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bev_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  bev_msgs::msg::Output & ros_message)
{
  // Member: id
  cdr >> ros_message.id;

  // Member: score
  cdr >> ros_message.score;

  // Member: label
  cdr >> ros_message.label;

  // Member: box
  bev_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.box);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bev_msgs
get_serialized_size(
  const bev_msgs::msg::Output & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: score
  {
    size_t item_size = sizeof(ros_message.score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: label
  {
    size_t item_size = sizeof(ros_message.label);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: box

  current_alignment +=
    bev_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.box, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_bev_msgs
max_serialized_size_Output(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: score
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: label
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: box
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        bev_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Bbox(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _Output__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const bev_msgs::msg::Output *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Output__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<bev_msgs::msg::Output *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Output__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const bev_msgs::msg::Output *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Output__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Output(full_bounded, 0);
}

static message_type_support_callbacks_t _Output__callbacks = {
  "bev_msgs::msg",
  "Output",
  _Output__cdr_serialize,
  _Output__cdr_deserialize,
  _Output__get_serialized_size,
  _Output__max_serialized_size
};

static rosidl_message_type_support_t _Output__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Output__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace bev_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_bev_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<bev_msgs::msg::Output>()
{
  return &bev_msgs::msg::typesupport_fastrtps_cpp::_Output__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, bev_msgs, msg, Output)() {
  return &bev_msgs::msg::typesupport_fastrtps_cpp::_Output__handle;
}

#ifdef __cplusplus
}
#endif
