# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cosmos_interfaces:msg/Camera.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Camera(type):
    """Metaclass of message 'Camera'."""

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
                'cosmos_interfaces.msg.Camera')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__camera
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__camera
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__camera
            cls._TYPE_SUPPORT = module.type_support_msg__msg__camera
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__camera

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Camera(metaclass=Metaclass_Camera):
    """Message class 'Camera'."""

    __slots__ = [
        '_from_node',
        '_to_node',
        '_is_start',
        '_is_done',
        '_is_abort',
        '_is_target',
        '_img_num',
        '_next_img',
        '_u',
        '_v',
    ]

    _fields_and_field_types = {
        'from_node': 'string',
        'to_node': 'string',
        'is_start': 'boolean',
        'is_done': 'boolean',
        'is_abort': 'boolean',
        'is_target': 'boolean',
        'img_num': 'int32',
        'next_img': 'boolean',
        'u': 'int32',
        'v': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.from_node = kwargs.get('from_node', str())
        self.to_node = kwargs.get('to_node', str())
        self.is_start = kwargs.get('is_start', bool())
        self.is_done = kwargs.get('is_done', bool())
        self.is_abort = kwargs.get('is_abort', bool())
        self.is_target = kwargs.get('is_target', bool())
        self.img_num = kwargs.get('img_num', int())
        self.next_img = kwargs.get('next_img', bool())
        self.u = kwargs.get('u', int())
        self.v = kwargs.get('v', int())

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
        if self.is_start != other.is_start:
            return False
        if self.is_done != other.is_done:
            return False
        if self.is_abort != other.is_abort:
            return False
        if self.is_target != other.is_target:
            return False
        if self.img_num != other.img_num:
            return False
        if self.next_img != other.next_img:
            return False
        if self.u != other.u:
            return False
        if self.v != other.v:
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
    def img_num(self):
        """Message field 'img_num'."""
        return self._img_num

    @img_num.setter
    def img_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'img_num' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'img_num' field must be an integer in [-2147483648, 2147483647]"
        self._img_num = value

    @builtins.property
    def next_img(self):
        """Message field 'next_img'."""
        return self._next_img

    @next_img.setter
    def next_img(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'next_img' field must be of type 'bool'"
        self._next_img = value

    @builtins.property
    def u(self):
        """Message field 'u'."""
        return self._u

    @u.setter
    def u(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'u' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'u' field must be an integer in [-2147483648, 2147483647]"
        self._u = value

    @builtins.property
    def v(self):
        """Message field 'v'."""
        return self._v

    @v.setter
    def v(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'v' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'v' field must be an integer in [-2147483648, 2147483647]"
        self._v = value
