# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cosmos_interfaces:msg/DCM.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'dcm'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DCM(type):
    """Metaclass of message 'DCM'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cosmos_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cosmos_interfaces.msg.DCM')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__dcm
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__dcm
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__dcm
            cls._TYPE_SUPPORT = module.type_support_msg__msg__dcm
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__dcm

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DCM(metaclass=Metaclass_DCM):
    """Message class 'DCM'."""

    __slots__ = [
        '_to_node',
        '_from_node',
        '_is_start',
        '_is_target',
        '_is_abort',
        '_dcm',
        '_t',
    ]

    _fields_and_field_types = {
        'to_node': 'string',
        'from_node': 'string',
        'is_start': 'boolean',
        'is_target': 'boolean',
        'is_abort': 'boolean',
        'dcm': 'double[9]',
        't': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 9),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.to_node = kwargs.get('to_node', str())
        self.from_node = kwargs.get('from_node', str())
        self.is_start = kwargs.get('is_start', bool())
        self.is_target = kwargs.get('is_target', bool())
        self.is_abort = kwargs.get('is_abort', bool())
        if 'dcm' not in kwargs:
            self.dcm = numpy.zeros(9, dtype=numpy.float64)
        else:
            self.dcm = numpy.array(kwargs.get('dcm'), dtype=numpy.float64)
            assert self.dcm.shape == (9, )
        self.t = kwargs.get('t', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.to_node != other.to_node:
            return False
        if self.from_node != other.from_node:
            return False
        if self.is_start != other.is_start:
            return False
        if self.is_target != other.is_target:
            return False
        if self.is_abort != other.is_abort:
            return False
        if all(self.dcm != other.dcm):
            return False
        if self.t != other.t:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def to_node(self):
        """Message field 'to_node'."""
        return self._to_node

    @to_node.setter
    def to_node(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'to_node' field must be of type 'str'"
        self._to_node = value

    @builtins.property
    def from_node(self):
        """Message field 'from_node'."""
        return self._from_node

    @from_node.setter
    def from_node(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'from_node' field must be of type 'str'"
        self._from_node = value

    @builtins.property
    def is_start(self):
        """Message field 'is_start'."""
        return self._is_start

    @is_start.setter
    def is_start(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_start' field must be of type 'bool'"
        self._is_start = value

    @builtins.property
    def is_target(self):
        """Message field 'is_target'."""
        return self._is_target

    @is_target.setter
    def is_target(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_target' field must be of type 'bool'"
        self._is_target = value

    @builtins.property
    def is_abort(self):
        """Message field 'is_abort'."""
        return self._is_abort

    @is_abort.setter
    def is_abort(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_abort' field must be of type 'bool'"
        self._is_abort = value

    @builtins.property
    def dcm(self):
        """Message field 'dcm'."""
        return self._dcm

    @dcm.setter
    def dcm(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'dcm' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 9, \
                "The 'dcm' numpy.ndarray() must have a size of 9"
            self._dcm = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 9 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'dcm' field must be a set or sequence with length 9 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._dcm = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def t(self):
        """Message field 't'."""
        return self._t

    @t.setter
    def t(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 't' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 't' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._t = value
