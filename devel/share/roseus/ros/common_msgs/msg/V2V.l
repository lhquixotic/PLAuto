;; Auto-generated. Do not edit!


(when (boundp 'common_msgs::V2V)
  (if (not (find-package "COMMON_MSGS"))
    (make-package "COMMON_MSGS"))
  (shadow 'V2V (find-package "COMMON_MSGS")))
(unless (find-package "COMMON_MSGS::V2V")
  (make-package "COMMON_MSGS::V2V"))

(in-package "ROS")
;;//! \htmlinclude V2V.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass common_msgs::V2V
  :super ros::object
  :slots (_header _platoon_info ))

(defmethod common_msgs::V2V
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:platoon_info __platoon_info) (instance common_msgs::PlatoonState :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _platoon_info __platoon_info)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:platoon_info
   (&rest __platoon_info)
   (if (keywordp (car __platoon_info))
       (send* _platoon_info __platoon_info)
     (progn
       (if __platoon_info (setq _platoon_info (car __platoon_info)))
       _platoon_info)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; common_msgs/PlatoonState _platoon_info
    (send _platoon_info :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; common_msgs/PlatoonState _platoon_info
       (send _platoon_info :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; common_msgs/PlatoonState _platoon_info
     (send _platoon_info :deserialize buf ptr-) (incf ptr- (send _platoon_info :serialization-length))
   ;;
   self)
  )

(setf (get common_msgs::V2V :md5sum-) "84dd78ba72f6eb4041f0491a6158eda6")
(setf (get common_msgs::V2V :datatype-) "common_msgs/V2V")
(setf (get common_msgs::V2V :definition-)
      "std_msgs/Header header

common_msgs/PlatoonState platoon_info

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: common_msgs/PlatoonState
std_msgs/Header header

# member vehicle state
common_msgs/VehicleState[] vehicles
================================================================================
MSG: common_msgs/VehicleState
# Id of the vehicle
std_msgs/Header header 

# Basic info of the vehicle

# Odometry info of the vehicle
nav_msgs/Odometry odom

# Dynamic state of vehicle
common_msgs/VehicleDynamicState dynamics

# Chassis state of vehicle
common_msgs/ChassisState chassis

================================================================================
MSG: nav_msgs/Odometry
# This represents an estimate of a position and velocity in free space.  
# The pose in this message should be specified in the coordinate frame given by header.frame_id.
# The twist in this message should be specified in the coordinate frame given by the child_frame_id
Header header
string child_frame_id
geometry_msgs/PoseWithCovariance pose
geometry_msgs/TwistWithCovariance twist

================================================================================
MSG: geometry_msgs/PoseWithCovariance
# This represents a pose in free space with uncertainty.

Pose pose

# Row-major representation of the 6x6 covariance matrix
# The orientation parameters use a fixed-axis representation.
# In order, the parameters are:
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
float64[36] covariance

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/TwistWithCovariance
# This expresses velocity in free space with uncertainty.

Twist twist

# Row-major representation of the 6x6 covariance matrix
# The orientation parameters use a fixed-axis representation.
# In order, the parameters are:
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
float64[36] covariance

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: common_msgs/VehicleDynamicState
std_msgs/Header  header

float32 lon_speed
float32 lon_accel
float32 lat_speed
float32 lat_accel
float32 yaw_rate
float32 yaw_accel
================================================================================
MSG: common_msgs/ChassisState
std_msgs/Header header

# real acc throttle value
float32 throttle

# real brake pressure
float32 brake

# vehicle run mode
uint8 run_mode

# Level of accelaration, unit in m/s^2, throttle is positive, braking is negative
float32 accel

# Level of steering on front wheel, unit in radian, left turning is positive
float32 steer

# Gear
int8 gear

# Parking
bool parking_brake




")



(provide :common_msgs/V2V "84dd78ba72f6eb4041f0491a6158eda6")


