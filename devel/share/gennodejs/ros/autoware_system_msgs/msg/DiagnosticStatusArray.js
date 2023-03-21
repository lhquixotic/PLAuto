// Auto-generated. Do not edit!

// (in-package autoware_system_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let DiagnosticStatus = require('./DiagnosticStatus.js');

//-----------------------------------------------------------

class DiagnosticStatusArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.status = null;
    }
    else {
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DiagnosticStatusArray
    // Serialize message field [status]
    // Serialize the length for message field [status]
    bufferOffset = _serializer.uint32(obj.status.length, buffer, bufferOffset);
    obj.status.forEach((val) => {
      bufferOffset = DiagnosticStatus.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DiagnosticStatusArray
    let len;
    let data = new DiagnosticStatusArray(null);
    // Deserialize message field [status]
    // Deserialize array length for message field [status]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.status = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.status[i] = DiagnosticStatus.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.status.forEach((val) => {
      length += DiagnosticStatus.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'autoware_system_msgs/DiagnosticStatusArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3630b28b658945d3148aa0b60b9f7af0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    autoware_system_msgs/DiagnosticStatus[] status
    ================================================================================
    MSG: autoware_system_msgs/DiagnosticStatus
    Header header
    
    string key
    
    string value
    
    string description
    
    uint8 UNDEFINED = 0
    
    uint8 type
    uint8 OUT_OF_RANGE = 1
    uint8 UNEXPECTED_RATE = 2
    uint8 INVALID_VALUE = 3
    uint8 INTERNAL = 4
    uint8 FUNCTIONAL = 100
    uint8 HARDWARE = 200
    
    uint8 level
    uint8 OK = 1
    uint8 WARN = 2
    uint8 ERROR = 3
    uint8 FATAL = 4
    
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
    const resolved = new DiagnosticStatusArray(null);
    if (msg.status !== undefined) {
      resolved.status = new Array(msg.status.length);
      for (let i = 0; i < resolved.status.length; ++i) {
        resolved.status[i] = DiagnosticStatus.Resolve(msg.status[i]);
      }
    }
    else {
      resolved.status = []
    }

    return resolved;
    }
};

module.exports = DiagnosticStatusArray;
