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

//-----------------------------------------------------------

class VehicleDynamicState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.lon_speed = null;
      this.lon_acceleration = null;
      this.lat_speed = null;
      this.lat_acceleration = null;
      this.yaw_rate = null;
      this.yaw_acceleration = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('lon_speed')) {
        this.lon_speed = initObj.lon_speed
      }
      else {
        this.lon_speed = 0.0;
      }
      if (initObj.hasOwnProperty('lon_acceleration')) {
        this.lon_acceleration = initObj.lon_acceleration
      }
      else {
        this.lon_acceleration = 0.0;
      }
      if (initObj.hasOwnProperty('lat_speed')) {
        this.lat_speed = initObj.lat_speed
      }
      else {
        this.lat_speed = 0.0;
      }
      if (initObj.hasOwnProperty('lat_acceleration')) {
        this.lat_acceleration = initObj.lat_acceleration
      }
      else {
        this.lat_acceleration = 0.0;
      }
      if (initObj.hasOwnProperty('yaw_rate')) {
        this.yaw_rate = initObj.yaw_rate
      }
      else {
        this.yaw_rate = 0.0;
      }
      if (initObj.hasOwnProperty('yaw_acceleration')) {
        this.yaw_acceleration = initObj.yaw_acceleration
      }
      else {
        this.yaw_acceleration = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type VehicleDynamicState
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [lon_speed]
    bufferOffset = _serializer.float64(obj.lon_speed, buffer, bufferOffset);
    // Serialize message field [lon_acceleration]
    bufferOffset = _serializer.float64(obj.lon_acceleration, buffer, bufferOffset);
    // Serialize message field [lat_speed]
    bufferOffset = _serializer.float64(obj.lat_speed, buffer, bufferOffset);
    // Serialize message field [lat_acceleration]
    bufferOffset = _serializer.float64(obj.lat_acceleration, buffer, bufferOffset);
    // Serialize message field [yaw_rate]
    bufferOffset = _serializer.float64(obj.yaw_rate, buffer, bufferOffset);
    // Serialize message field [yaw_acceleration]
    bufferOffset = _serializer.float64(obj.yaw_acceleration, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type VehicleDynamicState
    let len;
    let data = new VehicleDynamicState(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [lon_speed]
    data.lon_speed = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [lon_acceleration]
    data.lon_acceleration = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [lat_speed]
    data.lat_speed = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [lat_acceleration]
    data.lat_acceleration = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yaw_rate]
    data.yaw_rate = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yaw_acceleration]
    data.yaw_acceleration = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'common_msgs/VehicleDynamicState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '543c8cc51ef4a96b419de72eeff8a6e9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header  header
    
    float64 lon_speed
    float64 lon_acceleration
    float64 lat_speed
    float64 lat_acceleration
    float64 yaw_rate
    float64 yaw_acceleration
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new VehicleDynamicState(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.lon_speed !== undefined) {
      resolved.lon_speed = msg.lon_speed;
    }
    else {
      resolved.lon_speed = 0.0
    }

    if (msg.lon_acceleration !== undefined) {
      resolved.lon_acceleration = msg.lon_acceleration;
    }
    else {
      resolved.lon_acceleration = 0.0
    }

    if (msg.lat_speed !== undefined) {
      resolved.lat_speed = msg.lat_speed;
    }
    else {
      resolved.lat_speed = 0.0
    }

    if (msg.lat_acceleration !== undefined) {
      resolved.lat_acceleration = msg.lat_acceleration;
    }
    else {
      resolved.lat_acceleration = 0.0
    }

    if (msg.yaw_rate !== undefined) {
      resolved.yaw_rate = msg.yaw_rate;
    }
    else {
      resolved.yaw_rate = 0.0
    }

    if (msg.yaw_acceleration !== undefined) {
      resolved.yaw_acceleration = msg.yaw_acceleration;
    }
    else {
      resolved.yaw_acceleration = 0.0
    }

    return resolved;
    }
};

module.exports = VehicleDynamicState;
