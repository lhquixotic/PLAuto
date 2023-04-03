// Auto-generated. Do not edit!

// (in-package common_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let PlatoonState = require('./PlatoonState.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class V2V {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.platoon_info = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('platoon_info')) {
        this.platoon_info = initObj.platoon_info
      }
      else {
        this.platoon_info = new PlatoonState();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type V2V
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [platoon_info]
    bufferOffset = PlatoonState.serialize(obj.platoon_info, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type V2V
    let len;
    let data = new V2V(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [platoon_info]
    data.platoon_info = PlatoonState.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += PlatoonState.getMessageSize(object.platoon_info);
    return length;
  }

  static datatype() {
    // Returns string type for a message object
    return 'common_msgs/V2V';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '84dd78ba72f6eb4041f0491a6158eda6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    
    common_msgs/PlatoonState platoon_info
    
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
    MSG: common_msgs/PlatoonState
    std_msgs/Header header
    
    # member vehicle state
    common_msgs/VehicleState[] vehicles
    ================================================================================
    MSG: common_msgs/VehicleState
    # Id of the vehicle
    std_msgs/Header header 
    
    # Basic info of the vehicle
    
    # Odometry info of the vehicle
    nav_msgs/Odometry odom
    
    # Dynamic state of vehicle
    common_msgs/VehicleDynamicState dynamics
    
    # Chassis state of vehicle
    common_msgs/ChassisState chassis
    
    ================================================================================
    MSG: nav_msgs/Odometry
    # This represents an estimate of a position and velocity in free space.  
    # The pose in this message should be specified in the coordinate frame given by header.frame_id.
    # The twist in this message should be specified in the coordinate frame given by the child_frame_id
    Header header
    string child_frame_id
    geometry_msgs/PoseWithCovariance pose
    geometry_msgs/TwistWithCovariance twist
    
    ================================================================================
    MSG: geometry_msgs/PoseWithCovariance
    # This represents a pose in free space with uncertainty.
    
    Pose pose
    
    # Row-major representation of the 6x6 covariance matrix
    # The orientation parameters use a fixed-axis representation.
    # In order, the parameters are:
    # (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
    float64[36] covariance
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    ================================================================================
    MSG: geometry_msgs/TwistWithCovariance
    # This expresses velocity in free space with uncertainty.
    
    Twist twist
    
    # Row-major representation of the 6x6 covariance matrix
    # The orientation parameters use a fixed-axis representation.
    # In order, the parameters are:
    # (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
    float64[36] covariance
    
    ================================================================================
    MSG: geometry_msgs/Twist
    # This expresses velocity in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    ================================================================================
    MSG: common_msgs/VehicleDynamicState
    std_msgs/Header  header
    
    float32 lon_speed
    float32 lon_accel
    float32 lat_speed
    float32 lat_accel
    float32 yaw_rate
    float32 yaw_accel
    ================================================================================
    MSG: common_msgs/ChassisState
    std_msgs/Header header
    
    # real acc throttle value
    float32 throttle
    
    # real brake pressure
    float32 brake
    
    # vehicle run mode
    uint8 run_mode
    
    # Level of accelaration, unit in m/s^2, throttle is positive, braking is negative
    float32 accel
    
    # Level of steering on front wheel, unit in radian, left turning is positive
    float32 steer
    
    # Gear
    int8 gear
    
    # Parking
    bool parking_brake
    
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new V2V(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.platoon_info !== undefined) {
      resolved.platoon_info = PlatoonState.Resolve(msg.platoon_info)
    }
    else {
      resolved.platoon_info = new PlatoonState()
    }

    return resolved;
    }
};

module.exports = V2V;
