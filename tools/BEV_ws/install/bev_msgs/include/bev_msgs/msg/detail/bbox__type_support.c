// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from bev_msgs:msg/Bbox.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "bev_msgs/msg/detail/bbox__rosidl_typesupport_introspection_c.h"
#include "bev_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "bev_msgs/msg/detail/bbox__functions.h"
#include "bev_msgs/msg/detail/bbox__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Bbox__rosidl_typesupport_introspection_c__Bbox_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  bev_msgs__msg__Bbox__init(message_memory);
}

void Bbox__rosidl_typesupport_introspection_c__Bbox_fini_function(void * message_memory)
{
  bev_msgs__msg__Bbox__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Bbox__rosidl_typesupport_introspection_c__Bbox_message_member_array[6] = {
  {
    "pos_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Bbox, pos_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Bbox, pos_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Bbox, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Bbox, length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Bbox, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs__msg__Bbox, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Bbox__rosidl_typesupport_introspection_c__Bbox_message_members = {
  "bev_msgs__msg",  // message namespace
  "Bbox",  // message name
  6,  // number of fields
  sizeof(bev_msgs__msg__Bbox),
  Bbox__rosidl_typesupport_introspection_c__Bbox_message_member_array,  // message members
  Bbox__rosidl_typesupport_introspection_c__Bbox_init_function,  // function to initialize message memory (memory has to be allocated)
  Bbox__rosidl_typesupport_introspection_c__Bbox_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Bbox__rosidl_typesupport_introspection_c__Bbox_message_type_support_handle = {
  0,
  &Bbox__rosidl_typesupport_introspection_c__Bbox_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_bev_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bev_msgs, msg, Bbox)() {
  if (!Bbox__rosidl_typesupport_introspection_c__Bbox_message_type_support_handle.typesupport_identifier) {
    Bbox__rosidl_typesupport_introspection_c__Bbox_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Bbox__rosidl_typesupport_introspection_c__Bbox_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
