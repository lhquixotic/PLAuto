
(cl:in-package :asdf)

(defsystem "common_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :nav_msgs-msg
               :sensor_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ChassisState" :depends-on ("_package_ChassisState"))
    (:file "_package_ChassisState" :depends-on ("_package"))
    (:file "ControlCommand" :depends-on ("_package_ControlCommand"))
    (:file "_package_ControlCommand" :depends-on ("_package"))
    (:file "GpsInfo" :depends-on ("_package_GpsInfo"))
    (:file "_package_GpsInfo" :depends-on ("_package"))
    (:file "PlatoonState" :depends-on ("_package_PlatoonState"))
    (:file "_package_PlatoonState" :depends-on ("_package"))
    (:file "PolarBoundary" :depends-on ("_package_PolarBoundary"))
    (:file "_package_PolarBoundary" :depends-on ("_package"))
    (:file "StopDecision" :depends-on ("_package_StopDecision"))
    (:file "_package_StopDecision" :depends-on ("_package"))
    (:file "V2V" :depends-on ("_package_V2V"))
    (:file "_package_V2V" :depends-on ("_package"))
    (:file "VehicleDynamicState" :depends-on ("_package_VehicleDynamicState"))
    (:file "_package_VehicleDynamicState" :depends-on ("_package"))
    (:file "VehicleState" :depends-on ("_package_VehicleState"))
    (:file "_package_VehicleState" :depends-on ("_package"))
  ))