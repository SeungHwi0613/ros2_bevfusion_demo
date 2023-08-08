// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bev_msgs:msg/OutputArray.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__TRAITS_HPP_
#define BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__TRAITS_HPP_

#include "bev_msgs/msg/detail/output_array__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bev_msgs::msg::OutputArray>()
{
  return "bev_msgs::msg::OutputArray";
}

template<>
inline const char * name<bev_msgs::msg::OutputArray>()
{
  return "bev_msgs/msg/OutputArray";
}

template<>
struct has_fixed_size<bev_msgs::msg::OutputArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<bev_msgs::msg::OutputArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<bev_msgs::msg::OutputArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__TRAITS_HPP_
