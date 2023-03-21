; Auto-generated. Do not edit!


(cl:in-package common_msgs-msg)


;//! \htmlinclude StopDecision.msg.html

(cl:defclass <StopDecision> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (veh_stop_flag
    :reader veh_stop_flag
    :initarg :veh_stop_flag
    :type cl:integer
    :initform 0))
)

(cl:defclass StopDecision (<StopDecision>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StopDecision>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StopDecision)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common_msgs-msg:<StopDecision> is deprecated: use common_msgs-msg:StopDecision instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <StopDecision>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:header-val is deprecated.  Use common_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'veh_stop_flag-val :lambda-list '(m))
(cl:defmethod veh_stop_flag-val ((m <StopDecision>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:veh_stop_flag-val is deprecated.  Use common_msgs-msg:veh_stop_flag instead.")
  (veh_stop_flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StopDecision>) ostream)
  "Serializes a message object of type '<StopDecision>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'veh_stop_flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StopDecision>) istream)
  "Deserializes a message object of type '<StopDecision>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'veh_stop_flag) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StopDecision>)))
  "Returns string type for a message object of type '<StopDecision>"
  "common_msgs/StopDecision")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StopDecision)))
  "Returns string type for a message object of type 'StopDecision"
  "common_msgs/StopDecision")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StopDecision>)))
  "Returns md5sum for a message object of type '<StopDecision>"
  "40185f333e9db25a8a2ac70bc6903e53")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StopDecision)))
  "Returns md5sum for a message object of type 'StopDecision"
  "40185f333e9db25a8a2ac70bc6903e53")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StopDecision>)))
  "Returns full string definition for message of type '<StopDecision>"
  (cl:format cl:nil "std_msgs/Header header~%int32 veh_stop_flag~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StopDecision)))
  "Returns full string definition for message of type 'StopDecision"
  (cl:format cl:nil "std_msgs/Header header~%int32 veh_stop_flag~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StopDecision>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StopDecision>))
  "Converts a ROS message object to a list"
  (cl:list 'StopDecision
    (cl:cons ':header (header msg))
    (cl:cons ':veh_stop_flag (veh_stop_flag msg))
))
