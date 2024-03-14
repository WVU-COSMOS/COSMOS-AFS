// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cosmos_interfaces:srv/AAToDCM.idl
// generated code does not contain a copyright notice
#include "cosmos_interfaces/srv/detail/aa_to_dcm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `ehat`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
cosmos_interfaces__srv__AAToDCM_Request__init(cosmos_interfaces__srv__AAToDCM_Request * msg)
{
  if (!msg) {
    return false;
  }
  // ehat
  if (!rosidl_runtime_c__double__Sequence__init(&msg->ehat, 0)) {
    cosmos_interfaces__srv__AAToDCM_Request__fini(msg);
    return false;
  }
  // phimag
  return true;
}

void
cosmos_interfaces__srv__AAToDCM_Request__fini(cosmos_interfaces__srv__AAToDCM_Request * msg)
{
  if (!msg) {
    return;
  }
  // ehat
  rosidl_runtime_c__double__Sequence__fini(&msg->ehat);
  // phimag
}

bool
cosmos_interfaces__srv__AAToDCM_Request__are_equal(const cosmos_interfaces__srv__AAToDCM_Request * lhs, const cosmos_interfaces__srv__AAToDCM_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ehat
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->ehat), &(rhs->ehat)))
  {
    return false;
  }
  // phimag
  if (lhs->phimag != rhs->phimag) {
    return false;
  }
  return true;
}

bool
cosmos_interfaces__srv__AAToDCM_Request__copy(
  const cosmos_interfaces__srv__AAToDCM_Request * input,
  cosmos_interfaces__srv__AAToDCM_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // ehat
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->ehat), &(output->ehat)))
  {
    return false;
  }
  // phimag
  output->phimag = input->phimag;
  return true;
}

cosmos_interfaces__srv__AAToDCM_Request *
cosmos_interfaces__srv__AAToDCM_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__srv__AAToDCM_Request * msg = (cosmos_interfaces__srv__AAToDCM_Request *)allocator.allocate(sizeof(cosmos_interfaces__srv__AAToDCM_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cosmos_interfaces__srv__AAToDCM_Request));
  bool success = cosmos_interfaces__srv__AAToDCM_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cosmos_interfaces__srv__AAToDCM_Request__destroy(cosmos_interfaces__srv__AAToDCM_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cosmos_interfaces__srv__AAToDCM_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cosmos_interfaces__srv__AAToDCM_Request__Sequence__init(cosmos_interfaces__srv__AAToDCM_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__srv__AAToDCM_Request * data = NULL;

  if (size) {
    data = (cosmos_interfaces__srv__AAToDCM_Request *)allocator.zero_allocate(size, sizeof(cosmos_interfaces__srv__AAToDCM_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cosmos_interfaces__srv__AAToDCM_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cosmos_interfaces__srv__AAToDCM_Request__fini(&data[i - 1]);
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
cosmos_interfaces__srv__AAToDCM_Request__Sequence__fini(cosmos_interfaces__srv__AAToDCM_Request__Sequence * array)
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
      cosmos_interfaces__srv__AAToDCM_Request__fini(&array->data[i]);
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

cosmos_interfaces__srv__AAToDCM_Request__Sequence *
cosmos_interfaces__srv__AAToDCM_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__srv__AAToDCM_Request__Sequence * array = (cosmos_interfaces__srv__AAToDCM_Request__Sequence *)allocator.allocate(sizeof(cosmos_interfaces__srv__AAToDCM_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cosmos_interfaces__srv__AAToDCM_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cosmos_interfaces__srv__AAToDCM_Request__Sequence__destroy(cosmos_interfaces__srv__AAToDCM_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cosmos_interfaces__srv__AAToDCM_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cosmos_interfaces__srv__AAToDCM_Request__Sequence__are_equal(const cosmos_interfaces__srv__AAToDCM_Request__Sequence * lhs, const cosmos_interfaces__srv__AAToDCM_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cosmos_interfaces__srv__AAToDCM_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cosmos_interfaces__srv__AAToDCM_Request__Sequence__copy(
  const cosmos_interfaces__srv__AAToDCM_Request__Sequence * input,
  cosmos_interfaces__srv__AAToDCM_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cosmos_interfaces__srv__AAToDCM_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cosmos_interfaces__srv__AAToDCM_Request * data =
      (cosmos_interfaces__srv__AAToDCM_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cosmos_interfaces__srv__AAToDCM_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cosmos_interfaces__srv__AAToDCM_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cosmos_interfaces__srv__AAToDCM_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
cosmos_interfaces__srv__AAToDCM_Response__init(cosmos_interfaces__srv__AAToDCM_Response * msg)
{
  if (!msg) {
    return false;
  }
  // dcm
  return true;
}

void
cosmos_interfaces__srv__AAToDCM_Response__fini(cosmos_interfaces__srv__AAToDCM_Response * msg)
{
  if (!msg) {
    return;
  }
  // dcm
}

bool
cosmos_interfaces__srv__AAToDCM_Response__are_equal(const cosmos_interfaces__srv__AAToDCM_Response * lhs, const cosmos_interfaces__srv__AAToDCM_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // dcm
  for (size_t i = 0; i < 9; ++i) {
    if (lhs->dcm[i] != rhs->dcm[i]) {
      return false;
    }
  }
  return true;
}

bool
cosmos_interfaces__srv__AAToDCM_Response__copy(
  const cosmos_interfaces__srv__AAToDCM_Response * input,
  cosmos_interfaces__srv__AAToDCM_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // dcm
  for (size_t i = 0; i < 9; ++i) {
    output->dcm[i] = input->dcm[i];
  }
  return true;
}

cosmos_interfaces__srv__AAToDCM_Response *
cosmos_interfaces__srv__AAToDCM_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__srv__AAToDCM_Response * msg = (cosmos_interfaces__srv__AAToDCM_Response *)allocator.allocate(sizeof(cosmos_interfaces__srv__AAToDCM_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cosmos_interfaces__srv__AAToDCM_Response));
  bool success = cosmos_interfaces__srv__AAToDCM_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cosmos_interfaces__srv__AAToDCM_Response__destroy(cosmos_interfaces__srv__AAToDCM_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cosmos_interfaces__srv__AAToDCM_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cosmos_interfaces__srv__AAToDCM_Response__Sequence__init(cosmos_interfaces__srv__AAToDCM_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__srv__AAToDCM_Response * data = NULL;

  if (size) {
    data = (cosmos_interfaces__srv__AAToDCM_Response *)allocator.zero_allocate(size, sizeof(cosmos_interfaces__srv__AAToDCM_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cosmos_interfaces__srv__AAToDCM_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cosmos_interfaces__srv__AAToDCM_Response__fini(&data[i - 1]);
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
cosmos_interfaces__srv__AAToDCM_Response__Sequence__fini(cosmos_interfaces__srv__AAToDCM_Response__Sequence * array)
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
      cosmos_interfaces__srv__AAToDCM_Response__fini(&array->data[i]);
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

cosmos_interfaces__srv__AAToDCM_Response__Sequence *
cosmos_interfaces__srv__AAToDCM_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cosmos_interfaces__srv__AAToDCM_Response__Sequence * array = (cosmos_interfaces__srv__AAToDCM_Response__Sequence *)allocator.allocate(sizeof(cosmos_interfaces__srv__AAToDCM_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cosmos_interfaces__srv__AAToDCM_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cosmos_interfaces__srv__AAToDCM_Response__Sequence__destroy(cosmos_interfaces__srv__AAToDCM_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cosmos_interfaces__srv__AAToDCM_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cosmos_interfaces__srv__AAToDCM_Response__Sequence__are_equal(const cosmos_interfaces__srv__AAToDCM_Response__Sequence * lhs, const cosmos_interfaces__srv__AAToDCM_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cosmos_interfaces__srv__AAToDCM_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cosmos_interfaces__srv__AAToDCM_Response__Sequence__copy(
  const cosmos_interfaces__srv__AAToDCM_Response__Sequence * input,
  cosmos_interfaces__srv__AAToDCM_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cosmos_interfaces__srv__AAToDCM_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cosmos_interfaces__srv__AAToDCM_Response * data =
      (cosmos_interfaces__srv__AAToDCM_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cosmos_interfaces__srv__AAToDCM_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cosmos_interfaces__srv__AAToDCM_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cosmos_interfaces__srv__AAToDCM_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
