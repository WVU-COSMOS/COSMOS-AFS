// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cosmos_interfaces:msg/Attitude.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/attitude__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cosmos_interfaces__msg__Attitude__init(cosmos_interfaces__msg__Attitude * msg)
{
  if (!msg) {
    return false;
  }
  // time_stamp
  // q1
  // q2
  // q3
  // q4
  return true;
}

void
cosmos_interfaces__msg__Attitude__fini(cosmos_interfaces__msg__Attitude * msg)
{
  if (!msg) {
    return;
  }
  // time_stamp
  // q1
  // q2
  // q3
  // q4
}

bool
cosmos_interfaces__msg__Attitude__are_equal(const cosmos_interfaces__msg__Attitude * lhs, const cosmos_interfaces__msg__Attitude * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // time_stamp
  if (lhs->time_stamp != rhs->time_stamp) {
    return false;
  }
  // q1
  if (lhs->q1 != rhs->q1) {
    return false;
  }
  // q2
  if (lhs->q2 != rhs->q2) {
    return false;
  }
  // q3
  if (lhs->q3 != rhs->q3) {
    return false;
  }
  // q4
  if (lhs->q4 != rhs->q4) {
    return false;
  }
  return true;
}

bool
cosmos_interfaces__msg__Attitude__copy(
  const cosmos_interfaces__msg__Attitude * input,
  cosmos_interfaces__msg__Attitude * output)
{
  if (!input || !output) {
    return false;
  }
  // time_stamp
  output->time_stamp = input->time_stamp;
  // q1
  output->q1 = input->q1;
  // q2
  output->q2 = input->q2;
  // q3
  output->q3 = input->q3;
  // q4
  output->q4 = input->q4;
  return true;
}

cosmos_interfaces__msg__Attitude *
cosmos_interfaces__msg__Attitude__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__Attitude * msg = (cosmos_interfaces__msg__Attitude *)allocator.allocate(sizeof(cosmos_interfaces__msg__Attitude), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cosmos_interfaces__msg__Attitude));
  bool success = cosmos_interfaces__msg__Attitude__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cosmos_interfaces__msg__Attitude__destroy(cosmos_interfaces__msg__Attitude * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cosmos_interfaces__msg__Attitude__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cosmos_interfaces__msg__Attitude__Sequence__init(cosmos_interfaces__msg__Attitude__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__Attitude * data = NULL;

  if (size) {
    data = (cosmos_interfaces__msg__Attitude *)allocator.zero_allocate(size, sizeof(cosmos_interfaces__msg__Attitude), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cosmos_interfaces__msg__Attitude__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cosmos_interfaces__msg__Attitude__fini(&data[i - 1]);
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
cosmos_interfaces__msg__Attitude__Sequence__fini(cosmos_interfaces__msg__Attitude__Sequence * array)
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
      cosmos_interfaces__msg__Attitude__fini(&array->data[i]);
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

cosmos_interfaces__msg__Attitude__Sequence *
cosmos_interfaces__msg__Attitude__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__Attitude__Sequence * array = (cosmos_interfaces__msg__Attitude__Sequence *)allocator.allocate(sizeof(cosmos_interfaces__msg__Attitude__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cosmos_interfaces__msg__Attitude__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cosmos_interfaces__msg__Attitude__Sequence__destroy(cosmos_interfaces__msg__Attitude__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cosmos_interfaces__msg__Attitude__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cosmos_interfaces__msg__Attitude__Sequence__are_equal(const cosmos_interfaces__msg__Attitude__Sequence * lhs, const cosmos_interfaces__msg__Attitude__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cosmos_interfaces__msg__Attitude__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cosmos_interfaces__msg__Attitude__Sequence__copy(
  const cosmos_interfaces__msg__Attitude__Sequence * input,
  cosmos_interfaces__msg__Attitude__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cosmos_interfaces__msg__Attitude);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cosmos_interfaces__msg__Attitude * data =
      (cosmos_interfaces__msg__Attitude *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cosmos_interfaces__msg__Attitude__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cosmos_interfaces__msg__Attitude__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cosmos_interfaces__msg__Attitude__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
