;; Auto-generated. Do not edit!


(when (boundp 'autoware_system_msgs::NodeStatus)
  (if (not (find-package "AUTOWARE_SYSTEM_MSGS"))
    (make-package "AUTOWARE_SYSTEM_MSGS"))
  (shadow 'NodeStatus (find-package "AUTOWARE_SYSTEM_MSGS")))
(unless (find-package "AUTOWARE_SYSTEM_MSGS::NODESTATUS")
  (make-package "AUTOWARE_SYSTEM_MSGS::NODESTATUS"))

(in-package "ROS")
;;//! \htmlinclude NodeStatus.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass autoware_system_msgs::NodeStatus
  :super ros::object
  :slots (_header _node_name _node_activated _status ))

(defmethod autoware_system_msgs::NodeStatus
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:node_name __node_name) "")
    ((:node_activated __node_activated) nil)
    ((:status __status) ())
    )
   (send-super :init)
   (setq _header __header)
   (setq _node_name (string __node_name))
   (setq _node_activated __node_activated)
   (setq _status __status)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:node_name
   (&optional __node_name)
   (if __node_name (setq _node_name __node_name)) _node_name)
  (:node_activated
   (&optional (__node_activated :null))
   (if (not (eq __node_activated :null)) (setq _node_activated __node_activated)) _node_activated)
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
    ;; string _node_name
    4 (length _node_name)
    ;; bool _node_activated
    1
    ;; autoware_system_msgs/DiagnosticStatusArray[] _status
    (apply #'+ (send-all _status :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _node_name
       (write-long (length _node_name) s) (princ _node_name s)
     ;; bool _node_activated
       (if _node_activated (write-byte -1 s) (write-byte 0 s))
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
   ;; string _node_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _node_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _node_activated
     (setq _node_activated (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
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

(setf (get autoware_system_msgs::NodeStatus :md5sum-) "24ee03c6afba01e301b566add8485af9")
(setf (get autoware_system_msgs::NodeStatus :datatype-) "autoware_system_msgs/NodeStatus")
(setf (get autoware_system_msgs::NodeStatus :definition-)
      "Header header
string node_name
bool node_activated
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



(provide :autoware_system_msgs/NodeStatus "24ee03c6afba01e301b566add8485af9")


