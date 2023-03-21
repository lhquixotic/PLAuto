// Auto-generated. Do not edit!

// (in-package common_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');
let nav_msgs = _finder('nav_msgs');

//-----------------------------------------------------------

class V2V {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.odom = null;
      this.leader_speed = null;
      this.leader_acc = null;
      this.leader_acc_pedal = null;
      this.leader_brake_pedal = null;
      this.leader_frontwheel_angle = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('odom')) {
        this.odom = initObj.odom
      }
      else {
        this.odom = new nav_msgs.msg.Odometry();
      }
      if (initObj.hasOwnProperty('leader_speed')) {
        this.leader_speed = initObj.leader_speed
      }
      else {
        this.leader_speed = 0.0;
      }
      if (initObj.hasOwnProperty('leader_acc')) {
        this.leader_acc = initObj.leader_acc
      }
      else {
        this.leader_acc = 0.0;
      }
      if (initObj.hasOwnProperty('leader_acc_pedal')) {
        this.leader_acc_pedal = initObj.leader_acc_pedal
      }
      else {
        this.leader_acc_pedal = 0.0;
      }
      if (initObj.hasOwnProperty('leader_brake_pedal')) {
        this.leader_brake_pedal = initObj.leader_brake_pedal
      }
      else {
        this.leader_brake_pedal = 0.0;
      }
      if (initObj.hasOwnProperty('leader_frontwheel_angle')) {
        this.leader_frontwheel_angle = initObj.leader_frontwheel_angle
      }
      else {
        this.leader_frontwheel_angle = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type V2V
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [odom]
    bufferOffset = nav_msgs.msg.Odometry.serialize(obj.odom, buffer, bufferOffset);
    // Serialize message field [leader_speed]
    bufferOffset = _serializer.float64(obj.leader_speed, buffer, bufferOffset);
    // Serialize message field [leader_acc]
    bufferOffset = _serializer.float64(obj.leader_acc, buffer, bufferOffset);
    // Serialize message field [leader_acc_pedal]
    bufferOffset = _serializer.float64(obj.leader_acc_pedal, buffer, bufferOffset);
    // Serialize message field [leader_brake_pedal]
    bufferOffset = _serializer.float64(obj.leader_brake_pedal, buffer, bufferOffset);
    // Serialize message field [leader_frontwheel_angle]
    bufferOffset = _serializer.float64(obj.leader_frontwheel_angle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type V2V
    let len;
    let data = new V2V(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [odom]
    data.odom = nav_msgs.msg.Odometry.deserialize(buffer, bufferOffset);
    // Deserialize message field [leader_speed]
    data.leader_speed = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [leader_acc]
    data.leader_acc = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [leader_acc_pedal]
    data.leader_acc_pedal = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [leader_brake_pedal]
    data.leader_brake_pedal = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [leader_frontwheel_angle]
    data.leader_frontwheel_angle = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += nav_msgs.msg.Odometry.getMessageSize(object.odom);
    return length + 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'common_msgs/V2V';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5d3f3ce1d5d07abc8f4695c3e316dc23';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    #gpsinfo
    nav_msgs/Odometry odom
    #leader info
    float64 leader_speed
    float64 leader_acc
    float64 leader_acc_pedal
    float64 leader_brake_pedal
    float64 leader_frontwheel_angle
    
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

    if (msg.odom !== undefined) {
      resolved.odom = nav_msgs.msg.Odometry.Resolve(msg.odom)
    }
    else {
      resolved.odom = new nav_msgs.msg.Odometry()
    }

    if (msg.leader_speed !== undefined) {
      resolved.leader_speed = msg.leader_speed;
    }
    else {
      resolved.leader_speed = 0.0
    }

    if (msg.leader_acc !== undefined) {
      resolved.leader_acc = msg.leader_acc;
    }
    else {
      resolved.leader_acc = 0.0
    }

    if (msg.leader_acc_pedal !== undefined) {
      resolved.leader_acc_pedal = msg.leader_acc_pedal;
    }
    else {
      resolved.leader_acc_pedal = 0.0
    }

    if (msg.leader_brake_pedal !== undefined) {
      resolved.leader_brake_pedal = msg.leader_brake_pedal;
    }
    else {
      resolved.leader_brake_pedal = 0.0
    }

    if (msg.leader_frontwheel_angle !== undefined) {
      resolved.leader_frontwheel_angle = msg.leader_frontwheel_angle;
    }
    else {
      resolved.leader_frontwheel_angle = 0.0
    }

    return resolved;
    }
};

module.exports = V2V;
