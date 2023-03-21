; Auto-generated. Do not edit!


(cl:in-package common_msgs-msg)


;//! \htmlinclude ChassisStatus.msg.html

(cl:defclass <ChassisStatus> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (real_throttle
    :reader real_throttle
    :initarg :real_throttle
    :type cl:fixnum
    :initform 0)
   (real_brake_pressure
    :reader real_brake_pressure
    :initarg :real_brake_pressure
    :type cl:fixnum
    :initform 0)
   (real_steer_angle
    :reader real_steer_angle
    :initarg :real_steer_angle
    :type cl:float
    :initform 0.0)
   (vehicle_run_mode
    :reader vehicle_run_mode
    :initarg :vehicle_run_mode
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ChassisStatus (<ChassisStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ChassisStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ChassisStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common_msgs-msg:<ChassisStatus> is deprecated: use common_msgs-msg:ChassisStatus instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ChassisStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:header-val is deprecated.  Use common_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'real_throttle-val :lambda-list '(m))
(cl:defmethod real_throttle-val ((m <ChassisStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:real_throttle-val is deprecated.  Use common_msgs-msg:real_throttle instead.")
  (real_throttle m))

(cl:ensure-generic-function 'real_brake_pressure-val :lambda-list '(m))
(cl:defmethod real_brake_pressure-val ((m <ChassisStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:real_brake_pressure-val is deprecated.  Use common_msgs-msg:real_brake_pressure instead.")
  (real_brake_pressure m))

(cl:ensure-generic-function 'real_steer_angle-val :lambda-list '(m))
(cl:defmethod real_steer_angle-val ((m <ChassisStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:real_steer_angle-val is deprecated.  Use common_msgs-msg:real_steer_angle instead.")
  (real_steer_angle m))

(cl:ensure-generic-function 'vehicle_run_mode-val :lambda-list '(m))
(cl:defmethod vehicle_run_mode-val ((m <ChassisStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:vehicle_run_mode-val is deprecated.  Use common_msgs-msg:vehicle_run_mode instead.")
  (vehicle_run_mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ChassisStatus>) ostream)
  "Serializes a message object of type '<ChassisStatus>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'real_throttle)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'real_brake_pressure)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'real_steer_angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vehicle_run_mode)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ChassisStatus>) istream)
  "Deserializes a message object of type '<ChassisStatus>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'real_throttle)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'real_brake_pressure)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'real_steer_angle) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vehicle_run_mode)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ChassisStatus>)))
  "Returns string type for a message object of type '<ChassisStatus>"
  "common_msgs/ChassisStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ChassisStatus)))
  "Returns string type for a message object of type 'ChassisStatus"
  "common_msgs/ChassisStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ChassisStatus>)))
  "Returns md5sum for a message object of type '<ChassisStatus>"
  "3318ade59e28d0d24b09394333e12cbc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ChassisStatus)))
  "Returns md5sum for a message object of type 'ChassisStatus"
  "3318ade59e28d0d24b09394333e12cbc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ChassisStatus>)))
  "Returns full string definition for message of type '<ChassisStatus>"
  (cl:format cl:nil "std_msgs/Header header~%~%# real acc throttle value~%uint8 real_throttle~%~%# real brake pressure~%uint8 real_brake_pressure~%~%# real steer angle~%float64 real_steer_angle~%~%# vehicle run mode~%uint8 vehicle_run_mode~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ChassisStatus)))
  "Returns full string definition for message of type 'ChassisStatus"
  (cl:format cl:nil "std_msgs/Header header~%~%# real acc throttle value~%uint8 real_throttle~%~%# real brake pressure~%uint8 real_brake_pressure~%~%# real steer angle~%float64 real_steer_angle~%~%# vehicle run mode~%uint8 vehicle_run_mode~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ChassisStatus>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ChassisStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'ChassisStatus
    (cl:cons ':header (header msg))
    (cl:cons ':real_throttle (real_throttle msg))
    (cl:cons ':real_brake_pressure (real_brake_pressure msg))
    (cl:cons ':real_steer_angle (real_steer_angle msg))
    (cl:cons ':vehicle_run_mode (vehicle_run_mode msg))
))
