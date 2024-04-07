# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cosmos_interfaces:msg/ReactionWheels.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ReactionWheels(type):
    """Metaclass of message 'ReactionWheels'."""

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
                'cosmos_interfaces.msg.ReactionWheels')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__reaction_wheels
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__reaction_wheels
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__reaction_wheels
            cls._TYPE_SUPPORT = module.type_support_msg__msg__reaction_wheels
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__reaction_wheels

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ReactionWheels(metaclass=Metaclass_ReactionWheels):
    """Message class 'ReactionWheels'."""

    __slots__ = [
        '_from_node',
        '_to_node',
        '_is_done',
        '_motor_x',
        '_motor_y',
        '_motor_z',
        '_speed_x',
        '_speed_y',
        '_speed_z',
        '_time_x',
        '_time_y',
        '_time_z',
    ]

    _fields_and_field_types = {
        'from_node': 'string',
        'to_node': 'string',
        'is_done': 'boolean',
        'motor_x': 'boolean',
        'motor_y': 'boolean',
        'motor_z': 'boolean',
        'speed_x': 'int32',
        'speed_y': 'int32',
        'speed_z': 'int32',
        'time_x': 'int64',
        'time_y': 'int64',
        'time_z': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.from_node = kwargs.get('from_node', str())
        self.to_node = kwargs.get('to_node', str())
        self.is_done = kwargs.get('is_done', bool())
        self.motor_x = kwargs.get('motor_x', bool())
        self.motor_y = kwargs.get('motor_y', bool())
        self.motor_z = kwargs.get('motor_z', bool())
        self.speed_x = kwargs.get('speed_x', int())
        self.speed_y = kwargs.get('speed_y', int())
        self.speed_z = kwargs.get('speed_z', int())
        self.time_x = kwargs.get('time_x', int())
        self.time_y = kwargs.get('time_y', int())
        self.time_z = kwargs.get('time_z', int())

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
        if self.from_node != other.from_node:
            return False
        if self.to_node != other.to_node:
            return False
        if self.is_done != other.is_done:
            return False
        if self.motor_x != other.motor_x:
            return False
        if self.motor_y != other.motor_y:
            return False
        if self.motor_z != other.motor_z:
            return False
        if self.speed_x != other.speed_x:
            return False
        if self.speed_y != other.speed_y:
            return False
        if self.speed_z != other.speed_z:
            return False
        if self.time_x != other.time_x:
            return False
        if self.time_y != other.time_y:
            return False
        if self.time_z != other.time_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def is_done(self):
        """Message field 'is_done'."""
        return self._is_done

    @is_done.setter
    def is_done(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_done' field must be of type 'bool'"
        self._is_done = value

    @builtins.property
    def motor_x(self):
        """Message field 'motor_x'."""
        return self._motor_x

    @motor_x.setter
    def motor_x(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'motor_x' field must be of type 'bool'"
        self._motor_x = value

    @builtins.property
    def motor_y(self):
        """Message field 'motor_y'."""
        return self._motor_y

    @motor_y.setter
    def motor_y(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'motor_y' field must be of type 'bool'"
        self._motor_y = value

    @builtins.property
    def motor_z(self):
        """Message field 'motor_z'."""
        return self._motor_z

    @motor_z.setter
    def motor_z(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'motor_z' field must be of type 'bool'"
        self._motor_z = value

    @builtins.property
    def speed_x(self):
        """Message field 'speed_x'."""
        return self._speed_x

    @speed_x.setter
    def speed_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'speed_x' field must be an integer in [-2147483648, 2147483647]"
        self._speed_x = value

    @builtins.property
    def speed_y(self):
        """Message field 'speed_y'."""
        return self._speed_y

    @speed_y.setter
    def speed_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'speed_y' field must be an integer in [-2147483648, 2147483647]"
        self._speed_y = value

    @builtins.property
    def speed_z(self):
        """Message field 'speed_z'."""
        return self._speed_z

    @speed_z.setter
    def speed_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed_z' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'speed_z' field must be an integer in [-2147483648, 2147483647]"
        self._speed_z = value

    @builtins.property
    def time_x(self):
        """Message field 'time_x'."""
        return self._time_x

    @time_x.setter
    def time_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time_x' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'time_x' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._time_x = value

    @builtins.property
    def time_y(self):
        """Message field 'time_y'."""
        return self._time_y

    @time_y.setter
    def time_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time_y' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'time_y' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._time_y = value

    @builtins.property
    def time_z(self):
        """Message field 'time_z'."""
        return self._time_z

    @time_z.setter
    def time_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time_z' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'time_z' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._time_z = value
