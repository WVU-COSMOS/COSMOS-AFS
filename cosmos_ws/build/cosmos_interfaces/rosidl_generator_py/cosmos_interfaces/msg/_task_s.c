// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cosmos_interfaces:msg/Task.idl
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
#include "cosmos_interfaces/msg/detail/task__struct.h"
#include "cosmos_interfaces/msg/detail/task__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool cosmos_interfaces__msg__task__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
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
    assert(strncmp("cosmos_interfaces.msg._task.Task", full_classname_dest, 32) == 0);
  }
  cosmos_interfaces__msg__Task * ros_message = _ros_message;
  {  // mission
    PyObject * field = PyObject_GetAttrString(_pymsg, "mission");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mission = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // node
    PyObject * field = PyObject_GetAttrString(_pymsg, "node");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->node = (int32_t)PyLong_AsLong(field);
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cosmos_interfaces__msg__task__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Task */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cosmos_interfaces.msg._task");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Task");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cosmos_interfaces__msg__Task * ros_message = (cosmos_interfaces__msg__Task *)raw_ros_message;
  {  // mission
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->mission);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mission", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // node
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->node);
    {
      int rc = PyObject_SetAttrString(_pymessage, "node", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}