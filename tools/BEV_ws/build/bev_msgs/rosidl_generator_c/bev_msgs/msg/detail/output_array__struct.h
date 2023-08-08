// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bev_msgs:msg/OutputArray.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__STRUCT_H_
#define BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'outputs'
#include "bev_msgs/msg/detail/output__struct.h"

// Struct defined in msg/OutputArray in the package bev_msgs.
typedef struct bev_msgs__msg__OutputArray
{
  std_msgs__msg__Header header;
  bev_msgs__msg__Output__Sequence outputs;
} bev_msgs__msg__OutputArray;

// Struct for a sequence of bev_msgs__msg__OutputArray.
typedef struct bev_msgs__msg__OutputArray__Sequence
{
  bev_msgs__msg__OutputArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bev_msgs__msg__OutputArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__STRUCT_H_
