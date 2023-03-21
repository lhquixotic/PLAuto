; Auto-generated. Do not edit!


(cl:in-package autoware_system_msgs-msg)


;//! \htmlinclude SystemStatus.msg.html

(cl:defclass <SystemStatus> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (available_nodes
    :reader available_nodes
    :initarg :available_nodes
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (detect_too_match_warning
    :reader detect_too_match_warning
    :initarg :detect_too_match_warning
    :type cl:boolean
    :initform cl:nil)
   (node_status
    :reader node_status
    :initarg :node_status
    :type (cl:vector autoware_system_msgs-msg:NodeStatus)
   :initform (cl:make-array 0 :element-type 'autoware_system_msgs-msg:NodeStatus :initial-element (cl:make-instance 'autoware_system_msgs-msg:NodeStatus)))
   (hardware_status
    :reader hardware_status
    :initarg :hardware_status
    :type (cl:vector autoware_system_msgs-msg:HardwareStatus)
   :initform (cl:make-array 0 :element-type 'autoware_system_msgs-msg:HardwareStatus :initial-element (cl:make-instance 'autoware_system_msgs-msg:HardwareStatus)))
   (topic_statistics
    :reader topic_statistics
    :initarg :topic_statistics
    :type (cl:vector rosgraph_msgs-msg:TopicStatistics)
   :initform (cl:make-array 0 :element-type 'rosgraph_msgs-msg:TopicStatistics :initial-element (cl:make-instance 'rosgraph_msgs-msg:TopicStatistics))))
)

(cl:defclass SystemStatus (<SystemStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SystemStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SystemStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name autoware_system_msgs-msg:<SystemStatus> is deprecated: use autoware_system_msgs-msg:SystemStatus instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SystemStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:header-val is deprecated.  Use autoware_system_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'available_nodes-val :lambda-list '(m))
(cl:defmethod available_nodes-val ((m <SystemStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:available_nodes-val is deprecated.  Use autoware_system_msgs-msg:available_nodes instead.")
  (available_nodes m))

(cl:ensure-generic-function 'detect_too_match_warning-val :lambda-list '(m))
(cl:defmethod detect_too_match_warning-val ((m <SystemStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:detect_too_match_warning-val is deprecated.  Use autoware_system_msgs-msg:detect_too_match_warning instead.")
  (detect_too_match_warning m))

(cl:ensure-generic-function 'node_status-val :lambda-list '(m))
(cl:defmethod node_status-val ((m <SystemStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:node_status-val is deprecated.  Use autoware_system_msgs-msg:node_status instead.")
  (node_status m))

(cl:ensure-generic-function 'hardware_status-val :lambda-list '(m))
(cl:defmethod hardware_status-val ((m <SystemStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:hardware_status-val is deprecated.  Use autoware_system_msgs-msg:hardware_status instead.")
  (hardware_status m))

(cl:ensure-generic-function 'topic_statistics-val :lambda-list '(m))
(cl:defmethod topic_statistics-val ((m <SystemStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:topic_statistics-val is deprecated.  Use autoware_system_msgs-msg:topic_statistics instead.")
  (topic_statistics m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SystemStatus>) ostream)
  "Serializes a message object of type '<SystemStatus>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'available_nodes))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'available_nodes))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'detect_too_match_warning) 1 0)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'node_status))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'node_status))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'hardware_status))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'hardware_status))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'topic_statistics))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'topic_statistics))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SystemStatus>) istream)
  "Deserializes a message object of type '<SystemStatus>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'available_nodes) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'available_nodes)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
    (cl:setf (cl:slot-value msg 'detect_too_match_warning) (cl:not (cl:zerop (cl:read-byte istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'node_status) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'node_status)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'autoware_system_msgs-msg:NodeStatus))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'hardware_status) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'hardware_status)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'autoware_system_msgs-msg:HardwareStatus))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'topic_statistics) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'topic_statistics)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'rosgraph_msgs-msg:TopicStatistics))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SystemStatus>)))
  "Returns string type for a message object of type '<SystemStatus>"
  "autoware_system_msgs/SystemStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SystemStatus)))
  "Returns string type for a message object of type 'SystemStatus"
  "autoware_system_msgs/SystemStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SystemStatus>)))
  "Returns md5sum for a message object of type '<SystemStatus>"
  "7daf3e9d5c454c414ddc765307bd564d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SystemStatus)))
  "Returns md5sum for a message object of type 'SystemStatus"
  "7daf3e9d5c454c414ddc765307bd564d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SystemStatus>)))
  "Returns full string definition for message of type '<SystemStatus>"
  (cl:format cl:nil "Header header~%string[] available_nodes~%bool detect_too_match_warning~%autoware_system_msgs/NodeStatus[] node_status~%autoware_system_msgs/HardwareStatus[] hardware_status~%rosgraph_msgs/TopicStatistics[] topic_statistics~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: autoware_system_msgs/NodeStatus~%Header header~%string node_name~%bool node_activated~%autoware_system_msgs/DiagnosticStatusArray[] status~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatusArray~%autoware_system_msgs/DiagnosticStatus[] status~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatus~%Header header~%~%string key~%~%string value~%~%string description~%~%uint8 UNDEFINED = 0~%~%uint8 type~%uint8 OUT_OF_RANGE = 1~%uint8 UNEXPECTED_RATE = 2~%uint8 INVALID_VALUE = 3~%uint8 INTERNAL = 4~%uint8 FUNCTIONAL = 100~%uint8 HARDWARE = 200~%~%uint8 level~%uint8 OK = 1~%uint8 WARN = 2~%uint8 ERROR = 3~%uint8 FATAL = 4~%~%================================================================================~%MSG: autoware_system_msgs/HardwareStatus~%std_msgs/Header header~%string hardware_name~%autoware_system_msgs/DiagnosticStatusArray[] status~%================================================================================~%MSG: rosgraph_msgs/TopicStatistics~%# name of the topic~%string topic~%~%# node id of the publisher~%string node_pub~%~%# node id of the subscriber~%string node_sub~%~%# the statistics apply to this time window~%time window_start~%time window_stop~%~%# number of messages delivered during the window~%int32 delivered_msgs~%# numbers of messages dropped during the window~%int32 dropped_msgs~%~%# traffic during the window, in bytes~%int32 traffic~%~%# mean/stddev/max period between two messages~%duration period_mean~%duration period_stddev~%duration period_max~%~%# mean/stddev/max age of the message based on the~%# timestamp in the message header. In case the~%# message does not have a header, it will be 0.~%duration stamp_age_mean~%duration stamp_age_stddev~%duration stamp_age_max~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SystemStatus)))
  "Returns full string definition for message of type 'SystemStatus"
  (cl:format cl:nil "Header header~%string[] available_nodes~%bool detect_too_match_warning~%autoware_system_msgs/NodeStatus[] node_status~%autoware_system_msgs/HardwareStatus[] hardware_status~%rosgraph_msgs/TopicStatistics[] topic_statistics~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: autoware_system_msgs/NodeStatus~%Header header~%string node_name~%bool node_activated~%autoware_system_msgs/DiagnosticStatusArray[] status~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatusArray~%autoware_system_msgs/DiagnosticStatus[] status~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatus~%Header header~%~%string key~%~%string value~%~%string description~%~%uint8 UNDEFINED = 0~%~%uint8 type~%uint8 OUT_OF_RANGE = 1~%uint8 UNEXPECTED_RATE = 2~%uint8 INVALID_VALUE = 3~%uint8 INTERNAL = 4~%uint8 FUNCTIONAL = 100~%uint8 HARDWARE = 200~%~%uint8 level~%uint8 OK = 1~%uint8 WARN = 2~%uint8 ERROR = 3~%uint8 FATAL = 4~%~%================================================================================~%MSG: autoware_system_msgs/HardwareStatus~%std_msgs/Header header~%string hardware_name~%autoware_system_msgs/DiagnosticStatusArray[] status~%================================================================================~%MSG: rosgraph_msgs/TopicStatistics~%# name of the topic~%string topic~%~%# node id of the publisher~%string node_pub~%~%# node id of the subscriber~%string node_sub~%~%# the statistics apply to this time window~%time window_start~%time window_stop~%~%# number of messages delivered during the window~%int32 delivered_msgs~%# numbers of messages dropped during the window~%int32 dropped_msgs~%~%# traffic during the window, in bytes~%int32 traffic~%~%# mean/stddev/max period between two messages~%duration period_mean~%duration period_stddev~%duration period_max~%~%# mean/stddev/max age of the message based on the~%# timestamp in the message header. In case the~%# message does not have a header, it will be 0.~%duration stamp_age_mean~%duration stamp_age_stddev~%duration stamp_age_max~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SystemStatus>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'available_nodes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'node_status) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'hardware_status) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'topic_statistics) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SystemStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'SystemStatus
    (cl:cons ':header (header msg))
    (cl:cons ':available_nodes (available_nodes msg))
    (cl:cons ':detect_too_match_warning (detect_too_match_warning msg))
    (cl:cons ':node_status (node_status msg))
    (cl:cons ':hardware_status (hardware_status msg))
    (cl:cons ':topic_statistics (topic_statistics msg))
))
