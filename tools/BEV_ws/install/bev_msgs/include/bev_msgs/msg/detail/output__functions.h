// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from bev_msgs:msg/Output.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__OUTPUT__FUNCTIONS_H_
#define BEV_MSGS__MSG__DETAIL__OUTPUT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "bev_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "bev_msgs/msg/detail/output__struct.h"

/// Initialize msg/Output message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * bev_msgs__msg__Output
 * )) before or use
 * bev_msgs__msg__Output__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__Output__init(bev_msgs__msg__Output * msg);

/// Finalize msg/Output message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
void
bev_msgs__msg__Output__fini(bev_msgs__msg__Output * msg);

/// Create msg/Output message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * bev_msgs__msg__Output__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bev_msgs__msg__Output *
bev_msgs__msg__Output__create();

/// Destroy msg/Output message.
/**
 * It calls
 * bev_msgs__msg__Output__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
void
bev_msgs__msg__Output__destroy(bev_msgs__msg__Output * msg);

/// Check for msg/Output message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__Output__are_equal(const bev_msgs__msg__Output * lhs, const bev_msgs__msg__Output * rhs);

/// Copy a msg/Output message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__Output__copy(
  const bev_msgs__msg__Output * input,
  bev_msgs__msg__Output * output);

/// Initialize array of msg/Output messages.
/**
 * It allocates the memory for the number of elements and calls
 * bev_msgs__msg__Output__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__Output__Sequence__init(bev_msgs__msg__Output__Sequence * array, size_t size);

/// Finalize array of msg/Output messages.
/**
 * It calls
 * bev_msgs__msg__Output__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
void
bev_msgs__msg__Output__Sequence__fini(bev_msgs__msg__Output__Sequence * array);

/// Create array of msg/Output messages.
/**
 * It allocates the memory for the array and calls
 * bev_msgs__msg__Output__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bev_msgs__msg__Output__Sequence *
bev_msgs__msg__Output__Sequence__create(size_t size);

/// Destroy array of msg/Output messages.
/**
 * It calls
 * bev_msgs__msg__Output__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
void
bev_msgs__msg__Output__Sequence__destroy(bev_msgs__msg__Output__Sequence * array);

/// Check for msg/Output message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__Output__Sequence__are_equal(const bev_msgs__msg__Output__Sequence * lhs, const bev_msgs__msg__Output__Sequence * rhs);

/// Copy an array of msg/Output messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__Output__Sequence__copy(
  const bev_msgs__msg__Output__Sequence * input,
  bev_msgs__msg__Output__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BEV_MSGS__MSG__DETAIL__OUTPUT__FUNCTIONS_H_
