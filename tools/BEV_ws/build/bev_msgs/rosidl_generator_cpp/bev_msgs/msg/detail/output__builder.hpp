// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bev_msgs:msg/Output.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__OUTPUT__BUILDER_HPP_
#define BEV_MSGS__MSG__DETAIL__OUTPUT__BUILDER_HPP_

#include "bev_msgs/msg/detail/output__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace bev_msgs
{

namespace msg
{

namespace builder
{

class Init_Output_box
{
public:
  explicit Init_Output_box(::bev_msgs::msg::Output & msg)
  : msg_(msg)
  {}
  ::bev_msgs::msg::Output box(::bev_msgs::msg::Output::_box_type arg)
  {
    msg_.box = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bev_msgs::msg::Output msg_;
};

class Init_Output_label
{
public:
  explicit Init_Output_label(::bev_msgs::msg::Output & msg)
  : msg_(msg)
  {}
  Init_Output_box label(::bev_msgs::msg::Output::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Output_box(msg_);
  }

private:
  ::bev_msgs::msg::Output msg_;
};

class Init_Output_score
{
public:
  explicit Init_Output_score(::bev_msgs::msg::Output & msg)
  : msg_(msg)
  {}
  Init_Output_label score(::bev_msgs::msg::Output::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_Output_label(msg_);
  }

private:
  ::bev_msgs::msg::Output msg_;
};

class Init_Output_id
{
public:
  Init_Output_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Output_score id(::bev_msgs::msg::Output::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Output_score(msg_);
  }

private:
  ::bev_msgs::msg::Output msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bev_msgs::msg::Output>()
{
  return bev_msgs::msg::builder::Init_Output_id();
}

}  // namespace bev_msgs

#endif  // BEV_MSGS__MSG__DETAIL__OUTPUT__BUILDER_HPP_
