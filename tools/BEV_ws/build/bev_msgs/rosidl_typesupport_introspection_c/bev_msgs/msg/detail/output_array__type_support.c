// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from bev_msgs:msg/OutputArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "bev_msgs/msg/detail/output_array__rosidl_typesupport_introspection_c.h"
#include "bev_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "bev_msgs/msg/detail/output_array__functions.h"
#include "bev_msgs/msg/detail/output_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `outputs`
#include "bev_msgs/msg/output.h"
// Member `outputs`
#include "bev_msgs/msg/detail/output__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void OutputArray__rosidl_typesupport_introspection_c__OutputArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  bev_msgs__msg__OutputArray__init(message_memory);
}

void OutputArray__rosidl_typesupport_introspection_c__OutputArray_fini_function(void * message_memory)
{
  bev_msgs__msg__OutputArray__fini(message_memory);
}

size_t OutputArray__rosidl_typesupport_introspection_c__size_function__Output__outputs(
  const void * untyped_member)
{
  const bev_msgs__msg__Output__Sequence * member =
    (const bev_msgs__msg__Output__Sequence *)(untyped_member);
  return member->size;
}

const void * OutputArray__rosidl_typesupport_introspection_c__get_const_function__Output__outputs(
  const void * untyped_member, size_t index)
{
  const bev_msgs__msg__Output__Sequence * member =
    (const bev_msgs__msg__Output__Sequence *)(untyped_member);
  return &member->data[index];
}

void * OutputArray__rosidl_typesupport_introspection_c__get_function__Output__outputs(
  void * untyped_member, size_t index)
{
  bev_msgs__msg__Output__Sequence * member =
    (bev_msgs__msg__Output__Sequence *)(untyped_member);
  return &member->data[index];
}

bool OutputArray__rosidl_typesupport_introspection_c__resize_function__Output__outputs(
  void * untyped_member, size_t size)
{
  bev_msgs__msg__Output__Sequence * member =
    (bev_msgs__msg__Output__Sequence *)(untyped_member);
  bev_msgs__msg__Output__Sequence__fini(member);
  return bev_msgs__msg__Output__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__OutputArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "outputs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__OutputArray, outputs),  // bytes offset in struct
    NULL,  // default value
    OutputArray__rosidl_typesupport_introspection_c__size_function__Output__outputs,  // size() function pointer
    OutputArray__rosidl_typesupport_introspection_c__get_const_function__Output__outputs,  // get_const(index) function pointer
    OutputArray__rosidl_typesupport_introspection_c__get_function__Output__outputs,  // get(index) function pointer
    OutputArray__rosidl_typesupport_introspection_c__resize_function__Output__outputs  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_members = {
  "bev_msgs__msg",  // message namespace
  "OutputArray",  // message name
  2,  // number of fields
  sizeof(bev_msgs__msg__OutputArray),
  OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_member_array,  // message members
  OutputArray__rosidl_typesupport_introspection_c__OutputArray_init_function,  // function to initialize message memory (memory has to be allocated)
  OutputArray__rosidl_typesupport_introspection_c__OutputArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_type_support_handle = {
  0,
  &OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_bev_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bev_msgs, msg, OutputArray)() {
  OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bev_msgs, msg, Output)();
  if (!OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_type_support_handle.typesupport_identifier) {
    OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &OutputArray__rosidl_typesupport_introspection_c__OutputArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
