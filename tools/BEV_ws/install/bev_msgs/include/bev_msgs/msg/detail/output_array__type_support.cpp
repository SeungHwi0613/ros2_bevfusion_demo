// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from bev_msgs:msg/OutputArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "bev_msgs/msg/detail/output_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace bev_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void OutputArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) bev_msgs::msg::OutputArray(_init);
}

void OutputArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<bev_msgs::msg::OutputArray *>(message_memory);
  typed_message->~OutputArray();
}

size_t size_function__OutputArray__outputs(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<bev_msgs::msg::Output> *>(untyped_member);
  return member->size();
}

const void * get_const_function__OutputArray__outputs(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<bev_msgs::msg::Output> *>(untyped_member);
  return &member[index];
}

void * get_function__OutputArray__outputs(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<bev_msgs::msg::Output> *>(untyped_member);
  return &member[index];
}

void resize_function__OutputArray__outputs(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<bev_msgs::msg::Output> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember OutputArray_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs::msg::OutputArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "outputs",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<bev_msgs::msg::Output>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bev_msgs::msg::OutputArray, outputs),  // bytes offset in struct
    nullptr,  // default value
    size_function__OutputArray__outputs,  // size() function pointer
    get_const_function__OutputArray__outputs,  // get_const(index) function pointer
    get_function__OutputArray__outputs,  // get(index) function pointer
    resize_function__OutputArray__outputs  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers OutputArray_message_members = {
  "bev_msgs::msg",  // message namespace
  "OutputArray",  // message name
  2,  // number of fields
  sizeof(bev_msgs::msg::OutputArray),
  OutputArray_message_member_array,  // message members
  OutputArray_init_function,  // function to initialize message memory (memory has to be allocated)
  OutputArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t OutputArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &OutputArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace bev_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<bev_msgs::msg::OutputArray>()
{
  return &::bev_msgs::msg::rosidl_typesupport_introspection_cpp::OutputArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, bev_msgs, msg, OutputArray)() {
  return &::bev_msgs::msg::rosidl_typesupport_introspection_cpp::OutputArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
