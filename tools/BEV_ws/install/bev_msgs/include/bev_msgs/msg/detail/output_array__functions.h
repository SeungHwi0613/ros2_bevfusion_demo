// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from bev_msgs:msg/OutputArray.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__FUNCTIONS_H_
#define BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "bev_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "bev_msgs/msg/detail/output_array__struct.h"

/// Initialize msg/OutputArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * bev_msgs__msg__OutputArray
 * )) before or use
 * bev_msgs__msg__OutputArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__OutputArray__init(bev_msgs__msg__OutputArray * msg);

/// Finalize msg/OutputArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
void
bev_msgs__msg__OutputArray__fini(bev_msgs__msg__OutputArray * msg);

/// Create msg/OutputArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * bev_msgs__msg__OutputArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bev_msgs__msg__OutputArray *
bev_msgs__msg__OutputArray__create();

/// Destroy msg/OutputArray message.
/**
 * It calls
 * bev_msgs__msg__OutputArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
void
bev_msgs__msg__OutputArray__destroy(bev_msgs__msg__OutputArray * msg);

/// Check for msg/OutputArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__OutputArray__are_equal(const bev_msgs__msg__OutputArray * lhs, const bev_msgs__msg__OutputArray * rhs);

/// Copy a msg/OutputArray message.
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
bev_msgs__msg__OutputArray__copy(
  const bev_msgs__msg__OutputArray * input,
  bev_msgs__msg__OutputArray * output);

/// Initialize array of msg/OutputArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * bev_msgs__msg__OutputArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__OutputArray__Sequence__init(bev_msgs__msg__OutputArray__Sequence * array, size_t size);

/// Finalize array of msg/OutputArray messages.
/**
 * It calls
 * bev_msgs__msg__OutputArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
void
bev_msgs__msg__OutputArray__Sequence__fini(bev_msgs__msg__OutputArray__Sequence * array);

/// Create array of msg/OutputArray messages.
/**
 * It allocates the memory for the array and calls
 * bev_msgs__msg__OutputArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bev_msgs__msg__OutputArray__Sequence *
bev_msgs__msg__OutputArray__Sequence__create(size_t size);

/// Destroy array of msg/OutputArray messages.
/**
 * It calls
 * bev_msgs__msg__OutputArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
void
bev_msgs__msg__OutputArray__Sequence__destroy(bev_msgs__msg__OutputArray__Sequence * array);

/// Check for msg/OutputArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bev_msgs
bool
bev_msgs__msg__OutputArray__Sequence__are_equal(const bev_msgs__msg__OutputArray__Sequence * lhs, const bev_msgs__msg__OutputArray__Sequence * rhs);

/// Copy an array of msg/OutputArray messages.
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
bev_msgs__msg__OutputArray__Sequence__copy(
  const bev_msgs__msg__OutputArray__Sequence * input,
  bev_msgs__msg__OutputArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__FUNCTIONS_H_
