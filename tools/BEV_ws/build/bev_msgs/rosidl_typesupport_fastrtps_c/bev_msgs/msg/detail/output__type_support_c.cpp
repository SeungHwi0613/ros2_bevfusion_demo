// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from bev_msgs:msg/Output.idl
// generated code does not contain a copyright notice
#include "bev_msgs/msg/detail/output__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "bev_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "bev_msgs/msg/detail/output__struct.h"
#include "bev_msgs/msg/detail/output__functions.h"
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

#include "bev_msgs/msg/detail/bbox__functions.h"  // box

// forward declare type support functions
size_t get_serialized_size_bev_msgs__msg__Bbox(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_bev_msgs__msg__Bbox(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bev_msgs, msg, Bbox)();


using _Output__ros_msg_type = bev_msgs__msg__Output;

static bool _Output__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Output__ros_msg_type * ros_message = static_cast<const _Output__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: score
  {
    cdr << ros_message->score;
  }

  // Field name: label
  {
    cdr << ros_message->label;
  }

  // Field name: box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, bev_msgs, msg, Bbox
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->box, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Output__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Output__ros_msg_type * ros_message = static_cast<_Output__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr >> ros_message->id;
  }

  // Field name: score
  {
    cdr >> ros_message->score;
  }

  // Field name: label
  {
    cdr >> ros_message->label;
  }

  // Field name: box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, bev_msgs, msg, Bbox
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->box))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bev_msgs
size_t get_serialized_size_bev_msgs__msg__Output(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Output__ros_msg_type * ros_message = static_cast<const _Output__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name id
  {
    size_t item_size = sizeof(ros_message->id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name score
  {
    size_t item_size = sizeof(ros_message->score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name label
  {
    size_t item_size = sizeof(ros_message->label);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name box

  current_alignment += get_serialized_size_bev_msgs__msg__Bbox(
    &(ros_message->box), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Output__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_bev_msgs__msg__Output(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_bev_msgs
size_t max_serialized_size_bev_msgs__msg__Output(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: score
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: label
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: box
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_bev_msgs__msg__Bbox(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Output__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_bev_msgs__msg__Output(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Output = {
  "bev_msgs::msg",
  "Output",
  _Output__cdr_serialize,
  _Output__cdr_deserialize,
  _Output__get_serialized_size,
  _Output__max_serialized_size
};

static rosidl_message_type_support_t _Output__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Output,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, bev_msgs, msg, Output)() {
  return &_Output__type_support;
}

#if defined(__cplusplus)
}
#endif
