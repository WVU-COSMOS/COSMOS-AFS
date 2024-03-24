// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cosmos_interfaces:msg/Camera.idl
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
#include "cosmos_interfaces/msg/detail/camera__struct.h"
#include "cosmos_interfaces/msg/detail/camera__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool cosmos_interfaces__msg__camera__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
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
    assert(strncmp("cosmos_interfaces.msg._camera.Camera", full_classname_dest, 36) == 0);
  }
  cosmos_interfaces__msg__Camera * ros_message = _ros_message;
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
  {  // is_start
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_start");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_start = (Py_True == field);
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
  {  // is_abort
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_abort");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_abort = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_target
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_target");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_target = (Py_True == field);
    Py_DECREF(field);
  }
  {  // img_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "img_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->img_num = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // next_img
    PyObject * field = PyObject_GetAttrString(_pymsg, "next_img");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->next_img = (Py_True == field);
    Py_DECREF(field);
  }
  {  // u
    PyObject * field = PyObject_GetAttrString(_pymsg, "u");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->u = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // v
    PyObject * field = PyObject_GetAttrString(_pymsg, "v");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->v = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cosmos_interfaces__msg__camera__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Camera */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cosmos_interfaces.msg._camera");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Camera");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cosmos_interfaces__msg__Camera * ros_message = (cosmos_interfaces__msg__Camera *)raw_ros_message;
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
  {  // is_start
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_start ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_start", field);
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
  {  // is_abort
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_abort ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_abort", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_target
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_target ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_target", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // img_num
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->img_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "img_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // next_img
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->next_img ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "next_img", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // u
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->u);
    {
      int rc = PyObject_SetAttrString(_pymessage, "u", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
