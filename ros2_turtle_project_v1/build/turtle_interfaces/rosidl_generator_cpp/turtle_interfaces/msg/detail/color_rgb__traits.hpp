// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_interfaces:msg/ColorRGB.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__MSG__DETAIL__COLOR_RGB__TRAITS_HPP_
#define TURTLE_INTERFACES__MSG__DETAIL__COLOR_RGB__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_interfaces/msg/detail/color_rgb__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ColorRGB & msg,
  std::ostream & out)
{
  out << "{";
  // member: r
  {
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << ", ";
  }

  // member: g
  {
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ColorRGB & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << "\n";
  }

  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ColorRGB & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtle_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_interfaces::msg::ColorRGB & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtle_interfaces::msg::ColorRGB & msg)
{
  return turtle_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_interfaces::msg::ColorRGB>()
{
  return "turtle_interfaces::msg::ColorRGB";
}

template<>
inline const char * name<turtle_interfaces::msg::ColorRGB>()
{
  return "turtle_interfaces/msg/ColorRGB";
}

template<>
struct has_fixed_size<turtle_interfaces::msg::ColorRGB>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_interfaces::msg::ColorRGB>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_interfaces::msg::ColorRGB>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_INTERFACES__MSG__DETAIL__COLOR_RGB__TRAITS_HPP_
