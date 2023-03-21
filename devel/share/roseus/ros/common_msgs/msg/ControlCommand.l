;; Auto-generated. Do not edit!


(when (boundp 'common_msgs::ControlCommand)
  (if (not (find-package "COMMON_MSGS"))
    (make-package "COMMON_MSGS"))
  (shadow 'ControlCommand (find-package "COMMON_MSGS")))
(unless (find-package "COMMON_MSGS::CONTROLCOMMAND")
  (make-package "COMMON_MSGS::CONTROLCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude ControlCommand.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*GEAR_NONE*" (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(shadow '*GEAR_NONE* (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(defconstant common_msgs::ControlCommand::*GEAR_NONE* 0)
(intern "*GEAR_NEUTRAL*" (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(shadow '*GEAR_NEUTRAL* (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(defconstant common_msgs::ControlCommand::*GEAR_NEUTRAL* -1)
(intern "*GEAR_REVERSE*" (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(shadow '*GEAR_REVERSE* (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(defconstant common_msgs::ControlCommand::*GEAR_REVERSE* -2)
(intern "*GEAR_PARKING*" (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(shadow '*GEAR_PARKING* (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(defconstant common_msgs::ControlCommand::*GEAR_PARKING* -3)
(intern "*GEAR_DRIVE*" (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(shadow '*GEAR_DRIVE* (find-package "COMMON_MSGS::CONTROLCOMMAND"))
(defconstant common_msgs::ControlCommand::*GEAR_DRIVE* -4)

(defun common_msgs::ControlCommand-to-symbol (const)
  (cond
        ((= const 0) 'common_msgs::ControlCommand::*GEAR_NONE*)
        ((= const -1) 'common_msgs::ControlCommand::*GEAR_NEUTRAL*)
        ((= const -2) 'common_msgs::ControlCommand::*GEAR_REVERSE*)
        ((= const -3) 'common_msgs::ControlCommand::*GEAR_PARKING*)
        ((= const -4) 'common_msgs::ControlCommand::*GEAR_DRIVE*)
        (t nil)))

(defclass common_msgs::ControlCommand
  :super ros::object
  :slots (_header _accel _steer _gear _parking_brake ))

(defmethod common_msgs::ControlCommand
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:accel __accel) 0.0)
    ((:steer __steer) 0.0)
    ((:gear __gear) 0)
    ((:parking_brake __parking_brake) nil)
    )
   (send-super :init)
   (setq _header __header)
   (setq _accel (float __accel))
   (setq _steer (float __steer))
   (setq _gear (round __gear))
   (setq _parking_brake __parking_brake)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:accel
   (&optional __accel)
   (if __accel (setq _accel __accel)) _accel)
  (:steer
   (&optional __steer)
   (if __steer (setq _steer __steer)) _steer)
  (:gear
   (&optional __gear)
   (if __gear (setq _gear __gear)) _gear)
  (:parking_brake
   (&optional (__parking_brake :null))
   (if (not (eq __parking_brake :null)) (setq _parking_brake __parking_brake)) _parking_brake)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _accel
    4
    ;; float32 _steer
    4
    ;; int8 _gear
    1
    ;; bool _parking_brake
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _accel
       (sys::poke _accel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _steer
       (sys::poke _steer (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int8 _gear
       (write-byte _gear s)
     ;; bool _parking_brake
       (if _parking_brake (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _accel
     (setq _accel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _steer
     (setq _steer (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int8 _gear
     (setq _gear (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _gear 127) (setq _gear (- _gear 256)))
   ;; bool _parking_brake
     (setq _parking_brake (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get common_msgs::ControlCommand :md5sum-) "9e9243dea74c7ce1ca4f84c368334f51")
(setf (get common_msgs::ControlCommand :datatype-) "common_msgs/ControlCommand")
(setf (get common_msgs::ControlCommand :definition-)
      "# Adapted from CLAP (https://github.com/CLAP-Framework/clap)
Header header

# Level of accelaration, unit in m/s^2, throttle is positive, braking is negative
float32 accel

# Level of steering on front wheel, unit in radian, left turning is positive
float32 steer

# Gear shift, positive means manual transmission, negative means automatic transmission
int8 gear
int8 GEAR_NONE = 0
int8 GEAR_NEUTRAL = -1
int8 GEAR_REVERSE = -2
int8 GEAR_PARKING = -3
int8 GEAR_DRIVE = -4

# Parking brake switch
bool parking_brake

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



(provide :common_msgs/ControlCommand "9e9243dea74c7ce1ca4f84c368334f51")


