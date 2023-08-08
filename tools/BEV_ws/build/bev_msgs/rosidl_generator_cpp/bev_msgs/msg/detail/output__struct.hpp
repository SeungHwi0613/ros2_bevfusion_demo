// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bev_msgs:msg/Output.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__OUTPUT__STRUCT_HPP_
#define BEV_MSGS__MSG__DETAIL__OUTPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'box'
#include "bev_msgs/msg/detail/bbox__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__bev_msgs__msg__Output __attribute__((deprecated))
#else
# define DEPRECATED__bev_msgs__msg__Output __declspec(deprecated)
#endif

namespace bev_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Output_
{
  using Type = Output_<ContainerAllocator>;

  explicit Output_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : box(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->score = 0.0;
      this->label = 0ll;
    }
  }

  explicit Output_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : box(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->score = 0.0;
      this->label = 0ll;
    }
  }

  // field types and members
  using _id_type =
    int64_t;
  _id_type id;
  using _score_type =
    double;
  _score_type score;
  using _label_type =
    int64_t;
  _label_type label;
  using _box_type =
    bev_msgs::msg::Bbox_<ContainerAllocator>;
  _box_type box;

  // setters for named parameter idiom
  Type & set__id(
    const int64_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__score(
    const double & _arg)
  {
    this->score = _arg;
    return *this;
  }
  Type & set__label(
    const int64_t & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__box(
    const bev_msgs::msg::Bbox_<ContainerAllocator> & _arg)
  {
    this->box = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bev_msgs::msg::Output_<ContainerAllocator> *;
  using ConstRawPtr =
    const bev_msgs::msg::Output_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bev_msgs::msg::Output_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bev_msgs::msg::Output_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bev_msgs::msg::Output_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bev_msgs::msg::Output_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bev_msgs::msg::Output_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bev_msgs::msg::Output_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bev_msgs::msg::Output_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bev_msgs::msg::Output_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bev_msgs__msg__Output
    std::shared_ptr<bev_msgs::msg::Output_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bev_msgs__msg__Output
    std::shared_ptr<bev_msgs::msg::Output_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Output_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->score != other.score) {
      return false;
    }
    if (this->label != other.label) {
      return false;
    }
    if (this->box != other.box) {
      return false;
    }
    return true;
  }
  bool operator!=(const Output_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Output_

// alias to use template instance with default allocator
using Output =
  bev_msgs::msg::Output_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bev_msgs

#endif  // BEV_MSGS__MSG__DETAIL__OUTPUT__STRUCT_HPP_
