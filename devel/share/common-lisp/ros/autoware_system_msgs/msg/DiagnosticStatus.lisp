; Auto-generated. Do not edit!


(cl:in-package autoware_system_msgs-msg)


;//! \htmlinclude DiagnosticStatus.msg.html

(cl:defclass <DiagnosticStatus> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (key
    :reader key
    :initarg :key
    :type cl:string
    :initform "")
   (value
    :reader value
    :initarg :value
    :type cl:string
    :initform "")
   (description
    :reader description
    :initarg :description
    :type cl:string
    :initform "")
   (type
    :reader type
    :initarg :type
    :type cl:fixnum
    :initform 0)
   (level
    :reader level
    :initarg :level
    :type cl:fixnum
    :initform 0))
)

(cl:defclass DiagnosticStatus (<DiagnosticStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DiagnosticStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DiagnosticStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name autoware_system_msgs-msg:<DiagnosticStatus> is deprecated: use autoware_system_msgs-msg:DiagnosticStatus instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <DiagnosticStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:header-val is deprecated.  Use autoware_system_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'key-val :lambda-list '(m))
(cl:defmethod key-val ((m <DiagnosticStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:key-val is deprecated.  Use autoware_system_msgs-msg:key instead.")
  (key m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <DiagnosticStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:value-val is deprecated.  Use autoware_system_msgs-msg:value instead.")
  (value m))

(cl:ensure-generic-function 'description-val :lambda-list '(m))
(cl:defmethod description-val ((m <DiagnosticStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:description-val is deprecated.  Use autoware_system_msgs-msg:description instead.")
  (description m))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <DiagnosticStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:type-val is deprecated.  Use autoware_system_msgs-msg:type instead.")
  (type m))

(cl:ensure-generic-function 'level-val :lambda-list '(m))
(cl:defmethod level-val ((m <DiagnosticStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:level-val is deprecated.  Use autoware_system_msgs-msg:level instead.")
  (level m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<DiagnosticStatus>)))
    "Constants for message type '<DiagnosticStatus>"
  '((:UNDEFINED . 0)
    (:OUT_OF_RANGE . 1)
    (:UNEXPECTED_RATE . 2)
    (:INVALID_VALUE . 3)
    (:INTERNAL . 4)
    (:FUNCTIONAL . 100)
    (:HARDWARE . 200)
    (:OK . 1)
    (:WARN . 2)
    (:ERROR . 3)
    (:FATAL . 4))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'DiagnosticStatus)))
    "Constants for message type 'DiagnosticStatus"
  '((:UNDEFINED . 0)
    (:OUT_OF_RANGE . 1)
    (:UNEXPECTED_RATE . 2)
    (:INVALID_VALUE . 3)
    (:INTERNAL . 4)
    (:FUNCTIONAL . 100)
    (:HARDWARE . 200)
    (:OK . 1)
    (:WARN . 2)
    (:ERROR . 3)
    (:FATAL . 4))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DiagnosticStatus>) ostream)
  "Serializes a message object of type '<DiagnosticStatus>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'key))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'key))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'value))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'description))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'description))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'level)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DiagnosticStatus>) istream)
  "Deserializes a message object of type '<DiagnosticStatus>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'key) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'key) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'value) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'value) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'description) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'description) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'level)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DiagnosticStatus>)))
  "Returns string type for a message object of type '<DiagnosticStatus>"
  "autoware_system_msgs/DiagnosticStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DiagnosticStatus)))
  "Returns string type for a message object of type 'DiagnosticStatus"
  "autoware_system_msgs/DiagnosticStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DiagnosticStatus>)))
  "Returns md5sum for a message object of type '<DiagnosticStatus>"
  "b47803ee46ed9c93715ae4761992cf03")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DiagnosticStatus)))
  "Returns md5sum for a message object of type 'DiagnosticStatus"
  "b47803ee46ed9c93715ae4761992cf03")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DiagnosticStatus>)))
  "Returns full string definition for message of type '<DiagnosticStatus>"
  (cl:format cl:nil "Header header~%~%string key~%~%string value~%~%string description~%~%uint8 UNDEFINED = 0~%~%uint8 type~%uint8 OUT_OF_RANGE = 1~%uint8 UNEXPECTED_RATE = 2~%uint8 INVALID_VALUE = 3~%uint8 INTERNAL = 4~%uint8 FUNCTIONAL = 100~%uint8 HARDWARE = 200~%~%uint8 level~%uint8 OK = 1~%uint8 WARN = 2~%uint8 ERROR = 3~%uint8 FATAL = 4~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DiagnosticStatus)))
  "Returns full string definition for message of type 'DiagnosticStatus"
  (cl:format cl:nil "Header header~%~%string key~%~%string value~%~%string description~%~%uint8 UNDEFINED = 0~%~%uint8 type~%uint8 OUT_OF_RANGE = 1~%uint8 UNEXPECTED_RATE = 2~%uint8 INVALID_VALUE = 3~%uint8 INTERNAL = 4~%uint8 FUNCTIONAL = 100~%uint8 HARDWARE = 200~%~%uint8 level~%uint8 OK = 1~%uint8 WARN = 2~%uint8 ERROR = 3~%uint8 FATAL = 4~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DiagnosticStatus>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'key))
     4 (cl:length (cl:slot-value msg 'value))
     4 (cl:length (cl:slot-value msg 'description))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DiagnosticStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'DiagnosticStatus
    (cl:cons ':header (header msg))
    (cl:cons ':key (key msg))
    (cl:cons ':value (value msg))
    (cl:cons ':description (description msg))
    (cl:cons ':type (type msg))
    (cl:cons ':level (level msg))
))
