// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bev_msgs:msg/Output.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__OUTPUT__TRAITS_HPP_
#define BEV_MSGS__MSG__DETAIL__OUTPUT__TRAITS_HPP_

#include "bev_msgs/msg/detail/output__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'box'
#include "bev_msgs/msg/detail/bbox__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bev_msgs::msg::Output>()
{
  return "bev_msgs::msg::Output";
}

template<>
inline const char * name<bev_msgs::msg::Output>()
{
  return "bev_msgs/msg/Output";
}

template<>
struct has_fixed_size<bev_msgs::msg::Output>
  : std::integral_constant<bool, has_fixed_size<bev_msgs::msg::Bbox>::value> {};

template<>
struct has_bounded_size<bev_msgs::msg::Output>
  : std::integral_constant<bool, has_bounded_size<bev_msgs::msg::Bbox>::value> {};

template<>
struct is_message<bev_msgs::msg::Output>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BEV_MSGS__MSG__DETAIL__OUTPUT__TRAITS_HPP_
