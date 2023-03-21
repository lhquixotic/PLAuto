// Generated by gencpp from file common_msgs/StopDecision.msg
// DO NOT EDIT!


#ifndef COMMON_MSGS_MESSAGE_STOPDECISION_H
#define COMMON_MSGS_MESSAGE_STOPDECISION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace common_msgs
{
template <class ContainerAllocator>
struct StopDecision_
{
  typedef StopDecision_<ContainerAllocator> Type;

  StopDecision_()
    : header()
    , veh_stop_flag(0)  {
    }
  StopDecision_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , veh_stop_flag(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _veh_stop_flag_type;
  _veh_stop_flag_type veh_stop_flag;





  typedef boost::shared_ptr< ::common_msgs::StopDecision_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::common_msgs::StopDecision_<ContainerAllocator> const> ConstPtr;

}; // struct StopDecision_

typedef ::common_msgs::StopDecision_<std::allocator<void> > StopDecision;

typedef boost::shared_ptr< ::common_msgs::StopDecision > StopDecisionPtr;
typedef boost::shared_ptr< ::common_msgs::StopDecision const> StopDecisionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::common_msgs::StopDecision_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::common_msgs::StopDecision_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::common_msgs::StopDecision_<ContainerAllocator1> & lhs, const ::common_msgs::StopDecision_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.veh_stop_flag == rhs.veh_stop_flag;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::common_msgs::StopDecision_<ContainerAllocator1> & lhs, const ::common_msgs::StopDecision_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace common_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::common_msgs::StopDecision_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::common_msgs::StopDecision_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::common_msgs::StopDecision_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::common_msgs::StopDecision_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common_msgs::StopDecision_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common_msgs::StopDecision_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::common_msgs::StopDecision_<ContainerAllocator> >
{
  static const char* value()
  {
    return "40185f333e9db25a8a2ac70bc6903e53";
  }

  static const char* value(const ::common_msgs::StopDecision_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x40185f333e9db25aULL;
  static const uint64_t static_value2 = 0x8a2ac70bc6903e53ULL;
};

template<class ContainerAllocator>
struct DataType< ::common_msgs::StopDecision_<ContainerAllocator> >
{
  static const char* value()
  {
    return "common_msgs/StopDecision";
  }

  static const char* value(const ::common_msgs::StopDecision_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::common_msgs::StopDecision_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"int32 veh_stop_flag\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::common_msgs::StopDecision_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::common_msgs::StopDecision_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.veh_stop_flag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct StopDecision_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::common_msgs::StopDecision_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::common_msgs::StopDecision_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "veh_stop_flag: ";
    Printer<int32_t>::stream(s, indent + "  ", v.veh_stop_flag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMON_MSGS_MESSAGE_STOPDECISION_H