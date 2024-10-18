// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/TurtleColor.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_COLOR__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_COLOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/turtle_color__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtleColor_blue
{
public:
  explicit Init_TurtleColor_blue(::custom_interfaces::msg::TurtleColor & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::TurtleColor blue(::custom_interfaces::msg::TurtleColor::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::TurtleColor msg_;
};

class Init_TurtleColor_green
{
public:
  explicit Init_TurtleColor_green(::custom_interfaces::msg::TurtleColor & msg)
  : msg_(msg)
  {}
  Init_TurtleColor_blue green(::custom_interfaces::msg::TurtleColor::_green_type arg)
  {
    msg_.green = std::move(arg);
    return Init_TurtleColor_blue(msg_);
  }

private:
  ::custom_interfaces::msg::TurtleColor msg_;
};

class Init_TurtleColor_red
{
public:
  Init_TurtleColor_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtleColor_green red(::custom_interfaces::msg::TurtleColor::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_TurtleColor_green(msg_);
  }

private:
  ::custom_interfaces::msg::TurtleColor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::TurtleColor>()
{
  return custom_interfaces::msg::builder::Init_TurtleColor_red();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_COLOR__BUILDER_HPP_
