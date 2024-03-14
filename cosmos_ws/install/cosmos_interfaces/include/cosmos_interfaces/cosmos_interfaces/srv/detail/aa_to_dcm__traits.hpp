// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cosmos_interfaces:srv/AAToDCM.idl
// generated code does not contain a copyright notice

#ifndef COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__TRAITS_HPP_
#define COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cosmos_interfaces/srv/detail/aa_to_dcm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cosmos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AAToDCM_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: ehat
  {
    if (msg.ehat.size() == 0) {
      out << "ehat: []";
    } else {
      out << "ehat: [";
      size_t pending_items = msg.ehat.size();
      for (auto item : msg.ehat) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: phimag
  {
    out << "phimag: ";
    rosidl_generator_traits::value_to_yaml(msg.phimag, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AAToDCM_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ehat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ehat.size() == 0) {
      out << "ehat: []\n";
    } else {
      out << "ehat:\n";
      for (auto item : msg.ehat) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: phimag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "phimag: ";
    rosidl_generator_traits::value_to_yaml(msg.phimag, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AAToDCM_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cosmos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use cosmos_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cosmos_interfaces::srv::AAToDCM_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cosmos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cosmos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cosmos_interfaces::srv::AAToDCM_Request & msg)
{
  return cosmos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cosmos_interfaces::srv::AAToDCM_Request>()
{
  return "cosmos_interfaces::srv::AAToDCM_Request";
}

template<>
inline const char * name<cosmos_interfaces::srv::AAToDCM_Request>()
{
  return "cosmos_interfaces/srv/AAToDCM_Request";
}

template<>
struct has_fixed_size<cosmos_interfaces::srv::AAToDCM_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cosmos_interfaces::srv::AAToDCM_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cosmos_interfaces::srv::AAToDCM_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cosmos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AAToDCM_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: dcm
  {
    if (msg.dcm.size() == 0) {
      out << "dcm: []";
    } else {
      out << "dcm: [";
      size_t pending_items = msg.dcm.size();
      for (auto item : msg.dcm) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AAToDCM_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dcm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dcm.size() == 0) {
      out << "dcm: []\n";
    } else {
      out << "dcm:\n";
      for (auto item : msg.dcm) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AAToDCM_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cosmos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use cosmos_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cosmos_interfaces::srv::AAToDCM_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cosmos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cosmos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cosmos_interfaces::srv::AAToDCM_Response & msg)
{
  return cosmos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cosmos_interfaces::srv::AAToDCM_Response>()
{
  return "cosmos_interfaces::srv::AAToDCM_Response";
}

template<>
inline const char * name<cosmos_interfaces::srv::AAToDCM_Response>()
{
  return "cosmos_interfaces/srv/AAToDCM_Response";
}

template<>
struct has_fixed_size<cosmos_interfaces::srv::AAToDCM_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cosmos_interfaces::srv::AAToDCM_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cosmos_interfaces::srv::AAToDCM_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cosmos_interfaces::srv::AAToDCM>()
{
  return "cosmos_interfaces::srv::AAToDCM";
}

template<>
inline const char * name<cosmos_interfaces::srv::AAToDCM>()
{
  return "cosmos_interfaces/srv/AAToDCM";
}

template<>
struct has_fixed_size<cosmos_interfaces::srv::AAToDCM>
  : std::integral_constant<
    bool,
    has_fixed_size<cosmos_interfaces::srv::AAToDCM_Request>::value &&
    has_fixed_size<cosmos_interfaces::srv::AAToDCM_Response>::value
  >
{
};

template<>
struct has_bounded_size<cosmos_interfaces::srv::AAToDCM>
  : std::integral_constant<
    bool,
    has_bounded_size<cosmos_interfaces::srv::AAToDCM_Request>::value &&
    has_bounded_size<cosmos_interfaces::srv::AAToDCM_Response>::value
  >
{
};

template<>
struct is_service<cosmos_interfaces::srv::AAToDCM>
  : std::true_type
{
};

template<>
struct is_service_request<cosmos_interfaces::srv::AAToDCM_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cosmos_interfaces::srv::AAToDCM_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COSMOS_INTERFACES__SRV__DETAIL__AA_TO_DCM__TRAITS_HPP_
