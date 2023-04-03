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
      this.lon_accel = null;
      this.lat_speed = null;
      this.lat_accel = null;
      this.yaw_rate = null;
      this.yaw_accel = null;
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
      if (initObj.hasOwnProperty('lon_accel')) {
        this.lon_accel = initObj.lon_accel
      }
      else {
        this.lon_accel = 0.0;
      }
      if (initObj.hasOwnProperty('lat_speed')) {
        this.lat_speed = initObj.lat_speed
      }
      else {
        this.lat_speed = 0.0;
      }
      if (initObj.hasOwnProperty('lat_accel')) {
        this.lat_accel = initObj.lat_accel
      }
      else {
        this.lat_accel = 0.0;
      }
      if (initObj.hasOwnProperty('yaw_rate')) {
        this.yaw_rate = initObj.yaw_rate
      }
      else {
        this.yaw_rate = 0.0;
      }
      if (initObj.hasOwnProperty('yaw_accel')) {
        this.yaw_accel = initObj.yaw_accel
      }
      else {
        this.yaw_accel = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type VehicleDynamicState
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [lon_speed]
    bufferOffset = _serializer.float32(obj.lon_speed, buffer, bufferOffset);
    // Serialize message field [lon_accel]
    bufferOffset = _serializer.float32(obj.lon_accel, buffer, bufferOffset);
    // Serialize message field [lat_speed]
    bufferOffset = _serializer.float32(obj.lat_speed, buffer, bufferOffset);
    // Serialize message field [lat_accel]
    bufferOffset = _serializer.float32(obj.lat_accel, buffer, bufferOffset);
    // Serialize message field [yaw_rate]
    bufferOffset = _serializer.float32(obj.yaw_rate, buffer, bufferOffset);
    // Serialize message field [yaw_accel]
    bufferOffset = _serializer.float32(obj.yaw_accel, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type VehicleDynamicState
    let len;
    let data = new VehicleDynamicState(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [lon_speed]
    data.lon_speed = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [lon_accel]
    data.lon_accel = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [lat_speed]
    data.lat_speed = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [lat_accel]
    data.lat_accel = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [yaw_rate]
    data.yaw_rate = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [yaw_accel]
    data.yaw_accel = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'common_msgs/VehicleDynamicState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd3015605eb810e5c79a5de962cc9f172';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header  header
    
    float32 lon_speed
    float32 lon_accel
    float32 lat_speed
    float32 lat_accel
    float32 yaw_rate
    float32 yaw_accel
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

    if (msg.lon_accel !== undefined) {
      resolved.lon_accel = msg.lon_accel;
    }
    else {
      resolved.lon_accel = 0.0
    }

    if (msg.lat_speed !== undefined) {
      resolved.lat_speed = msg.lat_speed;
    }
    else {
      resolved.lat_speed = 0.0
    }

    if (msg.lat_accel !== undefined) {
      resolved.lat_accel = msg.lat_accel;
    }
    else {
      resolved.lat_accel = 0.0
    }

    if (msg.yaw_rate !== undefined) {
      resolved.yaw_rate = msg.yaw_rate;
    }
    else {
      resolved.yaw_rate = 0.0
    }

    if (msg.yaw_accel !== undefined) {
      resolved.yaw_accel = msg.yaw_accel;
    }
    else {
      resolved.yaw_accel = 0.0
    }

    return resolved;
    }
};

module.exports = VehicleDynamicState;
