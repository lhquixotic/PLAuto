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
  :slots (_header _lon_speed _lon_accel _lat_speed _lat_accel _yaw_rate _yaw_accel ))

(defmethod common_msgs::VehicleDynamicState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:lon_speed __lon_speed) 0.0)
    ((:lon_accel __lon_accel) 0.0)
    ((:lat_speed __lat_speed) 0.0)
    ((:lat_accel __lat_accel) 0.0)
    ((:yaw_rate __yaw_rate) 0.0)
    ((:yaw_accel __yaw_accel) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _lon_speed (float __lon_speed))
   (setq _lon_accel (float __lon_accel))
   (setq _lat_speed (float __lat_speed))
   (setq _lat_accel (float __lat_accel))
   (setq _yaw_rate (float __yaw_rate))
   (setq _yaw_accel (float __yaw_accel))
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
  (:lon_accel
   (&optional __lon_accel)
   (if __lon_accel (setq _lon_accel __lon_accel)) _lon_accel)
  (:lat_speed
   (&optional __lat_speed)
   (if __lat_speed (setq _lat_speed __lat_speed)) _lat_speed)
  (:lat_accel
   (&optional __lat_accel)
   (if __lat_accel (setq _lat_accel __lat_accel)) _lat_accel)
  (:yaw_rate
   (&optional __yaw_rate)
   (if __yaw_rate (setq _yaw_rate __yaw_rate)) _yaw_rate)
  (:yaw_accel
   (&optional __yaw_accel)
   (if __yaw_accel (setq _yaw_accel __yaw_accel)) _yaw_accel)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _lon_speed
    4
    ;; float32 _lon_accel
    4
    ;; float32 _lat_speed
    4
    ;; float32 _lat_accel
    4
    ;; float32 _yaw_rate
    4
    ;; float32 _yaw_accel
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _lon_speed
       (sys::poke _lon_speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _lon_accel
       (sys::poke _lon_accel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _lat_speed
       (sys::poke _lat_speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _lat_accel
       (sys::poke _lat_accel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _yaw_rate
       (sys::poke _yaw_rate (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _yaw_accel
       (sys::poke _yaw_accel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _lon_speed
     (setq _lon_speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _lon_accel
     (setq _lon_accel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _lat_speed
     (setq _lat_speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _lat_accel
     (setq _lat_accel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _yaw_rate
     (setq _yaw_rate (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _yaw_accel
     (setq _yaw_accel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get common_msgs::VehicleDynamicState :md5sum-) "d3015605eb810e5c79a5de962cc9f172")
(setf (get common_msgs::VehicleDynamicState :datatype-) "common_msgs/VehicleDynamicState")
(setf (get common_msgs::VehicleDynamicState :definition-)
      "std_msgs/Header  header

float32 lon_speed
float32 lon_accel
float32 lat_speed
float32 lat_accel
float32 yaw_rate
float32 yaw_accel
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



(provide :common_msgs/VehicleDynamicState "d3015605eb810e5c79a5de962cc9f172")


