// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bev_msgs:msg/OutputArray.idl
// generated code does not contain a copyright notice

#ifndef BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__STRUCT_HPP_
#define BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'outputs'
#include "bev_msgs/msg/detail/output__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__bev_msgs__msg__OutputArray __attribute__((deprecated))
#else
# define DEPRECATED__bev_msgs__msg__OutputArray __declspec(deprecated)
#endif

namespace bev_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OutputArray_
{
  using Type = OutputArray_<ContainerAllocator>;

  explicit OutputArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit OutputArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _outputs_type =
    std::vector<bev_msgs::msg::Output_<ContainerAllocator>, typename ContainerAllocator::template rebind<bev_msgs::msg::Output_<ContainerAllocator>>::other>;
  _outputs_type outputs;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__outputs(
    const std::vector<bev_msgs::msg::Output_<ContainerAllocator>, typename ContainerAllocator::template rebind<bev_msgs::msg::Output_<ContainerAllocator>>::other> & _arg)
  {
    this->outputs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bev_msgs::msg::OutputArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const bev_msgs::msg::OutputArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bev_msgs::msg::OutputArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bev_msgs::msg::OutputArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bev_msgs::msg::OutputArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bev_msgs::msg::OutputArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bev_msgs::msg::OutputArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bev_msgs::msg::OutputArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bev_msgs::msg::OutputArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bev_msgs::msg::OutputArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bev_msgs__msg__OutputArray
    std::shared_ptr<bev_msgs::msg::OutputArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bev_msgs__msg__OutputArray
    std::shared_ptr<bev_msgs::msg::OutputArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OutputArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->outputs != other.outputs) {
      return false;
    }
    return true;
  }
  bool operator!=(const OutputArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OutputArray_

// alias to use template instance with default allocator
using OutputArray =
  bev_msgs::msg::OutputArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace bev_msgs

#endif  // BEV_MSGS__MSG__DETAIL__OUTPUT_ARRAY__STRUCT_HPP_
