# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cosmos_interfaces:msg/Position.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Position(type):
    """Metaclass of message 'Position'."""

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
                'cosmos_interfaces.msg.Position')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__position

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Position(metaclass=Metaclass_Position):
    """Message class 'Position'."""

    __slots__ = [
        '_mission',
        '_current_position',
        '_next_position',
        '_is_running',
    ]

    _fields_and_field_types = {
        'mission': 'int64',
        'current_position': 'int64',
        'next_position': 'int64',
        'is_running': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mission = kwargs.get('mission', int())
        self.current_position = kwargs.get('current_position', int())
        self.next_position = kwargs.get('next_position', int())
        self.is_running = kwargs.get('is_running', bool())

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
        if self.mission != other.mission:
            return False
        if self.current_position != other.current_position:
            return False
        if self.next_position != other.next_position:
            return False
        if self.is_running != other.is_running:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mission(self):
        """Message field 'mission'."""
        return self._mission

    @mission.setter
    def mission(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mission' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'mission' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._mission = value

    @builtins.property
    def current_position(self):
        """Message field 'current_position'."""
        return self._current_position

    @current_position.setter
    def current_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_position' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'current_position' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._current_position = value

    @builtins.property
    def next_position(self):
        """Message field 'next_position'."""
        return self._next_position

    @next_position.setter
    def next_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'next_position' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'next_position' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._next_position = value

    @builtins.property
    def is_running(self):
        """Message field 'is_running'."""
        return self._is_running

    @is_running.setter
    def is_running(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_running' field must be of type 'bool'"
        self._is_running = value
