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
  :slots (_header _vehicle_speed _vehicle_lon_acceleration ))

(defmethod common_msgs::VehicleDynamicState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:vehicle_speed __vehicle_speed) 0.0)
    ((:vehicle_lon_acceleration __vehicle_lon_acceleration) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _vehicle_speed (float __vehicle_speed))
   (setq _vehicle_lon_acceleration (float __vehicle_lon_acceleration))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:vehicle_speed
   (&optional __vehicle_speed)
   (if __vehicle_speed (setq _vehicle_speed __vehicle_speed)) _vehicle_speed)
  (:vehicle_lon_acceleration
   (&optional __vehicle_lon_acceleration)
   (if __vehicle_lon_acceleration (setq _vehicle_lon_acceleration __vehicle_lon_acceleration)) _vehicle_lon_acceleration)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _vehicle_speed
    8
    ;; float64 _vehicle_lon_acceleration
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _vehicle_speed
       (sys::poke _vehicle_speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vehicle_lon_acceleration
       (sys::poke _vehicle_lon_acceleration (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _vehicle_speed
     (setq _vehicle_speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vehicle_lon_acceleration
     (setq _vehicle_lon_acceleration (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get common_msgs::VehicleDynamicState :md5sum-) "156d2fe6b2b7a496f295863b8c3741b1")
(setf (get common_msgs::VehicleDynamicState :datatype-) "common_msgs/VehicleDynamicState")
(setf (get common_msgs::VehicleDynamicState :definition-)
      "std_msgs/Header  header
float64 vehicle_speed
float64 vehicle_lon_acceleration
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



(provide :common_msgs/VehicleDynamicState "156d2fe6b2b7a496f295863b8c3741b1")


