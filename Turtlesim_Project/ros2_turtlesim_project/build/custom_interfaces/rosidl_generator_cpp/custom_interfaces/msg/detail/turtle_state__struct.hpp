// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/TurtleState.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'x_velocity'
// Member 'yaw_rate'
#include "std_msgs/msg/detail/float32__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__TurtleState __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__TurtleState __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TurtleState_
{
  using Type = TurtleState_<ContainerAllocator>;

  explicit TurtleState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : x_velocity(_init),
    yaw_rate(_init)
  {
    (void)_init;
  }

  explicit TurtleState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : x_velocity(_alloc, _init),
    yaw_rate(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _x_velocity_type =
    std_msgs::msg::Float32_<ContainerAllocator>;
  _x_velocity_type x_velocity;
  using _yaw_rate_type =
    std_msgs::msg::Float32_<ContainerAllocator>;
  _yaw_rate_type yaw_rate;

  // setters for named parameter idiom
  Type & set__x_velocity(
    const std_msgs::msg::Float32_<ContainerAllocator> & _arg)
  {
    this->x_velocity = _arg;
    return *this;
  }
  Type & set__yaw_rate(
    const std_msgs::msg::Float32_<ContainerAllocator> & _arg)
  {
    this->yaw_rate = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::TurtleState_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::TurtleState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::TurtleState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::TurtleState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::TurtleState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::TurtleState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::TurtleState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::TurtleState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::TurtleState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::TurtleState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__TurtleState
    std::shared_ptr<custom_interfaces::msg::TurtleState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__TurtleState
    std::shared_ptr<custom_interfaces::msg::TurtleState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurtleState_ & other) const
  {
    if (this->x_velocity != other.x_velocity) {
      return false;
    }
    if (this->yaw_rate != other.yaw_rate) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurtleState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurtleState_

// alias to use template instance with default allocator
using TurtleState =
  custom_interfaces::msg::TurtleState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__STRUCT_HPP_
