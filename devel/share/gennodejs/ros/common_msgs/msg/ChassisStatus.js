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

class ChassisStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.real_throttle = null;
      this.real_brake_pressure = null;
      this.real_steer_angle = null;
      this.vehicle_run_mode = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('real_throttle')) {
        this.real_throttle = initObj.real_throttle
      }
      else {
        this.real_throttle = 0;
      }
      if (initObj.hasOwnProperty('real_brake_pressure')) {
        this.real_brake_pressure = initObj.real_brake_pressure
      }
      else {
        this.real_brake_pressure = 0;
      }
      if (initObj.hasOwnProperty('real_steer_angle')) {
        this.real_steer_angle = initObj.real_steer_angle
      }
      else {
        this.real_steer_angle = 0.0;
      }
      if (initObj.hasOwnProperty('vehicle_run_mode')) {
        this.vehicle_run_mode = initObj.vehicle_run_mode
      }
      else {
        this.vehicle_run_mode = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ChassisStatus
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [real_throttle]
    bufferOffset = _serializer.uint8(obj.real_throttle, buffer, bufferOffset);
    // Serialize message field [real_brake_pressure]
    bufferOffset = _serializer.uint8(obj.real_brake_pressure, buffer, bufferOffset);
    // Serialize message field [real_steer_angle]
    bufferOffset = _serializer.float64(obj.real_steer_angle, buffer, bufferOffset);
    // Serialize message field [vehicle_run_mode]
    bufferOffset = _serializer.uint8(obj.vehicle_run_mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ChassisStatus
    let len;
    let data = new ChassisStatus(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [real_throttle]
    data.real_throttle = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [real_brake_pressure]
    data.real_brake_pressure = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [real_steer_angle]
    data.real_steer_angle = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [vehicle_run_mode]
    data.vehicle_run_mode = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 11;
  }

  static datatype() {
    // Returns string type for a message object
    return 'common_msgs/ChassisStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3318ade59e28d0d24b09394333e12cbc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    
    # real acc throttle value
    uint8 real_throttle
    
    # real brake pressure
    uint8 real_brake_pressure
    
    # real steer angle
    float64 real_steer_angle
    
    # vehicle run mode
    uint8 vehicle_run_mode
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
    const resolved = new ChassisStatus(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.real_throttle !== undefined) {
      resolved.real_throttle = msg.real_throttle;
    }
    else {
      resolved.real_throttle = 0
    }

    if (msg.real_brake_pressure !== undefined) {
      resolved.real_brake_pressure = msg.real_brake_pressure;
    }
    else {
      resolved.real_brake_pressure = 0
    }

    if (msg.real_steer_angle !== undefined) {
      resolved.real_steer_angle = msg.real_steer_angle;
    }
    else {
      resolved.real_steer_angle = 0.0
    }

    if (msg.vehicle_run_mode !== undefined) {
      resolved.vehicle_run_mode = msg.vehicle_run_mode;
    }
    else {
      resolved.vehicle_run_mode = 0
    }

    return resolved;
    }
};

module.exports = ChassisStatus;
