;; Auto-generated. Do not edit!


(when (boundp 'autoware_system_msgs::HardwareStatus)
  (if (not (find-package "AUTOWARE_SYSTEM_MSGS"))
    (make-package "AUTOWARE_SYSTEM_MSGS"))
  (shadow 'HardwareStatus (find-package "AUTOWARE_SYSTEM_MSGS")))
(unless (find-package "AUTOWARE_SYSTEM_MSGS::HARDWARESTATUS")
  (make-package "AUTOWARE_SYSTEM_MSGS::HARDWARESTATUS"))

(in-package "ROS")
;;//! \htmlinclude HardwareStatus.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass autoware_system_msgs::HardwareStatus
  :super ros::object
  :slots (_header _hardware_name _status ))

(defmethod autoware_system_msgs::HardwareStatus
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:hardware_name __hardware_name) "")
    ((:status __status) ())
    )
   (send-super :init)
   (setq _header __header)
   (setq _hardware_name (string __hardware_name))
   (setq _status __status)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:hardware_name
   (&optional __hardware_name)
   (if __hardware_name (setq _hardware_name __hardware_name)) _hardware_name)
  (:status
   (&rest __status)
   (if (keywordp (car __status))
       (send* _status __status)
     (progn
       (if __status (setq _status (car __status)))
       _status)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _hardware_name
    4 (length _hardware_name)
    ;; autoware_system_msgs/DiagnosticStatusArray[] _status
    (apply #'+ (send-all _status :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _hardware_name
       (write-long (length _hardware_name) s) (princ _hardware_name s)
     ;; autoware_system_msgs/DiagnosticStatusArray[] _status
     (write-long (length _status) s)
     (dolist (elem _status)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _hardware_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _hardware_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; autoware_system_msgs/DiagnosticStatusArray[] _status
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _status (let (r) (dotimes (i n) (push (instance autoware_system_msgs::DiagnosticStatusArray :init) r)) r))
     (dolist (elem- _status)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get autoware_system_msgs::HardwareStatus :md5sum-) "40a97d6058cac5d379870773362116f2")
(setf (get autoware_system_msgs::HardwareStatus :datatype-) "autoware_system_msgs/HardwareStatus")
(setf (get autoware_system_msgs::HardwareStatus :definition-)
      "std_msgs/Header header
string hardware_name
autoware_system_msgs/DiagnosticStatusArray[] status
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
MSG: autoware_system_msgs/DiagnosticStatusArray
autoware_system_msgs/DiagnosticStatus[] status
================================================================================
MSG: autoware_system_msgs/DiagnosticStatus
Header header

string key

string value

string description

uint8 UNDEFINED = 0

uint8 type
uint8 OUT_OF_RANGE = 1
uint8 UNEXPECTED_RATE = 2
uint8 INVALID_VALUE = 3
uint8 INTERNAL = 4
uint8 FUNCTIONAL = 100
uint8 HARDWARE = 200

uint8 level
uint8 OK = 1
uint8 WARN = 2
uint8 ERROR = 3
uint8 FATAL = 4

")



(provide :autoware_system_msgs/HardwareStatus "40a97d6058cac5d379870773362116f2")


