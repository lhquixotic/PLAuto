;; Auto-generated. Do not edit!


(when (boundp 'autoware_system_msgs::SystemStatus)
  (if (not (find-package "AUTOWARE_SYSTEM_MSGS"))
    (make-package "AUTOWARE_SYSTEM_MSGS"))
  (shadow 'SystemStatus (find-package "AUTOWARE_SYSTEM_MSGS")))
(unless (find-package "AUTOWARE_SYSTEM_MSGS::SYSTEMSTATUS")
  (make-package "AUTOWARE_SYSTEM_MSGS::SYSTEMSTATUS"))

(in-package "ROS")
;;//! \htmlinclude SystemStatus.msg.html
(if (not (find-package "ROSGRAPH_MSGS"))
  (ros::roseus-add-msgs "rosgraph_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass autoware_system_msgs::SystemStatus
  :super ros::object
  :slots (_header _available_nodes _detect_too_match_warning _node_status _hardware_status _topic_statistics ))

(defmethod autoware_system_msgs::SystemStatus
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:available_nodes __available_nodes) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:detect_too_match_warning __detect_too_match_warning) nil)
    ((:node_status __node_status) ())
    ((:hardware_status __hardware_status) ())
    ((:topic_statistics __topic_statistics) ())
    )
   (send-super :init)
   (setq _header __header)
   (setq _available_nodes __available_nodes)
   (setq _detect_too_match_warning __detect_too_match_warning)
   (setq _node_status __node_status)
   (setq _hardware_status __hardware_status)
   (setq _topic_statistics __topic_statistics)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:available_nodes
   (&optional __available_nodes)
   (if __available_nodes (setq _available_nodes __available_nodes)) _available_nodes)
  (:detect_too_match_warning
   (&optional (__detect_too_match_warning :null))
   (if (not (eq __detect_too_match_warning :null)) (setq _detect_too_match_warning __detect_too_match_warning)) _detect_too_match_warning)
  (:node_status
   (&rest __node_status)
   (if (keywordp (car __node_status))
       (send* _node_status __node_status)
     (progn
       (if __node_status (setq _node_status (car __node_status)))
       _node_status)))
  (:hardware_status
   (&rest __hardware_status)
   (if (keywordp (car __hardware_status))
       (send* _hardware_status __hardware_status)
     (progn
       (if __hardware_status (setq _hardware_status (car __hardware_status)))
       _hardware_status)))
  (:topic_statistics
   (&rest __topic_statistics)
   (if (keywordp (car __topic_statistics))
       (send* _topic_statistics __topic_statistics)
     (progn
       (if __topic_statistics (setq _topic_statistics (car __topic_statistics)))
       _topic_statistics)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string[] _available_nodes
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _available_nodes)) 4
    ;; bool _detect_too_match_warning
    1
    ;; autoware_system_msgs/NodeStatus[] _node_status
    (apply #'+ (send-all _node_status :serialization-length)) 4
    ;; autoware_system_msgs/HardwareStatus[] _hardware_status
    (apply #'+ (send-all _hardware_status :serialization-length)) 4
    ;; rosgraph_msgs/TopicStatistics[] _topic_statistics
    (apply #'+ (send-all _topic_statistics :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string[] _available_nodes
     (write-long (length _available_nodes) s)
     (dolist (elem _available_nodes)
       (write-long (length elem) s) (princ elem s)
       )
     ;; bool _detect_too_match_warning
       (if _detect_too_match_warning (write-byte -1 s) (write-byte 0 s))
     ;; autoware_system_msgs/NodeStatus[] _node_status
     (write-long (length _node_status) s)
     (dolist (elem _node_status)
       (send elem :serialize s)
       )
     ;; autoware_system_msgs/HardwareStatus[] _hardware_status
     (write-long (length _hardware_status) s)
     (dolist (elem _hardware_status)
       (send elem :serialize s)
       )
     ;; rosgraph_msgs/TopicStatistics[] _topic_statistics
     (write-long (length _topic_statistics) s)
     (dolist (elem _topic_statistics)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string[] _available_nodes
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _available_nodes (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _available_nodes i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; bool _detect_too_match_warning
     (setq _detect_too_match_warning (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; autoware_system_msgs/NodeStatus[] _node_status
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _node_status (let (r) (dotimes (i n) (push (instance autoware_system_msgs::NodeStatus :init) r)) r))
     (dolist (elem- _node_status)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; autoware_system_msgs/HardwareStatus[] _hardware_status
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _hardware_status (let (r) (dotimes (i n) (push (instance autoware_system_msgs::HardwareStatus :init) r)) r))
     (dolist (elem- _hardware_status)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; rosgraph_msgs/TopicStatistics[] _topic_statistics
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _topic_statistics (let (r) (dotimes (i n) (push (instance rosgraph_msgs::TopicStatistics :init) r)) r))
     (dolist (elem- _topic_statistics)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get autoware_system_msgs::SystemStatus :md5sum-) "7daf3e9d5c454c414ddc765307bd564d")
(setf (get autoware_system_msgs::SystemStatus :datatype-) "autoware_system_msgs/SystemStatus")
(setf (get autoware_system_msgs::SystemStatus :definition-)
      "Header header
string[] available_nodes
bool detect_too_match_warning
autoware_system_msgs/NodeStatus[] node_status
autoware_system_msgs/HardwareStatus[] hardware_status
rosgraph_msgs/TopicStatistics[] topic_statistics
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
MSG: autoware_system_msgs/NodeStatus
Header header
string node_name
bool node_activated
autoware_system_msgs/DiagnosticStatusArray[] status
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

================================================================================
MSG: autoware_system_msgs/HardwareStatus
std_msgs/Header header
string hardware_name
autoware_system_msgs/DiagnosticStatusArray[] status
================================================================================
MSG: rosgraph_msgs/TopicStatistics
# name of the topic
string topic

# node id of the publisher
string node_pub

# node id of the subscriber
string node_sub

# the statistics apply to this time window
time window_start
time window_stop

# number of messages delivered during the window
int32 delivered_msgs
# numbers of messages dropped during the window
int32 dropped_msgs

# traffic during the window, in bytes
int32 traffic

# mean/stddev/max period between two messages
duration period_mean
duration period_stddev
duration period_max

# mean/stddev/max age of the message based on the
# timestamp in the message header. In case the
# message does not have a header, it will be 0.
duration stamp_age_mean
duration stamp_age_stddev
duration stamp_age_max

")



(provide :autoware_system_msgs/SystemStatus "7daf3e9d5c454c414ddc765307bd564d")


