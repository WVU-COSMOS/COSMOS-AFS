// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cosmos_interfaces:msg/Camera.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/msg/detail/camera__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `from_node`
// Member `to_node`
#include "rosidl_runtime_c/string_functions.h"

bool
cosmos_interfaces__msg__Camera__init(cosmos_interfaces__msg__Camera * msg)
{
  if (!msg) {
    return false;
  }
  // from_node
  if (!rosidl_runtime_c__String__init(&msg->from_node)) {
    cosmos_interfaces__msg__Camera__fini(msg);
    return false;
  }
  // to_node
  if (!rosidl_runtime_c__String__init(&msg->to_node)) {
    cosmos_interfaces__msg__Camera__fini(msg);
    return false;
  }
  // is_start
  // is_done
  // is_abort
  // is_target
  // img_num
  // next_img
  // u
  // v
  return true;
}

void
cosmos_interfaces__msg__Camera__fini(cosmos_interfaces__msg__Camera * msg)
{
  if (!msg) {
    return;
  }
  // from_node
  rosidl_runtime_c__String__fini(&msg->from_node);
  // to_node
  rosidl_runtime_c__String__fini(&msg->to_node);
  // is_start
  // is_done
  // is_abort
  // is_target
  // img_num
  // next_img
  // u
  // v
}

bool
cosmos_interfaces__msg__Camera__are_equal(const cosmos_interfaces__msg__Camera * lhs, const cosmos_interfaces__msg__Camera * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // from_node
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->from_node), &(rhs->from_node)))
  {
    return false;
  }
  // to_node
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->to_node), &(rhs->to_node)))
  {
    return false;
  }
  // is_start
  if (lhs->is_start != rhs->is_start) {
    return false;
  }
  // is_done
  if (lhs->is_done != rhs->is_done) {
    return false;
  }
  // is_abort
  if (lhs->is_abort != rhs->is_abort) {
    return false;
  }
  // is_target
  if (lhs->is_target != rhs->is_target) {
    return false;
  }
  // img_num
  if (lhs->img_num != rhs->img_num) {
    return false;
  }
  // next_img
  if (lhs->next_img != rhs->next_img) {
    return false;
  }
  // u
  if (lhs->u != rhs->u) {
    return false;
  }
  // v
  if (lhs->v != rhs->v) {
    return false;
  }
  return true;
}

bool
cosmos_interfaces__msg__Camera__copy(
  const cosmos_interfaces__msg__Camera * input,
  cosmos_interfaces__msg__Camera * output)
{
  if (!input || !output) {
    return false;
  }
  // from_node
  if (!rosidl_runtime_c__String__copy(
      &(input->from_node), &(output->from_node)))
  {
    return false;
  }
  // to_node
  if (!rosidl_runtime_c__String__copy(
      &(input->to_node), &(output->to_node)))
  {
    return false;
  }
  // is_start
  output->is_start = input->is_start;
  // is_done
  output->is_done = input->is_done;
  // is_abort
  output->is_abort = input->is_abort;
  // is_target
  output->is_target = input->is_target;
  // img_num
  output->img_num = input->img_num;
  // next_img
  output->next_img = input->next_img;
  // u
  output->u = input->u;
  // v
  output->v = input->v;
  return true;
}

cosmos_interfaces__msg__Camera *
cosmos_interfaces__msg__Camera__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__Camera * msg = (cosmos_interfaces__msg__Camera *)allocator.allocate(sizeof(cosmos_interfaces__msg__Camera), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cosmos_interfaces__msg__Camera));
  bool success = cosmos_interfaces__msg__Camera__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cosmos_interfaces__msg__Camera__destroy(cosmos_interfaces__msg__Camera * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cosmos_interfaces__msg__Camera__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cosmos_interfaces__msg__Camera__Sequence__init(cosmos_interfaces__msg__Camera__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__Camera * data = NULL;

  if (size) {
    data = (cosmos_interfaces__msg__Camera *)allocator.zero_allocate(size, sizeof(cosmos_interfaces__msg__Camera), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cosmos_interfaces__msg__Camera__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cosmos_interfaces__msg__Camera__fini(&data[i - 1]);
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
cosmos_interfaces__msg__Camera__Sequence__fini(cosmos_interfaces__msg__Camera__Sequence * array)
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
      cosmos_interfaces__msg__Camera__fini(&array->data[i]);
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

cosmos_interfaces__msg__Camera__Sequence *
cosmos_interfaces__msg__Camera__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__msg__Camera__Sequence * array = (cosmos_interfaces__msg__Camera__Sequence *)allocator.allocate(sizeof(cosmos_interfaces__msg__Camera__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cosmos_interfaces__msg__Camera__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cosmos_interfaces__msg__Camera__Sequence__destroy(cosmos_interfaces__msg__Camera__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cosmos_interfaces__msg__Camera__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cosmos_interfaces__msg__Camera__Sequence__are_equal(const cosmos_interfaces__msg__Camera__Sequence * lhs, const cosmos_interfaces__msg__Camera__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cosmos_interfaces__msg__Camera__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cosmos_interfaces__msg__Camera__Sequence__copy(
  const cosmos_interfaces__msg__Camera__Sequence * input,
  cosmos_interfaces__msg__Camera__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cosmos_interfaces__msg__Camera);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cosmos_interfaces__msg__Camera * data =
      (cosmos_interfaces__msg__Camera *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cosmos_interfaces__msg__Camera__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cosmos_interfaces__msg__Camera__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cosmos_interfaces__msg__Camera__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
