// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cosmos_interfaces:msg/Position.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cosmos_interfaces__msg__Position__init(cosmos_interfaces__msg__Position * msg)
{
  if (!msg) {
    return false;
  }
  // mission
  // current_position
  // next_position
  // is_running
  return true;
}

void
cosmos_interfaces__msg__Position__fini(cosmos_interfaces__msg__Position * msg)
{
  if (!msg) {
    return;
  }
  // mission
  // current_position
  // next_position
  // is_running
}

bool
cosmos_interfaces__msg__Position__are_equal(const cosmos_interfaces__msg__Position * lhs, const cosmos_interfaces__msg__Position * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mission
  if (lhs->mission != rhs->mission) {
    return false;
  }
  // current_position
  if (lhs->current_position != rhs->current_position) {
    return false;
  }
  // next_position
  if (lhs->next_position != rhs->next_position) {
    return false;
  }
  // is_running
  if (lhs->is_running != rhs->is_running) {
    return false;
  }
  return true;
}

bool
cosmos_interfaces__msg__Position__copy(
  const cosmos_interfaces__msg__Position * input,
  cosmos_interfaces__msg__Position * output)
{
  if (!input || !output) {
    return false;
  }
  // mission
  output->mission = input->mission;
  // current_position
  output->current_position = input->current_position;
  // next_position
  output->next_position = input->next_position;
  // is_running
  output->is_running = input->is_running;
  return true;
}

cosmos_interfaces__msg__Position *
cosmos_interfaces__msg__Position__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__Position * msg = (cosmos_interfaces__msg__Position *)allocator.allocate(sizeof(cosmos_interfaces__msg__Position), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cosmos_interfaces__msg__Position));
  bool success = cosmos_interfaces__msg__Position__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cosmos_interfaces__msg__Position__destroy(cosmos_interfaces__msg__Position * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cosmos_interfaces__msg__Position__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cosmos_interfaces__msg__Position__Sequence__init(cosmos_interfaces__msg__Position__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__Position * data = NULL;

  if (size) {
    data = (cosmos_interfaces__msg__Position *)allocator.zero_allocate(size, sizeof(cosmos_interfaces__msg__Position), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cosmos_interfaces__msg__Position__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cosmos_interfaces__msg__Position__fini(&data[i - 1]);
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
cosmos_interfaces__msg__Position__Sequence__fini(cosmos_interfaces__msg__Position__Sequence * array)
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
      cosmos_interfaces__msg__Position__fini(&array->data[i]);
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

cosmos_interfaces__msg__Position__Sequence *
cosmos_interfaces__msg__Position__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__Position__Sequence * array = (cosmos_interfaces__msg__Position__Sequence *)allocator.allocate(sizeof(cosmos_interfaces__msg__Position__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cosmos_interfaces__msg__Position__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cosmos_interfaces__msg__Position__Sequence__destroy(cosmos_interfaces__msg__Position__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cosmos_interfaces__msg__Position__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cosmos_interfaces__msg__Position__Sequence__are_equal(const cosmos_interfaces__msg__Position__Sequence * lhs, const cosmos_interfaces__msg__Position__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cosmos_interfaces__msg__Position__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cosmos_interfaces__msg__Position__Sequence__copy(
  const cosmos_interfaces__msg__Position__Sequence * input,
  cosmos_interfaces__msg__Position__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cosmos_interfaces__msg__Position);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cosmos_interfaces__msg__Position * data =
      (cosmos_interfaces__msg__Position *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cosmos_interfaces__msg__Position__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cosmos_interfaces__msg__Position__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cosmos_interfaces__msg__Position__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
