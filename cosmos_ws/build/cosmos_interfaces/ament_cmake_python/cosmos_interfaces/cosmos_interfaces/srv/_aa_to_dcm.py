# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cosmos_interfaces:srv/AAToDCM.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'ehat'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AAToDCM_Request(type):
    """Metaclass of message 'AAToDCM_Request'."""

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
                'cosmos_interfaces.srv.AAToDCM_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__aa_to_dcm__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__aa_to_dcm__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__aa_to_dcm__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__aa_to_dcm__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__aa_to_dcm__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AAToDCM_Request(metaclass=Metaclass_AAToDCM_Request):
    """Message class 'AAToDCM_Request'."""

    __slots__ = [
        '_ehat',
        '_phimag',
    ]

    _fields_and_field_types = {
        'ehat': 'sequence<double>',
        'phimag': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ehat = array.array('d', kwargs.get('ehat', []))
        self.phimag = kwargs.get('phimag', float())

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
        if self.ehat != other.ehat:
            return False
        if self.phimag != other.phimag:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ehat(self):
        """Message field 'ehat'."""
        return self._ehat

    @ehat.setter
    def ehat(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'ehat' array.array() must have the type code of 'd'"
            self._ehat = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'ehat' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._ehat = array.array('d', value)

    @builtins.property
    def phimag(self):
        """Message field 'phimag'."""
        return self._phimag

    @phimag.setter
    def phimag(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'phimag' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'phimag' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._phimag = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# Member 'dcm'
import numpy  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_AAToDCM_Response(type):
    """Metaclass of message 'AAToDCM_Response'."""

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
                'cosmos_interfaces.srv.AAToDCM_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__aa_to_dcm__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__aa_to_dcm__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__aa_to_dcm__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__aa_to_dcm__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__aa_to_dcm__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AAToDCM_Response(metaclass=Metaclass_AAToDCM_Response):
    """Message class 'AAToDCM_Response'."""

    __slots__ = [
        '_dcm',
    ]

    _fields_and_field_types = {
        'dcm': 'double[9]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 9),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'dcm' not in kwargs:
            self.dcm = numpy.zeros(9, dtype=numpy.float64)
        else:
            self.dcm = numpy.array(kwargs.get('dcm'), dtype=numpy.float64)
            assert self.dcm.shape == (9, )

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
        if all(self.dcm != other.dcm):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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


class Metaclass_AAToDCM(type):
    """Metaclass of service 'AAToDCM'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cosmos_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cosmos_interfaces.srv.AAToDCM')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__aa_to_dcm

            from cosmos_interfaces.srv import _aa_to_dcm
            if _aa_to_dcm.Metaclass_AAToDCM_Request._TYPE_SUPPORT is None:
                _aa_to_dcm.Metaclass_AAToDCM_Request.__import_type_support__()
            if _aa_to_dcm.Metaclass_AAToDCM_Response._TYPE_SUPPORT is None:
                _aa_to_dcm.Metaclass_AAToDCM_Response.__import_type_support__()


class AAToDCM(metaclass=Metaclass_AAToDCM):
    from cosmos_interfaces.srv._aa_to_dcm import AAToDCM_Request as Request
    from cosmos_interfaces.srv._aa_to_dcm import AAToDCM_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
