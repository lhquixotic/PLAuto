// Generated by gencpp from file autoware_msgs/ImageRectRanged.msg
// DO NOT EDIT!


#ifndef AUTOWARE_MSGS_MESSAGE_IMAGERECTRANGED_H
#define AUTOWARE_MSGS_MESSAGE_IMAGERECTRANGED_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <autoware_msgs/ImageRect.h>

namespace autoware_msgs
{
template <class ContainerAllocator>
struct ImageRectRanged_
{
  typedef ImageRectRanged_<ContainerAllocator> Type;

  ImageRectRanged_()
    : rect()
    , range(0.0)
    , min_height(0.0)
    , max_height(0.0)  {
    }
  ImageRectRanged_(const ContainerAllocator& _alloc)
    : rect(_alloc)
    , range(0.0)
    , min_height(0.0)
    , max_height(0.0)  {
  (void)_alloc;
    }



   typedef  ::autoware_msgs::ImageRect_<ContainerAllocator>  _rect_type;
  _rect_type rect;

   typedef float _range_type;
  _range_type range;

   typedef float _min_height_type;
  _min_height_type min_height;

   typedef float _max_height_type;
  _max_height_type max_height;





  typedef boost::shared_ptr< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> const> ConstPtr;

}; // struct ImageRectRanged_

typedef ::autoware_msgs::ImageRectRanged_<std::allocator<void> > ImageRectRanged;

typedef boost::shared_ptr< ::autoware_msgs::ImageRectRanged > ImageRectRangedPtr;
typedef boost::shared_ptr< ::autoware_msgs::ImageRectRanged const> ImageRectRangedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::autoware_msgs::ImageRectRanged_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::autoware_msgs::ImageRectRanged_<ContainerAllocator1> & lhs, const ::autoware_msgs::ImageRectRanged_<ContainerAllocator2> & rhs)
{
  return lhs.rect == rhs.rect &&
    lhs.range == rhs.range &&
    lhs.min_height == rhs.min_height &&
    lhs.max_height == rhs.max_height;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::autoware_msgs::ImageRectRanged_<ContainerAllocator1> & lhs, const ::autoware_msgs::ImageRectRanged_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace autoware_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3781b4778925185f71f990932766044c";
  }

  static const char* value(const ::autoware_msgs::ImageRectRanged_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3781b4778925185fULL;
  static const uint64_t static_value2 = 0x71f990932766044cULL;
};

template<class ContainerAllocator>
struct DataType< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> >
{
  static const char* value()
  {
    return "autoware_msgs/ImageRectRanged";
  }

  static const char* value(const ::autoware_msgs::ImageRectRanged_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ImageRect rect\n"
"float32 range\n"
"float32 min_height\n"
"float32 max_height\n"
"\n"
"================================================================================\n"
"MSG: autoware_msgs/ImageRect\n"
"int32 x\n"
"int32 y\n"
"int32 height\n"
"int32 width\n"
"float32 score\n"
;
  }

  static const char* value(const ::autoware_msgs::ImageRectRanged_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.rect);
      stream.next(m.range);
      stream.next(m.min_height);
      stream.next(m.max_height);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ImageRectRanged_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::autoware_msgs::ImageRectRanged_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::autoware_msgs::ImageRectRanged_<ContainerAllocator>& v)
  {
    s << indent << "rect: ";
    s << std::endl;
    Printer< ::autoware_msgs::ImageRect_<ContainerAllocator> >::stream(s, indent + "  ", v.rect);
    s << indent << "range: ";
    Printer<float>::stream(s, indent + "  ", v.range);
    s << indent << "min_height: ";
    Printer<float>::stream(s, indent + "  ", v.min_height);
    s << indent << "max_height: ";
    Printer<float>::stream(s, indent + "  ", v.max_height);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUTOWARE_MSGS_MESSAGE_IMAGERECTRANGED_H
