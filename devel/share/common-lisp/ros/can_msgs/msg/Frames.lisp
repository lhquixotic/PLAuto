; Auto-generated. Do not edit!


(cl:in-package can_msgs-msg)


;//! \htmlinclude Frames.msg.html

(cl:defclass <Frames> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (frames
    :reader frames
    :initarg :frames
    :type (cl:vector can_msgs-msg:Frame)
   :initform (cl:make-array 0 :element-type 'can_msgs-msg:Frame :initial-element (cl:make-instance 'can_msgs-msg:Frame))))
)

(cl:defclass Frames (<Frames>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Frames>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Frames)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name can_msgs-msg:<Frames> is deprecated: use can_msgs-msg:Frames instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Frames>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader can_msgs-msg:header-val is deprecated.  Use can_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'frames-val :lambda-list '(m))
(cl:defmethod frames-val ((m <Frames>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader can_msgs-msg:frames-val is deprecated.  Use can_msgs-msg:frames instead.")
  (frames m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Frames>) ostream)
  "Serializes a message object of type '<Frames>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'frames))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'frames))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Frames>) istream)
  "Deserializes a message object of type '<Frames>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'frames) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'frames)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'can_msgs-msg:Frame))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Frames>)))
  "Returns string type for a message object of type '<Frames>"
  "can_msgs/Frames")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Frames)))
  "Returns string type for a message object of type 'Frames"
  "can_msgs/Frames")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Frames>)))
  "Returns md5sum for a message object of type '<Frames>"
  "a652a31438717760a5dd3f589c696e07")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Frames)))
  "Returns md5sum for a message object of type 'Frames"
  "a652a31438717760a5dd3f589c696e07")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Frames>)))
  "Returns full string definition for message of type '<Frames>"
  (cl:format cl:nil "Header header~%Frame[] frames~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: can_msgs/Frame~%Header header~%uint32 id~%bool is_rtr~%bool is_extended~%bool is_error~%uint8 dlc~%uint8[8] data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Frames)))
  "Returns full string definition for message of type 'Frames"
  (cl:format cl:nil "Header header~%Frame[] frames~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: can_msgs/Frame~%Header header~%uint32 id~%bool is_rtr~%bool is_extended~%bool is_error~%uint8 dlc~%uint8[8] data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Frames>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'frames) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Frames>))
  "Converts a ROS message object to a list"
  (cl:list 'Frames
    (cl:cons ':header (header msg))
    (cl:cons ':frames (frames msg))
))
