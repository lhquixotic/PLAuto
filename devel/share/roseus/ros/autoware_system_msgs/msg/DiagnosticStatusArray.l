;; Auto-generated. Do not edit!


(when (boundp 'autoware_system_msgs::DiagnosticStatusArray)
  (if (not (find-package "AUTOWARE_SYSTEM_MSGS"))
    (make-package "AUTOWARE_SYSTEM_MSGS"))
  (shadow 'DiagnosticStatusArray (find-package "AUTOWARE_SYSTEM_MSGS")))
(unless (find-package "AUTOWARE_SYSTEM_MSGS::DIAGNOSTICSTATUSARRAY")
  (make-package "AUTOWARE_SYSTEM_MSGS::DIAGNOSTICSTATUSARRAY"))

(in-package "ROS")
;;//! \htmlinclude DiagnosticStatusArray.msg.html


(defclass autoware_system_msgs::DiagnosticStatusArray
  :super ros::object
  :slots (_status ))

(defmethod autoware_system_msgs::DiagnosticStatusArray
  (:init
   (&key
    ((:status __status) ())
    )
   (send-super :init)
   (setq _status __status)
   self)
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
    ;; autoware_system_msgs/DiagnosticStatus[] _status
    (apply #'+ (send-all _status :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; autoware_system_msgs/DiagnosticStatus[] _status
     (write-long (length _status) s)
     (dolist (elem _status)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; autoware_system_msgs/DiagnosticStatus[] _status
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _status (let (r) (dotimes (i n) (push (instance autoware_system_msgs::DiagnosticStatus :init) r)) r))
     (dolist (elem- _status)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get autoware_system_msgs::DiagnosticStatusArray :md5sum-) "3630b28b658945d3148aa0b60b9f7af0")
(setf (get autoware_system_msgs::DiagnosticStatusArray :datatype-) "autoware_system_msgs/DiagnosticStatusArray")
(setf (get autoware_system_msgs::DiagnosticStatusArray :definition-)
      "autoware_system_msgs/DiagnosticStatus[] status
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



(provide :autoware_system_msgs/DiagnosticStatusArray "3630b28b658945d3148aa0b60b9f7af0")


