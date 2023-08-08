// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bev_msgs:msg/Bbox.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__BBOX__BUILDER_HPP_
#define BEV_MSGS__MSG__DETAIL__BBOX__BUILDER_HPP_

#include "bev_msgs/msg/detail/bbox__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace bev_msgs
{

namespace msg
{

namespace builder
{

class Init_Bbox_yaw
{
public:
  explicit Init_Bbox_yaw(::bev_msgs::msg::Bbox & msg)
  : msg_(msg)
  {}
  ::bev_msgs::msg::Bbox yaw(::bev_msgs::msg::Bbox::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bev_msgs::msg::Bbox msg_;
};

class Init_Bbox_height
{
public:
  explicit Init_Bbox_height(::bev_msgs::msg::Bbox & msg)
  : msg_(msg)
  {}
  Init_Bbox_yaw height(::bev_msgs::msg::Bbox::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_Bbox_yaw(msg_);
  }

private:
  ::bev_msgs::msg::Bbox msg_;
};

class Init_Bbox_length
{
public:
  explicit Init_Bbox_length(::bev_msgs::msg::Bbox & msg)
  : msg_(msg)
  {}
  Init_Bbox_height length(::bev_msgs::msg::Bbox::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_Bbox_height(msg_);
  }

private:
  ::bev_msgs::msg::Bbox msg_;
};

class Init_Bbox_width
{
public:
  explicit Init_Bbox_width(::bev_msgs::msg::Bbox & msg)
  : msg_(msg)
  {}
  Init_Bbox_length width(::bev_msgs::msg::Bbox::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_Bbox_length(msg_);
  }

private:
  ::bev_msgs::msg::Bbox msg_;
};

class Init_Bbox_pos_y
{
public:
  explicit Init_Bbox_pos_y(::bev_msgs::msg::Bbox & msg)
  : msg_(msg)
  {}
  Init_Bbox_width pos_y(::bev_msgs::msg::Bbox::_pos_y_type arg)
  {
    msg_.pos_y = std::move(arg);
    return Init_Bbox_width(msg_);
  }

private:
  ::bev_msgs::msg::Bbox msg_;
};

class Init_Bbox_pos_x
{
public:
  Init_Bbox_pos_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bbox_pos_y pos_x(::bev_msgs::msg::Bbox::_pos_x_type arg)
  {
    msg_.pos_x = std::move(arg);
    return Init_Bbox_pos_y(msg_);
  }

private:
  ::bev_msgs::msg::Bbox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bev_msgs::msg::Bbox>()
{
  return bev_msgs::msg::builder::Init_Bbox_pos_x();
}

}  // namespace bev_msgs

#endif  // BEV_MSGS__MSG__DETAIL__BBOX__BUILDER_HPP_
