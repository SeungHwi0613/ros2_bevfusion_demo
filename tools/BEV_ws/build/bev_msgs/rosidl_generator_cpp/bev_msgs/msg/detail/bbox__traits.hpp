// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bev_msgs:msg/Bbox.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__BBOX__TRAITS_HPP_
#define BEV_MSGS__MSG__DETAIL__BBOX__TRAITS_HPP_

#include "bev_msgs/msg/detail/bbox__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bev_msgs::msg::Bbox>()
{
  return "bev_msgs::msg::Bbox";
}

template<>
inline const char * name<bev_msgs::msg::Bbox>()
{
  return "bev_msgs/msg/Bbox";
}

template<>
struct has_fixed_size<bev_msgs::msg::Bbox>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<bev_msgs::msg::Bbox>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<bev_msgs::msg::Bbox>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BEV_MSGS__MSG__DETAIL__BBOX__TRAITS_HPP_
