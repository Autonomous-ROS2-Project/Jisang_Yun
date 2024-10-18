// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_interfaces:msg/ColorRGB.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__MSG__DETAIL__COLOR_RGB__BUILDER_HPP_
#define TURTLE_INTERFACES__MSG__DETAIL__COLOR_RGB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_interfaces/msg/detail/color_rgb__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_interfaces
{

namespace msg
{

namespace builder
{

class Init_ColorRGB_b
{
public:
  explicit Init_ColorRGB_b(::turtle_interfaces::msg::ColorRGB & msg)
  : msg_(msg)
  {}
  ::turtle_interfaces::msg::ColorRGB b(::turtle_interfaces::msg::ColorRGB::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_interfaces::msg::ColorRGB msg_;
};

class Init_ColorRGB_g
{
public:
  explicit Init_ColorRGB_g(::turtle_interfaces::msg::ColorRGB & msg)
  : msg_(msg)
  {}
  Init_ColorRGB_b g(::turtle_interfaces::msg::ColorRGB::_g_type arg)
  {
    msg_.g = std::move(arg);
    return Init_ColorRGB_b(msg_);
  }

private:
  ::turtle_interfaces::msg::ColorRGB msg_;
};

class Init_ColorRGB_r
{
public:
  Init_ColorRGB_r()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ColorRGB_g r(::turtle_interfaces::msg::ColorRGB::_r_type arg)
  {
    msg_.r = std::move(arg);
    return Init_ColorRGB_g(msg_);
  }

private:
  ::turtle_interfaces::msg::ColorRGB msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_interfaces::msg::ColorRGB>()
{
  return turtle_interfaces::msg::builder::Init_ColorRGB_r();
}

}  // namespace turtle_interfaces

#endif  // TURTLE_INTERFACES__MSG__DETAIL__COLOR_RGB__BUILDER_HPP_
