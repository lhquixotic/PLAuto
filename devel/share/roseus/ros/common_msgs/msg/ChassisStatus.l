;; Auto-generated. Do not edit!


(when (boundp 'common_msgs::ChassisStatus)
  (if (not (find-package "COMMON_MSGS"))
    (make-package "COMMON_MSGS"))
  (shadow 'ChassisStatus (find-package "COMMON_MSGS")))
(unless (find-package "COMMON_MSGS::CHASSISSTATUS")
  (make-package "COMMON_MSGS::CHASSISSTATUS"))

(in-package "ROS")
;;//! \htmlinclude ChassisStatus.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass common_msgs::ChassisStatus
  :super ros::object
  :slots (_header _real_throttle _real_brake_pressure _real_steer_angle _vehicle_run_mode ))

(defmethod common_msgs::ChassisStatus
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:real_throttle __real_throttle) 0)
    ((:real_brake_pressure __real_brake_pressure) 0)
    ((:real_steer_angle __real_steer_angle) 0.0)
    ((:vehicle_run_mode __vehicle_run_mode) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _real_throttle (round __real_throttle))
   (setq _real_brake_pressure (round __real_brake_pressure))
   (setq _real_steer_angle (float __real_steer_angle))
   (setq _vehicle_run_mode (round __vehicle_run_mode))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:real_throttle
   (&optional __real_throttle)
   (if __real_throttle (setq _real_throttle __real_throttle)) _real_throttle)
  (:real_brake_pressure
   (&optional __real_brake_pressure)
   (if __real_brake_pressure (setq _real_brake_pressure __real_brake_pressure)) _real_brake_pressure)
  (:real_steer_angle
   (&optional __real_steer_angle)
   (if __real_steer_angle (setq _real_steer_angle __real_steer_angle)) _real_steer_angle)
  (:vehicle_run_mode
   (&optional __vehicle_run_mode)
   (if __vehicle_run_mode (setq _vehicle_run_mode __vehicle_run_mode)) _vehicle_run_mode)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _real_throttle
    1
    ;; uint8 _real_brake_pressure
    1
    ;; float64 _real_steer_angle
    8
    ;; uint8 _vehicle_run_mode
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _real_throttle
       (write-byte _real_throttle s)
     ;; uint8 _real_brake_pressure
       (write-byte _real_brake_pressure s)
     ;; float64 _real_steer_angle
       (sys::poke _real_steer_angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint8 _vehicle_run_mode
       (write-byte _vehicle_run_mode s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _real_throttle
     (setq _real_throttle (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _real_brake_pressure
     (setq _real_brake_pressure (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _real_steer_angle
     (setq _real_steer_angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint8 _vehicle_run_mode
     (setq _vehicle_run_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get common_msgs::ChassisStatus :md5sum-) "3318ade59e28d0d24b09394333e12cbc")
(setf (get common_msgs::ChassisStatus :datatype-) "common_msgs/ChassisStatus")
(setf (get common_msgs::ChassisStatus :definition-)
      "std_msgs/Header header

# real acc throttle value
uint8 real_throttle

# real brake pressure
uint8 real_brake_pressure

# real steer angle
float64 real_steer_angle

# vehicle run mode
uint8 vehicle_run_mode
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



(provide :common_msgs/ChassisStatus "3318ade59e28d0d24b09394333e12cbc")


