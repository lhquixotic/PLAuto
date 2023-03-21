
(cl:in-package :asdf)

(defsystem "autoware_system_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :rosgraph_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "DiagnosticStatus" :depends-on ("_package_DiagnosticStatus"))
    (:file "_package_DiagnosticStatus" :depends-on ("_package"))
    (:file "DiagnosticStatusArray" :depends-on ("_package_DiagnosticStatusArray"))
    (:file "_package_DiagnosticStatusArray" :depends-on ("_package"))
    (:file "HardwareStatus" :depends-on ("_package_HardwareStatus"))
    (:file "_package_HardwareStatus" :depends-on ("_package"))
    (:file "NodeStatus" :depends-on ("_package_NodeStatus"))
    (:file "_package_NodeStatus" :depends-on ("_package"))
    (:file "SystemStatus" :depends-on ("_package_SystemStatus"))
    (:file "_package_SystemStatus" :depends-on ("_package"))
  ))