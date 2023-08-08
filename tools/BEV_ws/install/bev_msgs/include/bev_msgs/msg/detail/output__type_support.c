// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from bev_msgs:msg/Output.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "bev_msgs/msg/detail/output__rosidl_typesupport_introspection_c.h"
#include "bev_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "bev_msgs/msg/detail/output__functions.h"
#include "bev_msgs/msg/detail/output__struct.h"


// Include directives for member types
// Member `box`
#include "bev_msgs/msg/bbox.h"
// Member `box`
#include "bev_msgs/msg/detail/bbox__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Output__rosidl_typesupport_introspection_c__Output_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  bev_msgs__msg__Output__init(message_memory);
}

void Output__rosidl_typesupport_introspection_c__Output_fini_function(void * message_memory)
{
  bev_msgs__msg__Output__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Output__rosidl_typesupport_introspection_c__Output_message_member_array[4] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Output, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "score",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Output, score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Output, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "box",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Output, box),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Output__rosidl_typesupport_introspection_c__Output_message_members = {
  "bev_msgs__msg",  // message namespace
  "Output",  // message name
  4,  // number of fields
  sizeof(bev_msgs__msg__Output),
  Output__rosidl_typesupport_introspection_c__Output_message_member_array,  // message members
  Output__rosidl_typesupport_introspection_c__Output_init_function,  // function to initialize message memory (memory has to be allocated)
  Output__rosidl_typesupport_introspection_c__Output_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Output__rosidl_typesupport_introspection_c__Output_message_type_support_handle = {
  0,
  &Output__rosidl_typesupport_introspection_c__Output_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_bev_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bev_msgs, msg, Output)() {
  Output__rosidl_typesupport_introspection_c__Output_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bev_msgs, msg, Bbox)();
  if (!Output__rosidl_typesupport_introspection_c__Output_message_type_support_handle.typesupport_identifier) {
    Output__rosidl_typesupport_introspection_c__Output_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Output__rosidl_typesupport_introspection_c__Output_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
