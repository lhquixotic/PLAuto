;; Auto-generated. Do not edit!


(when (boundp 'can_msgs::Frames)
  (if (not (find-package "CAN_MSGS"))
    (make-package "CAN_MSGS"))
  (shadow 'Frames (find-package "CAN_MSGS")))
(unless (find-package "CAN_MSGS::FRAMES")
  (make-package "CAN_MSGS::FRAMES"))

(in-package "ROS")
;;//! \htmlinclude Frames.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass can_msgs::Frames
  :super ros::object
  :slots (_header _frames ))

(defmethod can_msgs::Frames
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:frames __frames) ())
    )
   (send-super :init)
   (setq _header __header)
   (setq _frames __frames)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:frames
   (&rest __frames)
   (if (keywordp (car __frames))
       (send* _frames __frames)
     (progn
       (if __frames (setq _frames (car __frames)))
       _frames)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; can_msgs/Frame[] _frames
    (apply #'+ (send-all _frames :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; can_msgs/Frame[] _frames
     (write-long (length _frames) s)
     (dolist (elem _frames)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; can_msgs/Frame[] _frames
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _frames (let (r) (dotimes (i n) (push (instance can_msgs::Frame :init) r)) r))
     (dolist (elem- _frames)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get can_msgs::Frames :md5sum-) "a652a31438717760a5dd3f589c696e07")
(setf (get can_msgs::Frames :datatype-) "can_msgs/Frames")
(setf (get can_msgs::Frames :definition-)
      "Header header
Frame[] frames
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
MSG: can_msgs/Frame
Header header
uint32 id
bool is_rtr
bool is_extended
bool is_error
uint8 dlc
uint8[8] data
")



(provide :can_msgs/Frames "a652a31438717760a5dd3f589c696e07")


