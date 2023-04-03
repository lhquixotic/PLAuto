; Auto-generated. Do not edit!


(cl:in-package common_msgs-msg)


;//! \htmlinclude VehicleDynamicState.msg.html

(cl:defclass <VehicleDynamicState> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (lon_speed
    :reader lon_speed
    :initarg :lon_speed
    :type cl:float
    :initform 0.0)
   (lon_accel
    :reader lon_accel
    :initarg :lon_accel
    :type cl:float
    :initform 0.0)
   (lat_speed
    :reader lat_speed
    :initarg :lat_speed
    :type cl:float
    :initform 0.0)
   (lat_accel
    :reader lat_accel
    :initarg :lat_accel
    :type cl:float
    :initform 0.0)
   (yaw_rate
    :reader yaw_rate
    :initarg :yaw_rate
    :type cl:float
    :initform 0.0)
   (yaw_accel
    :reader yaw_accel
    :initarg :yaw_accel
    :type cl:float
    :initform 0.0))
)

(cl:defclass VehicleDynamicState (<VehicleDynamicState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <VehicleDynamicState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'VehicleDynamicState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common_msgs-msg:<VehicleDynamicState> is deprecated: use common_msgs-msg:VehicleDynamicState instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <VehicleDynamicState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:header-val is deprecated.  Use common_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'lon_speed-val :lambda-list '(m))
(cl:defmethod lon_speed-val ((m <VehicleDynamicState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:lon_speed-val is deprecated.  Use common_msgs-msg:lon_speed instead.")
  (lon_speed m))

(cl:ensure-generic-function 'lon_accel-val :lambda-list '(m))
(cl:defmethod lon_accel-val ((m <VehicleDynamicState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:lon_accel-val is deprecated.  Use common_msgs-msg:lon_accel instead.")
  (lon_accel m))

(cl:ensure-generic-function 'lat_speed-val :lambda-list '(m))
(cl:defmethod lat_speed-val ((m <VehicleDynamicState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:lat_speed-val is deprecated.  Use common_msgs-msg:lat_speed instead.")
  (lat_speed m))

(cl:ensure-generic-function 'lat_accel-val :lambda-list '(m))
(cl:defmethod lat_accel-val ((m <VehicleDynamicState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:lat_accel-val is deprecated.  Use common_msgs-msg:lat_accel instead.")
  (lat_accel m))

(cl:ensure-generic-function 'yaw_rate-val :lambda-list '(m))
(cl:defmethod yaw_rate-val ((m <VehicleDynamicState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:yaw_rate-val is deprecated.  Use common_msgs-msg:yaw_rate instead.")
  (yaw_rate m))

(cl:ensure-generic-function 'yaw_accel-val :lambda-list '(m))
(cl:defmethod yaw_accel-val ((m <VehicleDynamicState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:yaw_accel-val is deprecated.  Use common_msgs-msg:yaw_accel instead.")
  (yaw_accel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <VehicleDynamicState>) ostream)
  "Serializes a message object of type '<VehicleDynamicState>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lon_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lon_accel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lat_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lat_accel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw_rate))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw_accel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <VehicleDynamicState>) istream)
  "Deserializes a message object of type '<VehicleDynamicState>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lon_speed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lon_accel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lat_speed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lat_accel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw_rate) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw_accel) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<VehicleDynamicState>)))
  "Returns string type for a message object of type '<VehicleDynamicState>"
  "common_msgs/VehicleDynamicState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'VehicleDynamicState)))
  "Returns string type for a message object of type 'VehicleDynamicState"
  "common_msgs/VehicleDynamicState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<VehicleDynamicState>)))
  "Returns md5sum for a message object of type '<VehicleDynamicState>"
  "d3015605eb810e5c79a5de962cc9f172")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'VehicleDynamicState)))
  "Returns md5sum for a message object of type 'VehicleDynamicState"
  "d3015605eb810e5c79a5de962cc9f172")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<VehicleDynamicState>)))
  "Returns full string definition for message of type '<VehicleDynamicState>"
  (cl:format cl:nil "std_msgs/Header  header~%~%float32 lon_speed~%float32 lon_accel~%float32 lat_speed~%float32 lat_accel~%float32 yaw_rate~%float32 yaw_accel~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'VehicleDynamicState)))
  "Returns full string definition for message of type 'VehicleDynamicState"
  (cl:format cl:nil "std_msgs/Header  header~%~%float32 lon_speed~%float32 lon_accel~%float32 lat_speed~%float32 lat_accel~%float32 yaw_rate~%float32 yaw_accel~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <VehicleDynamicState>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <VehicleDynamicState>))
  "Converts a ROS message object to a list"
  (cl:list 'VehicleDynamicState
    (cl:cons ':header (header msg))
    (cl:cons ':lon_speed (lon_speed msg))
    (cl:cons ':lon_accel (lon_accel msg))
    (cl:cons ':lat_speed (lat_speed msg))
    (cl:cons ':lat_accel (lat_accel msg))
    (cl:cons ':yaw_rate (yaw_rate msg))
    (cl:cons ':yaw_accel (yaw_accel msg))
))
