// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bev_msgs:msg/Bbox.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__BBOX__STRUCT_HPP_
#define BEV_MSGS__MSG__DETAIL__BBOX__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__bev_msgs__msg__Bbox __attribute__((deprecated))
#else
# define DEPRECATED__bev_msgs__msg__Bbox __declspec(deprecated)
#endif

namespace bev_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Bbox_
{
  using Type = Bbox_<ContainerAllocator>;

  explicit Bbox_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos_x = 0.0;
      this->pos_y = 0.0;
      this->width = 0.0;
      this->length = 0.0;
      this->height = 0.0;
      this->yaw = 0.0;
    }
  }

  explicit Bbox_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos_x = 0.0;
      this->pos_y = 0.0;
      this->width = 0.0;
      this->length = 0.0;
      this->height = 0.0;
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _pos_x_type =
    double;
  _pos_x_type pos_x;
  using _pos_y_type =
    double;
  _pos_y_type pos_y;
  using _width_type =
    double;
  _width_type width;
  using _length_type =
    double;
  _length_type length;
  using _height_type =
    double;
  _height_type height;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__pos_x(
    const double & _arg)
  {
    this->pos_x = _arg;
    return *this;
  }
  Type & set__pos_y(
    const double & _arg)
  {
    this->pos_y = _arg;
    return *this;
  }
  Type & set__width(
    const double & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__length(
    const double & _arg)
  {
    this->length = _arg;
    return *this;
  }
  Type & set__height(
    const double & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bev_msgs::msg::Bbox_<ContainerAllocator> *;
  using ConstRawPtr =
    const bev_msgs::msg::Bbox_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bev_msgs::msg::Bbox_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bev_msgs::msg::Bbox_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bev_msgs::msg::Bbox_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bev_msgs::msg::Bbox_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bev_msgs::msg::Bbox_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bev_msgs::msg::Bbox_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bev_msgs::msg::Bbox_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bev_msgs::msg::Bbox_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bev_msgs__msg__Bbox
    std::shared_ptr<bev_msgs::msg::Bbox_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bev_msgs__msg__Bbox
    std::shared_ptr<bev_msgs::msg::Bbox_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Bbox_ & other) const
  {
    if (this->pos_x != other.pos_x) {
      return false;
    }
    if (this->pos_y != other.pos_y) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const Bbox_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Bbox_

// alias to use template instance with default allocator
using Bbox =
  bev_msgs::msg::Bbox_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bev_msgs

#endif  // BEV_MSGS__MSG__DETAIL__BBOX__STRUCT_HPP_
