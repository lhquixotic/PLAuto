;; Auto-generated. Do not edit!


(when (boundp 'common_msgs::V2V)
  (if (not (find-package "COMMON_MSGS"))
    (make-package "COMMON_MSGS"))
  (shadow 'V2V (find-package "COMMON_MSGS")))
(unless (find-package "COMMON_MSGS::V2V")
  (make-package "COMMON_MSGS::V2V"))

(in-package "ROS")
;;//! \htmlinclude V2V.msg.html
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass common_msgs::V2V
  :super ros::object
  :slots (_header _odom _leader_speed _leader_acc _leader_acc_pedal _leader_brake_pedal _leader_frontwheel_angle ))

(defmethod common_msgs::V2V
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:odom __odom) (instance nav_msgs::Odometry :init))
    ((:leader_speed __leader_speed) 0.0)
    ((:leader_acc __leader_acc) 0.0)
    ((:leader_acc_pedal __leader_acc_pedal) 0.0)
    ((:leader_brake_pedal __leader_brake_pedal) 0.0)
    ((:leader_frontwheel_angle __leader_frontwheel_angle) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _odom __odom)
   (setq _leader_speed (float __leader_speed))
   (setq _leader_acc (float __leader_acc))
   (setq _leader_acc_pedal (float __leader_acc_pedal))
   (setq _leader_brake_pedal (float __leader_brake_pedal))
   (setq _leader_frontwheel_angle (float __leader_frontwheel_angle))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:odom
   (&rest __odom)
   (if (keywordp (car __odom))
       (send* _odom __odom)
     (progn
       (if __odom (setq _odom (car __odom)))
       _odom)))
  (:leader_speed
   (&optional __leader_speed)
   (if __leader_speed (setq _leader_speed __leader_speed)) _leader_speed)
  (:leader_acc
   (&optional __leader_acc)
   (if __leader_acc (setq _leader_acc __leader_acc)) _leader_acc)
  (:leader_acc_pedal
   (&optional __leader_acc_pedal)
   (if __leader_acc_pedal (setq _leader_acc_pedal __leader_acc_pedal)) _leader_acc_pedal)
  (:leader_brake_pedal
   (&optional __leader_brake_pedal)
   (if __leader_brake_pedal (setq _leader_brake_pedal __leader_brake_pedal)) _leader_brake_pedal)
  (:leader_frontwheel_angle
   (&optional __leader_frontwheel_angle)
   (if __leader_frontwheel_angle (setq _leader_frontwheel_angle __leader_frontwheel_angle)) _leader_frontwheel_angle)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; nav_msgs/Odometry _odom
    (send _odom :serialization-length)
    ;; float64 _leader_speed
    8
    ;; float64 _leader_acc
    8
    ;; float64 _leader_acc_pedal
    8
    ;; float64 _leader_brake_pedal
    8
    ;; float64 _leader_frontwheel_angle
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; nav_msgs/Odometry _odom
       (send _odom :serialize s)
     ;; float64 _leader_speed
       (sys::poke _leader_speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _leader_acc
       (sys::poke _leader_acc (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _leader_acc_pedal
       (sys::poke _leader_acc_pedal (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _leader_brake_pedal
       (sys::poke _leader_brake_pedal (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _leader_frontwheel_angle
       (sys::poke _leader_frontwheel_angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; nav_msgs/Odometry _odom
     (send _odom :deserialize buf ptr-) (incf ptr- (send _odom :serialization-length))
   ;; float64 _leader_speed
     (setq _leader_speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _leader_acc
     (setq _leader_acc (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _leader_acc_pedal
     (setq _leader_acc_pedal (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _leader_brake_pedal
     (setq _leader_brake_pedal (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _leader_frontwheel_angle
     (setq _leader_frontwheel_angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get common_msgs::V2V :md5sum-) "5d3f3ce1d5d07abc8f4695c3e316dc23")
(setf (get common_msgs::V2V :datatype-) "common_msgs/V2V")
(setf (get common_msgs::V2V :definition-)
      "std_msgs/Header header
#gpsinfo
nav_msgs/Odometry odom
#leader info
float64 leader_speed
float64 leader_acc
float64 leader_acc_pedal
float64 leader_brake_pedal
float64 leader_frontwheel_angle

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
")



(provide :common_msgs/V2V "5d3f3ce1d5d07abc8f4695c3e316dc23")


