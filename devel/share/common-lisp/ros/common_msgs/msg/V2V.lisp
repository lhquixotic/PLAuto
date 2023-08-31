; Auto-generated. Do not edit!


(cl:in-package common_msgs-msg)


;//! \htmlinclude V2V.msg.html

(cl:defclass <V2V> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (platoon_info
    :reader platoon_info
    :initarg :platoon_info
    :type common_msgs-msg:PlatoonState
    :initform (cl:make-instance 'common_msgs-msg:PlatoonState)))
)

(cl:defclass V2V (<V2V>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <V2V>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'V2V)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common_msgs-msg:<V2V> is deprecated: use common_msgs-msg:V2V instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <V2V>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:header-val is deprecated.  Use common_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'platoon_info-val :lambda-list '(m))
(cl:defmethod platoon_info-val ((m <V2V>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:platoon_info-val is deprecated.  Use common_msgs-msg:platoon_info instead.")
  (platoon_info m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <V2V>) ostream)
  "Serializes a message object of type '<V2V>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'platoon_info) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <V2V>) istream)
  "Deserializes a message object of type '<V2V>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'platoon_info) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<V2V>)))
  "Returns string type for a message object of type '<V2V>"
  "common_msgs/V2V")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'V2V)))
  "Returns string type for a message object of type 'V2V"
  "common_msgs/V2V")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<V2V>)))
  "Returns md5sum for a message object of type '<V2V>"
  "2d31987bd7161fdc80da619674546dd0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'V2V)))
  "Returns md5sum for a message object of type 'V2V"
  "2d31987bd7161fdc80da619674546dd0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<V2V>)))
  "Returns full string definition for message of type '<V2V>"
  (cl:format cl:nil "std_msgs/Header header~%~%common_msgs/PlatoonState platoon_info~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: common_msgs/PlatoonState~%std_msgs/Header header~%~%# member vehicle state~%common_msgs/VehicleState[] vehicles~%================================================================================~%MSG: common_msgs/VehicleState~%# Id of the vehicle~%std_msgs/Header header ~%~%# Unique indentity of the vehicle~%uint64 uid~%~%# Basic info of the vehicle~%~%# Odometry info of the vehicle~%nav_msgs/Odometry odom~%~%# Dynamic state of vehicle~%common_msgs/VehicleDynamicState dynamics~%~%# Chassis state of vehicle~%common_msgs/ChassisState chassis~%~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: common_msgs/VehicleDynamicState~%std_msgs/Header  header~%~%float32 lon_speed~%float32 lon_accel~%float32 lat_speed~%float32 lat_accel~%float32 yaw_rate~%float32 yaw_accel~%================================================================================~%MSG: common_msgs/ChassisState~%std_msgs/Header header~%~%# real acc throttle value~%float32 throttle~%~%# real brake pressure~%float32 brake~%~%# vehicle run mode~%uint8 run_mode~%~%# Level of accelaration, unit in m/s^2, throttle is positive, braking is negative~%float32 accel~%~%# Level of steering on front wheel, unit in radian, left turning is positive~%float32 steer~%~%# Gear~%int8 gear~%~%# Parking~%bool parking_brake~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'V2V)))
  "Returns full string definition for message of type 'V2V"
  (cl:format cl:nil "std_msgs/Header header~%~%common_msgs/PlatoonState platoon_info~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: common_msgs/PlatoonState~%std_msgs/Header header~%~%# member vehicle state~%common_msgs/VehicleState[] vehicles~%================================================================================~%MSG: common_msgs/VehicleState~%# Id of the vehicle~%std_msgs/Header header ~%~%# Unique indentity of the vehicle~%uint64 uid~%~%# Basic info of the vehicle~%~%# Odometry info of the vehicle~%nav_msgs/Odometry odom~%~%# Dynamic state of vehicle~%common_msgs/VehicleDynamicState dynamics~%~%# Chassis state of vehicle~%common_msgs/ChassisState chassis~%~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: common_msgs/VehicleDynamicState~%std_msgs/Header  header~%~%float32 lon_speed~%float32 lon_accel~%float32 lat_speed~%float32 lat_accel~%float32 yaw_rate~%float32 yaw_accel~%================================================================================~%MSG: common_msgs/ChassisState~%std_msgs/Header header~%~%# real acc throttle value~%float32 throttle~%~%# real brake pressure~%float32 brake~%~%# vehicle run mode~%uint8 run_mode~%~%# Level of accelaration, unit in m/s^2, throttle is positive, braking is negative~%float32 accel~%~%# Level of steering on front wheel, unit in radian, left turning is positive~%float32 steer~%~%# Gear~%int8 gear~%~%# Parking~%bool parking_brake~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <V2V>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'platoon_info))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <V2V>))
  "Converts a ROS message object to a list"
  (cl:list 'V2V
    (cl:cons ':header (header msg))
    (cl:cons ':platoon_info (platoon_info msg))
))
