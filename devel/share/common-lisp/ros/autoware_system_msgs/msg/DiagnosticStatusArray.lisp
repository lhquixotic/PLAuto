; Auto-generated. Do not edit!


(cl:in-package autoware_system_msgs-msg)


;//! \htmlinclude DiagnosticStatusArray.msg.html

(cl:defclass <DiagnosticStatusArray> (roslisp-msg-protocol:ros-message)
  ((status
    :reader status
    :initarg :status
    :type (cl:vector autoware_system_msgs-msg:DiagnosticStatus)
   :initform (cl:make-array 0 :element-type 'autoware_system_msgs-msg:DiagnosticStatus :initial-element (cl:make-instance 'autoware_system_msgs-msg:DiagnosticStatus))))
)

(cl:defclass DiagnosticStatusArray (<DiagnosticStatusArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DiagnosticStatusArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DiagnosticStatusArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name autoware_system_msgs-msg:<DiagnosticStatusArray> is deprecated: use autoware_system_msgs-msg:DiagnosticStatusArray instead.")))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <DiagnosticStatusArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader autoware_system_msgs-msg:status-val is deprecated.  Use autoware_system_msgs-msg:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DiagnosticStatusArray>) ostream)
  "Serializes a message object of type '<DiagnosticStatusArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'status))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'status))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DiagnosticStatusArray>) istream)
  "Deserializes a message object of type '<DiagnosticStatusArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'status) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'status)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'autoware_system_msgs-msg:DiagnosticStatus))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DiagnosticStatusArray>)))
  "Returns string type for a message object of type '<DiagnosticStatusArray>"
  "autoware_system_msgs/DiagnosticStatusArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DiagnosticStatusArray)))
  "Returns string type for a message object of type 'DiagnosticStatusArray"
  "autoware_system_msgs/DiagnosticStatusArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DiagnosticStatusArray>)))
  "Returns md5sum for a message object of type '<DiagnosticStatusArray>"
  "3630b28b658945d3148aa0b60b9f7af0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DiagnosticStatusArray)))
  "Returns md5sum for a message object of type 'DiagnosticStatusArray"
  "3630b28b658945d3148aa0b60b9f7af0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DiagnosticStatusArray>)))
  "Returns full string definition for message of type '<DiagnosticStatusArray>"
  (cl:format cl:nil "autoware_system_msgs/DiagnosticStatus[] status~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatus~%Header header~%~%string key~%~%string value~%~%string description~%~%uint8 UNDEFINED = 0~%~%uint8 type~%uint8 OUT_OF_RANGE = 1~%uint8 UNEXPECTED_RATE = 2~%uint8 INVALID_VALUE = 3~%uint8 INTERNAL = 4~%uint8 FUNCTIONAL = 100~%uint8 HARDWARE = 200~%~%uint8 level~%uint8 OK = 1~%uint8 WARN = 2~%uint8 ERROR = 3~%uint8 FATAL = 4~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DiagnosticStatusArray)))
  "Returns full string definition for message of type 'DiagnosticStatusArray"
  (cl:format cl:nil "autoware_system_msgs/DiagnosticStatus[] status~%================================================================================~%MSG: autoware_system_msgs/DiagnosticStatus~%Header header~%~%string key~%~%string value~%~%string description~%~%uint8 UNDEFINED = 0~%~%uint8 type~%uint8 OUT_OF_RANGE = 1~%uint8 UNEXPECTED_RATE = 2~%uint8 INVALID_VALUE = 3~%uint8 INTERNAL = 4~%uint8 FUNCTIONAL = 100~%uint8 HARDWARE = 200~%~%uint8 level~%uint8 OK = 1~%uint8 WARN = 2~%uint8 ERROR = 3~%uint8 FATAL = 4~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DiagnosticStatusArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'status) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DiagnosticStatusArray>))
  "Converts a ROS message object to a list"
  (cl:list 'DiagnosticStatusArray
    (cl:cons ':status (status msg))
))
