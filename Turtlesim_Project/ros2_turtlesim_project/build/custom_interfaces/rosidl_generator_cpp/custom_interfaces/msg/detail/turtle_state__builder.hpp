// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/TurtleState.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/turtle_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtleState_yaw_rate
{
public:
  explicit Init_TurtleState_yaw_rate(::custom_interfaces::msg::TurtleState & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::TurtleState yaw_rate(::custom_interfaces::msg::TurtleState::_yaw_rate_type arg)
  {
    msg_.yaw_rate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::TurtleState msg_;
};

class Init_TurtleState_x_velocity
{
public:
  Init_TurtleState_x_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtleState_yaw_rate x_velocity(::custom_interfaces::msg::TurtleState::_x_velocity_type arg)
  {
    msg_.x_velocity = std::move(arg);
    return Init_TurtleState_yaw_rate(msg_);
  }

private:
  ::custom_interfaces::msg::TurtleState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::TurtleState>()
{
  return custom_interfaces::msg::builder::Init_TurtleState_x_velocity();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__BUILDER_HPP_
