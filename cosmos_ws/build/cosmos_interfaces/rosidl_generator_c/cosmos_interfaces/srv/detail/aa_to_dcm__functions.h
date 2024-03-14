// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cosmos_interfaces:srv/AAToDCM.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__FUNCTIONS_H_
#define COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cosmos_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "cosmos_interfaces/srv/detail/aa_to_dcm__struct.h"

/// Initialize srv/AAToDCM message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cosmos_interfaces__srv__AAToDCM_Request
 * )) before or use
 * cosmos_interfaces__srv__AAToDCM_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Request__init(cosmos_interfaces__srv__AAToDCM_Request * msg);

/// Finalize srv/AAToDCM message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
void
cosmos_interfaces__srv__AAToDCM_Request__fini(cosmos_interfaces__srv__AAToDCM_Request * msg);

/// Create srv/AAToDCM message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cosmos_interfaces__srv__AAToDCM_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
cosmos_interfaces__srv__AAToDCM_Request *
cosmos_interfaces__srv__AAToDCM_Request__create();

/// Destroy srv/AAToDCM message.
/**
 * It calls
 * cosmos_interfaces__srv__AAToDCM_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
void
cosmos_interfaces__srv__AAToDCM_Request__destroy(cosmos_interfaces__srv__AAToDCM_Request * msg);

/// Check for srv/AAToDCM message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Request__are_equal(const cosmos_interfaces__srv__AAToDCM_Request * lhs, const cosmos_interfaces__srv__AAToDCM_Request * rhs);

/// Copy a srv/AAToDCM message.
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
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Request__copy(
  const cosmos_interfaces__srv__AAToDCM_Request * input,
  cosmos_interfaces__srv__AAToDCM_Request * output);

/// Initialize array of srv/AAToDCM messages.
/**
 * It allocates the memory for the number of elements and calls
 * cosmos_interfaces__srv__AAToDCM_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Request__Sequence__init(cosmos_interfaces__srv__AAToDCM_Request__Sequence * array, size_t size);

/// Finalize array of srv/AAToDCM messages.
/**
 * It calls
 * cosmos_interfaces__srv__AAToDCM_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
void
cosmos_interfaces__srv__AAToDCM_Request__Sequence__fini(cosmos_interfaces__srv__AAToDCM_Request__Sequence * array);

/// Create array of srv/AAToDCM messages.
/**
 * It allocates the memory for the array and calls
 * cosmos_interfaces__srv__AAToDCM_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
cosmos_interfaces__srv__AAToDCM_Request__Sequence *
cosmos_interfaces__srv__AAToDCM_Request__Sequence__create(size_t size);

/// Destroy array of srv/AAToDCM messages.
/**
 * It calls
 * cosmos_interfaces__srv__AAToDCM_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
void
cosmos_interfaces__srv__AAToDCM_Request__Sequence__destroy(cosmos_interfaces__srv__AAToDCM_Request__Sequence * array);

/// Check for srv/AAToDCM message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Request__Sequence__are_equal(const cosmos_interfaces__srv__AAToDCM_Request__Sequence * lhs, const cosmos_interfaces__srv__AAToDCM_Request__Sequence * rhs);

/// Copy an array of srv/AAToDCM messages.
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
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Request__Sequence__copy(
  const cosmos_interfaces__srv__AAToDCM_Request__Sequence * input,
  cosmos_interfaces__srv__AAToDCM_Request__Sequence * output);

/// Initialize srv/AAToDCM message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cosmos_interfaces__srv__AAToDCM_Response
 * )) before or use
 * cosmos_interfaces__srv__AAToDCM_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Response__init(cosmos_interfaces__srv__AAToDCM_Response * msg);

/// Finalize srv/AAToDCM message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
void
cosmos_interfaces__srv__AAToDCM_Response__fini(cosmos_interfaces__srv__AAToDCM_Response * msg);

/// Create srv/AAToDCM message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cosmos_interfaces__srv__AAToDCM_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
cosmos_interfaces__srv__AAToDCM_Response *
cosmos_interfaces__srv__AAToDCM_Response__create();

/// Destroy srv/AAToDCM message.
/**
 * It calls
 * cosmos_interfaces__srv__AAToDCM_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
void
cosmos_interfaces__srv__AAToDCM_Response__destroy(cosmos_interfaces__srv__AAToDCM_Response * msg);

/// Check for srv/AAToDCM message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Response__are_equal(const cosmos_interfaces__srv__AAToDCM_Response * lhs, const cosmos_interfaces__srv__AAToDCM_Response * rhs);

/// Copy a srv/AAToDCM message.
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
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Response__copy(
  const cosmos_interfaces__srv__AAToDCM_Response * input,
  cosmos_interfaces__srv__AAToDCM_Response * output);

/// Initialize array of srv/AAToDCM messages.
/**
 * It allocates the memory for the number of elements and calls
 * cosmos_interfaces__srv__AAToDCM_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Response__Sequence__init(cosmos_interfaces__srv__AAToDCM_Response__Sequence * array, size_t size);

/// Finalize array of srv/AAToDCM messages.
/**
 * It calls
 * cosmos_interfaces__srv__AAToDCM_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
void
cosmos_interfaces__srv__AAToDCM_Response__Sequence__fini(cosmos_interfaces__srv__AAToDCM_Response__Sequence * array);

/// Create array of srv/AAToDCM messages.
/**
 * It allocates the memory for the array and calls
 * cosmos_interfaces__srv__AAToDCM_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
cosmos_interfaces__srv__AAToDCM_Response__Sequence *
cosmos_interfaces__srv__AAToDCM_Response__Sequence__create(size_t size);

/// Destroy array of srv/AAToDCM messages.
/**
 * It calls
 * cosmos_interfaces__srv__AAToDCM_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
void
cosmos_interfaces__srv__AAToDCM_Response__Sequence__destroy(cosmos_interfaces__srv__AAToDCM_Response__Sequence * array);

/// Check for srv/AAToDCM message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Response__Sequence__are_equal(const cosmos_interfaces__srv__AAToDCM_Response__Sequence * lhs, const cosmos_interfaces__srv__AAToDCM_Response__Sequence * rhs);

/// Copy an array of srv/AAToDCM messages.
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
ROSIDL_GENERATOR_C_PUBLIC_cosmos_interfaces
bool
cosmos_interfaces__srv__AAToDCM_Response__Sequence__copy(
  const cosmos_interfaces__srv__AAToDCM_Response__Sequence * input,
  cosmos_interfaces__srv__AAToDCM_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__FUNCTIONS_H_
