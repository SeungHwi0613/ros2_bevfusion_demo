// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bev_msgs:msg/Bbox.idl
// generated code does not contain a copyright notice
#include "bev_msgs/msg/detail/bbox__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
bev_msgs__msg__Bbox__init(bev_msgs__msg__Bbox * msg)
{
  if (!msg) {
    return false;
  }
  // pos_x
  // pos_y
  // width
  // length
  // height
  // yaw
  return true;
}

void
bev_msgs__msg__Bbox__fini(bev_msgs__msg__Bbox * msg)
{
  if (!msg) {
    return;
  }
  // pos_x
  // pos_y
  // width
  // length
  // height
  // yaw
}

bool
bev_msgs__msg__Bbox__are_equal(const bev_msgs__msg__Bbox * lhs, const bev_msgs__msg__Bbox * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pos_x
  if (lhs->pos_x != rhs->pos_x) {
    return false;
  }
  // pos_y
  if (lhs->pos_y != rhs->pos_y) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // length
  if (lhs->length != rhs->length) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
bev_msgs__msg__Bbox__copy(
  const bev_msgs__msg__Bbox * input,
  bev_msgs__msg__Bbox * output)
{
  if (!input || !output) {
    return false;
  }
  // pos_x
  output->pos_x = input->pos_x;
  // pos_y
  output->pos_y = input->pos_y;
  // width
  output->width = input->width;
  // length
  output->length = input->length;
  // height
  output->height = input->height;
  // yaw
  output->yaw = input->yaw;
  return true;
}

bev_msgs__msg__Bbox *
bev_msgs__msg__Bbox__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bev_msgs__msg__Bbox * msg = (bev_msgs__msg__Bbox *)allocator.allocate(sizeof(bev_msgs__msg__Bbox), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bev_msgs__msg__Bbox));
  bool success = bev_msgs__msg__Bbox__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bev_msgs__msg__Bbox__destroy(bev_msgs__msg__Bbox * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bev_msgs__msg__Bbox__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bev_msgs__msg__Bbox__Sequence__init(bev_msgs__msg__Bbox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bev_msgs__msg__Bbox * data = NULL;

  if (size) {
    data = (bev_msgs__msg__Bbox *)allocator.zero_allocate(size, sizeof(bev_msgs__msg__Bbox), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bev_msgs__msg__Bbox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bev_msgs__msg__Bbox__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
bev_msgs__msg__Bbox__Sequence__fini(bev_msgs__msg__Bbox__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      bev_msgs__msg__Bbox__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

bev_msgs__msg__Bbox__Sequence *
bev_msgs__msg__Bbox__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bev_msgs__msg__Bbox__Sequence * array = (bev_msgs__msg__Bbox__Sequence *)allocator.allocate(sizeof(bev_msgs__msg__Bbox__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bev_msgs__msg__Bbox__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bev_msgs__msg__Bbox__Sequence__destroy(bev_msgs__msg__Bbox__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bev_msgs__msg__Bbox__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bev_msgs__msg__Bbox__Sequence__are_equal(const bev_msgs__msg__Bbox__Sequence * lhs, const bev_msgs__msg__Bbox__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bev_msgs__msg__Bbox__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bev_msgs__msg__Bbox__Sequence__copy(
  const bev_msgs__msg__Bbox__Sequence * input,
  bev_msgs__msg__Bbox__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bev_msgs__msg__Bbox);
    bev_msgs__msg__Bbox * data =
      (bev_msgs__msg__Bbox *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bev_msgs__msg__Bbox__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          bev_msgs__msg__Bbox__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bev_msgs__msg__Bbox__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
