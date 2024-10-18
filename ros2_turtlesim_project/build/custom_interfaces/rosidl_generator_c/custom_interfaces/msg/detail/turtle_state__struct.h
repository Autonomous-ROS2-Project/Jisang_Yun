// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/TurtleState.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x_velocity'
// Member 'yaw_rate'
#include "std_msgs/msg/detail/float32__struct.h"

/// Struct defined in msg/TurtleState in the package custom_interfaces.
typedef struct custom_interfaces__msg__TurtleState
{
  std_msgs__msg__Float32 x_velocity;
  std_msgs__msg__Float32 yaw_rate;
} custom_interfaces__msg__TurtleState;

// Struct for a sequence of custom_interfaces__msg__TurtleState.
typedef struct custom_interfaces__msg__TurtleState__Sequence
{
  custom_interfaces__msg__TurtleState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__TurtleState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TURTLE_STATE__STRUCT_H_
