;; Auto-generated. Do not edit!


(when (boundp 'common_msgs::VehicleDynamicState)
  (if (not (find-package "COMMON_MSGS"))
    (make-package "COMMON_MSGS"))
  (shadow 'VehicleDynamicState (find-package "COMMON_MSGS")))
(unless (find-package "COMMON_MSGS::VEHICLEDYNAMICSTATE")
  (make-package "COMMON_MSGS::VEHICLEDYNAMICSTATE"))

(in-package "ROS")
;;//! \htmlinclude VehicleDynamicState.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass common_msgs::VehicleDynamicState
  :super ros::object
  :slots (_header _lon_speed _lon_acceleration _lat_speed _lat_acceleration _yaw_rate _yaw_acceleration ))

(defmethod common_msgs::VehicleDynamicState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:lon_speed __lon_speed) 0.0)
    ((:lon_acceleration __lon_acceleration) 0.0)
    ((:lat_speed __lat_speed) 0.0)
    ((:lat_acceleration __lat_acceleration) 0.0)
    ((:yaw_rate __yaw_rate) 0.0)
    ((:yaw_acceleration __yaw_acceleration) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _lon_speed (float __lon_speed))
   (setq _lon_acceleration (float __lon_acceleration))
   (setq _lat_speed (float __lat_speed))
   (setq _lat_acceleration (float __lat_acceleration))
   (setq _yaw_rate (float __yaw_rate))
   (setq _yaw_acceleration (float __yaw_acceleration))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:lon_speed
   (&optional __lon_speed)
   (if __lon_speed (setq _lon_speed __lon_speed)) _lon_speed)
  (:lon_acceleration
   (&optional __lon_acceleration)
   (if __lon_acceleration (setq _lon_acceleration __lon_acceleration)) _lon_acceleration)
  (:lat_speed
   (&optional __lat_speed)
   (if __lat_speed (setq _lat_speed __lat_speed)) _lat_speed)
  (:lat_acceleration
   (&optional __lat_acceleration)
   (if __lat_acceleration (setq _lat_acceleration __lat_acceleration)) _lat_acceleration)
  (:yaw_rate
   (&optional __yaw_rate)
   (if __yaw_rate (setq _yaw_rate __yaw_rate)) _yaw_rate)
  (:yaw_acceleration
   (&optional __yaw_acceleration)
   (if __yaw_acceleration (setq _yaw_acceleration __yaw_acceleration)) _yaw_acceleration)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _lon_speed
    8
    ;; float64 _lon_acceleration
    8
    ;; float64 _lat_speed
    8
    ;; float64 _lat_acceleration
    8
    ;; float64 _yaw_rate
    8
    ;; float64 _yaw_acceleration
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _lon_speed
       (sys::poke _lon_speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _lon_acceleration
       (sys::poke _lon_acceleration (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _lat_speed
       (sys::poke _lat_speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _lat_acceleration
       (sys::poke _lat_acceleration (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw_rate
       (sys::poke _yaw_rate (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw_acceleration
       (sys::poke _yaw_acceleration (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _lon_speed
     (setq _lon_speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _lon_acceleration
     (setq _lon_acceleration (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _lat_speed
     (setq _lat_speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _lat_acceleration
     (setq _lat_acceleration (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw_rate
     (setq _yaw_rate (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw_acceleration
     (setq _yaw_acceleration (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get common_msgs::VehicleDynamicState :md5sum-) "543c8cc51ef4a96b419de72eeff8a6e9")
(setf (get common_msgs::VehicleDynamicState :datatype-) "common_msgs/VehicleDynamicState")
(setf (get common_msgs::VehicleDynamicState :definition-)
      "std_msgs/Header  header

float64 lon_speed
float64 lon_acceleration
float64 lat_speed
float64 lat_acceleration
float64 yaw_rate
float64 yaw_acceleration
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

")



(provide :common_msgs/VehicleDynamicState "543c8cc51ef4a96b419de72eeff8a6e9")


