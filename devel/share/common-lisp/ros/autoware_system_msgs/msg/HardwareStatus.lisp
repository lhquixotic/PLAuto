; Auto-generated. Do not edit!


(cl:in-package autoware_system_msgs-msg)


;//! \htmlinclude HardwareStatus.msg.html

(cl:defclass <HardwareStatus> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (hardware_name
    :reader hardware_name
    :initarg :hardware_name
    :type cl:string
    :initform "")
   (status
    :reader status
    :initarg :status
    :type (cl:vector autoware_system_msgs-msg:DiagnosticStatusArray)
   :initform (cl:make-array 0 :element-type 'autoware_system_msgs-msg:DiagnosticStatusArray :initial-element (cl:make-instance 'autoware_system_msgs-msg:DiagnosticStatusArray))))
)

(cl:defclass HardwareStatus (<HardwareStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HardwareStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HardwareStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name autoware_system_msgs-msg:<HardwareStatus> is deprecated: use autoware_system_msgs-msg:HardwareStatus instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <HardwareStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:header-val is deprecated.  Use autoware_system_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'hardware_name-val :lambda-list '(m))
(cl:defmethod hardware_name-val ((m <HardwareStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:hardware_name-val is deprecated.  Use autoware_system_msgs-msg:hardware_name instead.")
  (hardware_name m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <HardwareStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:status-val is deprecated.  Use autoware_system_msgs-msg:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HardwareStatus>) ostream)
  "Serializes a message object of type '<HardwareStatus>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'hardware_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'hardware_name))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'status))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'status))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HardwareStatus>) istream)
  "Deserializes a message object of type '<HardwareStatus>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'hardware_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'hardware_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'status) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'status)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'autoware_system_msgs-msg:DiagnosticStatusArray))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HardwareStatus>)))
  "Returns string type for a message object of type '<HardwareStatus>"
  "autoware_system_msgs/HardwareStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HardwareStatus)))
  "Returns string type for a message object of type 'HardwareStatus"
  "autoware_system_msgs/HardwareStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HardwareStatus>)))
  "Returns md5sum for a message object of type '<HardwareStatus>"
  "40a97d6058cac5d379870773362116f2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HardwareStatus)))
  "Returns md5sum for a message object of type 'HardwareStatus"
  "40a97d6058cac5d379870773362116f2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HardwareStatus>)))
  "Returns full string definition for message of type '<HardwareStatus>"
  (cl:format cl:nil "std_msgs/Header header~%string hardware_name~%autoware_system_msgs/DiagnosticStatusArray[] status~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatusArray~%autoware_system_msgs/DiagnosticStatus[] status~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatus~%Header header~%~%string key~%~%string value~%~%string description~%~%uint8 UNDEFINED = 0~%~%uint8 type~%uint8 OUT_OF_RANGE = 1~%uint8 UNEXPECTED_RATE = 2~%uint8 INVALID_VALUE = 3~%uint8 INTERNAL = 4~%uint8 FUNCTIONAL = 100~%uint8 HARDWARE = 200~%~%uint8 level~%uint8 OK = 1~%uint8 WARN = 2~%uint8 ERROR = 3~%uint8 FATAL = 4~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HardwareStatus)))
  "Returns full string definition for message of type 'HardwareStatus"
  (cl:format cl:nil "std_msgs/Header header~%string hardware_name~%autoware_system_msgs/DiagnosticStatusArray[] status~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatusArray~%autoware_system_msgs/DiagnosticStatus[] status~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatus~%Header header~%~%string key~%~%string value~%~%string description~%~%uint8 UNDEFINED = 0~%~%uint8 type~%uint8 OUT_OF_RANGE = 1~%uint8 UNEXPECTED_RATE = 2~%uint8 INVALID_VALUE = 3~%uint8 INTERNAL = 4~%uint8 FUNCTIONAL = 100~%uint8 HARDWARE = 200~%~%uint8 level~%uint8 OK = 1~%uint8 WARN = 2~%uint8 ERROR = 3~%uint8 FATAL = 4~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HardwareStatus>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'hardware_name))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'status) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HardwareStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'HardwareStatus
    (cl:cons ':header (header msg))
    (cl:cons ':hardware_name (hardware_name msg))
    (cl:cons ':status (status msg))
))
