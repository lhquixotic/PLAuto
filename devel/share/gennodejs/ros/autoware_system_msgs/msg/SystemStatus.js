// Auto-generated. Do not edit!

// (in-package autoware_system_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let NodeStatus = require('./NodeStatus.js');
let HardwareStatus = require('./HardwareStatus.js');
let std_msgs = _finder('std_msgs');
let rosgraph_msgs = _finder('rosgraph_msgs');

//-----------------------------------------------------------

class SystemStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.available_nodes = null;
      this.detect_too_match_warning = null;
      this.node_status = null;
      this.hardware_status = null;
      this.topic_statistics = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('available_nodes')) {
        this.available_nodes = initObj.available_nodes
      }
      else {
        this.available_nodes = [];
      }
      if (initObj.hasOwnProperty('detect_too_match_warning')) {
        this.detect_too_match_warning = initObj.detect_too_match_warning
      }
      else {
        this.detect_too_match_warning = false;
      }
      if (initObj.hasOwnProperty('node_status')) {
        this.node_status = initObj.node_status
      }
      else {
        this.node_status = [];
      }
      if (initObj.hasOwnProperty('hardware_status')) {
        this.hardware_status = initObj.hardware_status
      }
      else {
        this.hardware_status = [];
      }
      if (initObj.hasOwnProperty('topic_statistics')) {
        this.topic_statistics = initObj.topic_statistics
      }
      else {
        this.topic_statistics = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SystemStatus
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [available_nodes]
    bufferOffset = _arraySerializer.string(obj.available_nodes, buffer, bufferOffset, null);
    // Serialize message field [detect_too_match_warning]
    bufferOffset = _serializer.bool(obj.detect_too_match_warning, buffer, bufferOffset);
    // Serialize message field [node_status]
    // Serialize the length for message field [node_status]
    bufferOffset = _serializer.uint32(obj.node_status.length, buffer, bufferOffset);
    obj.node_status.forEach((val) => {
      bufferOffset = NodeStatus.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [hardware_status]
    // Serialize the length for message field [hardware_status]
    bufferOffset = _serializer.uint32(obj.hardware_status.length, buffer, bufferOffset);
    obj.hardware_status.forEach((val) => {
      bufferOffset = HardwareStatus.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [topic_statistics]
    // Serialize the length for message field [topic_statistics]
    bufferOffset = _serializer.uint32(obj.topic_statistics.length, buffer, bufferOffset);
    obj.topic_statistics.forEach((val) => {
      bufferOffset = rosgraph_msgs.msg.TopicStatistics.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SystemStatus
    let len;
    let data = new SystemStatus(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [available_nodes]
    data.available_nodes = _arrayDeserializer.string(buffer, bufferOffset, null)
    // Deserialize message field [detect_too_match_warning]
    data.detect_too_match_warning = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [node_status]
    // Deserialize array length for message field [node_status]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.node_status = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.node_status[i] = NodeStatus.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [hardware_status]
    // Deserialize array length for message field [hardware_status]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.hardware_status = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.hardware_status[i] = HardwareStatus.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [topic_statistics]
    // Deserialize array length for message field [topic_statistics]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.topic_statistics = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.topic_statistics[i] = rosgraph_msgs.msg.TopicStatistics.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.available_nodes.forEach((val) => {
      length += 4 + _getByteLength(val);
    });
    object.node_status.forEach((val) => {
      length += NodeStatus.getMessageSize(val);
    });
    object.hardware_status.forEach((val) => {
      length += HardwareStatus.getMessageSize(val);
    });
    object.topic_statistics.forEach((val) => {
      length += rosgraph_msgs.msg.TopicStatistics.getMessageSize(val);
    });
    return length + 17;
  }

  static datatype() {
    // Returns string type for a message object
    return 'autoware_system_msgs/SystemStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7daf3e9d5c454c414ddc765307bd564d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    string[] available_nodes
    bool detect_too_match_warning
    autoware_system_msgs/NodeStatus[] node_status
    autoware_system_msgs/HardwareStatus[] hardware_status
    rosgraph_msgs/TopicStatistics[] topic_statistics
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
    MSG: autoware_system_msgs/NodeStatus
    Header header
    string node_name
    bool node_activated
    autoware_system_msgs/DiagnosticStatusArray[] status
    ================================================================================
    MSG: autoware_system_msgs/DiagnosticStatusArray
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
    MSG: autoware_system_msgs/HardwareStatus
    std_msgs/Header header
    string hardware_name
    autoware_system_msgs/DiagnosticStatusArray[] status
    ================================================================================
    MSG: rosgraph_msgs/TopicStatistics
    # name of the topic
    string topic
    
    # node id of the publisher
    string node_pub
    
    # node id of the subscriber
    string node_sub
    
    # the statistics apply to this time window
    time window_start
    time window_stop
    
    # number of messages delivered during the window
    int32 delivered_msgs
    # numbers of messages dropped during the window
    int32 dropped_msgs
    
    # traffic during the window, in bytes
    int32 traffic
    
    # mean/stddev/max period between two messages
    duration period_mean
    duration period_stddev
    duration period_max
    
    # mean/stddev/max age of the message based on the
    # timestamp in the message header. In case the
    # message does not have a header, it will be 0.
    duration stamp_age_mean
    duration stamp_age_stddev
    duration stamp_age_max
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SystemStatus(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.available_nodes !== undefined) {
      resolved.available_nodes = msg.available_nodes;
    }
    else {
      resolved.available_nodes = []
    }

    if (msg.detect_too_match_warning !== undefined) {
      resolved.detect_too_match_warning = msg.detect_too_match_warning;
    }
    else {
      resolved.detect_too_match_warning = false
    }

    if (msg.node_status !== undefined) {
      resolved.node_status = new Array(msg.node_status.length);
      for (let i = 0; i < resolved.node_status.length; ++i) {
        resolved.node_status[i] = NodeStatus.Resolve(msg.node_status[i]);
      }
    }
    else {
      resolved.node_status = []
    }

    if (msg.hardware_status !== undefined) {
      resolved.hardware_status = new Array(msg.hardware_status.length);
      for (let i = 0; i < resolved.hardware_status.length; ++i) {
        resolved.hardware_status[i] = HardwareStatus.Resolve(msg.hardware_status[i]);
      }
    }
    else {
      resolved.hardware_status = []
    }

    if (msg.topic_statistics !== undefined) {
      resolved.topic_statistics = new Array(msg.topic_statistics.length);
      for (let i = 0; i < resolved.topic_statistics.length; ++i) {
        resolved.topic_statistics[i] = rosgraph_msgs.msg.TopicStatistics.Resolve(msg.topic_statistics[i]);
      }
    }
    else {
      resolved.topic_statistics = []
    }

    return resolved;
    }
};

module.exports = SystemStatus;
