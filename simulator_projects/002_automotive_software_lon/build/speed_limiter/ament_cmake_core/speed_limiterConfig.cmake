# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_speed_limiter_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED speed_limiter_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(speed_limiter_FOUND FALSE)
  elseif(NOT speed_limiter_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(speed_limiter_FOUND FALSE)
  endif()
  return()
endif()
set(_speed_limiter_CONFIG_INCLUDED TRUE)

# output package information
if(NOT speed_limiter_FIND_QUIETLY)
  message(STATUS "Found speed_limiter: 0.0.0 (${speed_limiter_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'speed_limiter' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${speed_limiter_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(speed_limiter_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${speed_limiter_DIR}/${_extra}")
endforeach()
