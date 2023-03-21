;; Auto-generated. Do not edit!


(when (boundp 'common_msgs::StopDecision)
  (if (not (find-package "COMMON_MSGS"))
    (make-package "COMMON_MSGS"))
  (shadow 'StopDecision (find-package "COMMON_MSGS")))
(unless (find-package "COMMON_MSGS::STOPDECISION")
  (make-package "COMMON_MSGS::STOPDECISION"))

(in-package "ROS")
;;//! \htmlinclude StopDecision.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass common_msgs::StopDecision
  :super ros::object
  :slots (_header _veh_stop_flag ))

(defmethod common_msgs::StopDecision
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:veh_stop_flag __veh_stop_flag) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _veh_stop_flag (round __veh_stop_flag))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:veh_stop_flag
   (&optional __veh_stop_flag)
   (if __veh_stop_flag (setq _veh_stop_flag __veh_stop_flag)) _veh_stop_flag)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32 _veh_stop_flag
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32 _veh_stop_flag
       (write-long _veh_stop_flag s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32 _veh_stop_flag
     (setq _veh_stop_flag (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get common_msgs::StopDecision :md5sum-) "40185f333e9db25a8a2ac70bc6903e53")
(setf (get common_msgs::StopDecision :datatype-) "common_msgs/StopDecision")
(setf (get common_msgs::StopDecision :definition-)
      "std_msgs/Header header
int32 veh_stop_flag
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

")



(provide :common_msgs/StopDecision "40185f333e9db25a8a2ac70bc6903e53")


