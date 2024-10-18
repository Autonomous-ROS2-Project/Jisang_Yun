// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/TurtleState.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/turtle_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'x_velocity'
// Member 'yaw_rate'
#include "std_msgs/msg/detail/float32__traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TurtleState & msg,
  std::ostream & out)
{
  out << "{";
  // member: x_velocity
  {
    out << "x_velocity: ";
    to_flow_style_yaml(msg.x_velocity, out);
    out << ", ";
  }

  // member: yaw_rate
  {
    out << "yaw_rate: ";
    to_flow_style_yaml(msg.yaw_rate, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TurtleState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_velocity:\n";
    to_block_style_yaml(msg.x_velocity, out, indentation + 2);
  }

  // member: yaw_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_rate:\n";
    to_block_style_yaml(msg.yaw_rate, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TurtleState & msg, bool use_flow_style = false)
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

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::TurtleState & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::TurtleState & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::TurtleState>()
{
  return "custom_interfaces::msg::TurtleState";
}

template<>
inline const char * name<custom_interfaces::msg::TurtleState>()
{
  return "custom_interfaces/msg/TurtleState";
}

template<>
struct has_fixed_size<custom_interfaces::msg::TurtleState>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float32>::value> {};

template<>
struct has_bounded_size<custom_interfaces::msg::TurtleState>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float32>::value> {};

template<>
struct is_message<custom_interfaces::msg::TurtleState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__TRAITS_HPP_
