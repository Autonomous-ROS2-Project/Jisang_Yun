// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_interfaces:msg/ColorRGB.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__MSG__DETAIL__COLOR_RGB__STRUCT_H_
#define TURTLE_INTERFACES__MSG__DETAIL__COLOR_RGB__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ColorRGB in the package turtle_interfaces.
typedef struct turtle_interfaces__msg__ColorRGB
{
  float r;
  float g;
  float b;
} turtle_interfaces__msg__ColorRGB;

// Struct for a sequence of turtle_interfaces__msg__ColorRGB.
typedef struct turtle_interfaces__msg__ColorRGB__Sequence
{
  turtle_interfaces__msg__ColorRGB * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_interfaces__msg__ColorRGB__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_INTERFACES__MSG__DETAIL__COLOR_RGB__STRUCT_H_
