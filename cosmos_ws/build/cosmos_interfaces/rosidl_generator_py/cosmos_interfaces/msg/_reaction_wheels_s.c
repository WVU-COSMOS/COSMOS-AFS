// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cosmos_interfaces:msg/ReactionWheels.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "cosmos_interfaces/msg/detail/reaction_wheels__struct.h"
#include "cosmos_interfaces/msg/detail/reaction_wheels__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool cosmos_interfaces__msg__reaction_wheels__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("cosmos_interfaces.msg._reaction_wheels.ReactionWheels", full_classname_dest, 53) == 0);
  }
  cosmos_interfaces__msg__ReactionWheels * ros_message = _ros_message;
  {  // from_node
    PyObject * field = PyObject_GetAttrString(_pymsg, "from_node");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->from_node, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // to_node
    PyObject * field = PyObject_GetAttrString(_pymsg, "to_node");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->to_node, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // is_done
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_done");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_done = (Py_True == field);
    Py_DECREF(field);
  }
  {  // motor_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_x");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->motor_x = (Py_True == field);
    Py_DECREF(field);
  }
  {  // motor_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_y");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->motor_y = (Py_True == field);
    Py_DECREF(field);
  }
  {  // motor_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_z");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->motor_z = (Py_True == field);
    Py_DECREF(field);
  }
  {  // speed_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->speed_x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // speed_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->speed_y = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // speed_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_z");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->speed_z = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // time_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->time_x = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // time_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->time_y = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // time_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_z");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->time_z = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cosmos_interfaces__msg__reaction_wheels__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ReactionWheels */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cosmos_interfaces.msg._reaction_wheels");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ReactionWheels");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cosmos_interfaces__msg__ReactionWheels * ros_message = (cosmos_interfaces__msg__ReactionWheels *)raw_ros_message;
  {  // from_node
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->from_node.data,
      strlen(ros_message->from_node.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "from_node", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // to_node
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->to_node.data,
      strlen(ros_message->to_node.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "to_node", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_done
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_done ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_done", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor_x
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->motor_x ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor_y
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->motor_y ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor_z
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->motor_z ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->speed_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->speed_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_z
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->speed_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // time_x
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->time_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // time_y
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->time_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // time_z
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->time_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
