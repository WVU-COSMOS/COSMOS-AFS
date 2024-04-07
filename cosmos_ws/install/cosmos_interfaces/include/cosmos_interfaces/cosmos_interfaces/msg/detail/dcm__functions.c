// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cosmos_interfaces:msg/DCM.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/dcm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `to_node`
// Member `from_node`
#include "rosidl_runtime_c/string_functions.h"

bool
cosmos_interfaces__msg__DCM__init(cosmos_interfaces__msg__DCM * msg)
{
  if (!msg) {
    return false;
  }
  // to_node
  if (!rosidl_runtime_c__String__init(&msg->to_node)) {
    cosmos_interfaces__msg__DCM__fini(msg);
    return false;
  }
  // from_node
  if (!rosidl_runtime_c__String__init(&msg->from_node)) {
    cosmos_interfaces__msg__DCM__fini(msg);
    return false;
  }
  // is_start
  // is_target
  // is_abort
  // dcm
  // t
  return true;
}

void
cosmos_interfaces__msg__DCM__fini(cosmos_interfaces__msg__DCM * msg)
{
  if (!msg) {
    return;
  }
  // to_node
  rosidl_runtime_c__String__fini(&msg->to_node);
  // from_node
  rosidl_runtime_c__String__fini(&msg->from_node);
  // is_start
  // is_target
  // is_abort
  // dcm
  // t
}

bool
cosmos_interfaces__msg__DCM__are_equal(const cosmos_interfaces__msg__DCM * lhs, const cosmos_interfaces__msg__DCM * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // to_node
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->to_node), &(rhs->to_node)))
  {
    return false;
  }
  // from_node
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->from_node), &(rhs->from_node)))
  {
    return false;
  }
  // is_start
  if (lhs->is_start != rhs->is_start) {
    return false;
  }
  // is_target
  if (lhs->is_target != rhs->is_target) {
    return false;
  }
  // is_abort
  if (lhs->is_abort != rhs->is_abort) {
    return false;
  }
  // dcm
  for (size_t i = 0; i < 9; ++i) {
    if (lhs->dcm[i] != rhs->dcm[i]) {
      return false;
    }
  }
  // t
  if (lhs->t != rhs->t) {
    return false;
  }
  return true;
}

bool
cosmos_interfaces__msg__DCM__copy(
  const cosmos_interfaces__msg__DCM * input,
  cosmos_interfaces__msg__DCM * output)
{
  if (!input || !output) {
    return false;
  }
  // to_node
  if (!rosidl_runtime_c__String__copy(
      &(input->to_node), &(output->to_node)))
  {
    return false;
  }
  // from_node
  if (!rosidl_runtime_c__String__copy(
      &(input->from_node), &(output->from_node)))
  {
    return false;
  }
  // is_start
  output->is_start = input->is_start;
  // is_target
  output->is_target = input->is_target;
  // is_abort
  output->is_abort = input->is_abort;
  // dcm
  for (size_t i = 0; i < 9; ++i) {
    output->dcm[i] = input->dcm[i];
  }
  // t
  output->t = input->t;
  return true;
}

cosmos_interfaces__msg__DCM *
cosmos_interfaces__msg__DCM__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__DCM * msg = (cosmos_interfaces__msg__DCM *)allocator.allocate(sizeof(cosmos_interfaces__msg__DCM), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cosmos_interfaces__msg__DCM));
  bool success = cosmos_interfaces__msg__DCM__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cosmos_interfaces__msg__DCM__destroy(cosmos_interfaces__msg__DCM * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cosmos_interfaces__msg__DCM__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cosmos_interfaces__msg__DCM__Sequence__init(cosmos_interfaces__msg__DCM__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__DCM * data = NULL;

  if (size) {
    data = (cosmos_interfaces__msg__DCM *)allocator.zero_allocate(size, sizeof(cosmos_interfaces__msg__DCM), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cosmos_interfaces__msg__DCM__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cosmos_interfaces__msg__DCM__fini(&data[i - 1]);
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
cosmos_interfaces__msg__DCM__Sequence__fini(cosmos_interfaces__msg__DCM__Sequence * array)
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
      cosmos_interfaces__msg__DCM__fini(&array->data[i]);
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

cosmos_interfaces__msg__DCM__Sequence *
cosmos_interfaces__msg__DCM__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__DCM__Sequence * array = (cosmos_interfaces__msg__DCM__Sequence *)allocator.allocate(sizeof(cosmos_interfaces__msg__DCM__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cosmos_interfaces__msg__DCM__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cosmos_interfaces__msg__DCM__Sequence__destroy(cosmos_interfaces__msg__DCM__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cosmos_interfaces__msg__DCM__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cosmos_interfaces__msg__DCM__Sequence__are_equal(const cosmos_interfaces__msg__DCM__Sequence * lhs, const cosmos_interfaces__msg__DCM__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cosmos_interfaces__msg__DCM__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cosmos_interfaces__msg__DCM__Sequence__copy(
  const cosmos_interfaces__msg__DCM__Sequence * input,
  cosmos_interfaces__msg__DCM__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cosmos_interfaces__msg__DCM);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cosmos_interfaces__msg__DCM * data =
      (cosmos_interfaces__msg__DCM *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cosmos_interfaces__msg__DCM__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cosmos_interfaces__msg__DCM__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cosmos_interfaces__msg__DCM__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
