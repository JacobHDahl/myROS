// Auto-generated. Do not edit!

// (in-package random_node.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Num {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.start = null;
      this.num2 = null;
      this.num1 = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('start')) {
        this.start = initObj.start
      }
      else {
        this.start = new std_msgs.msg.Time();
      }
      if (initObj.hasOwnProperty('num2')) {
        this.num2 = initObj.num2
      }
      else {
        this.num2 = 0;
      }
      if (initObj.hasOwnProperty('num1')) {
        this.num1 = initObj.num1
      }
      else {
        this.num1 = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Num
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [start]
    bufferOffset = std_msgs.msg.Time.serialize(obj.start, buffer, bufferOffset);
    // Serialize message field [num2]
    bufferOffset = _serializer.int16(obj.num2, buffer, bufferOffset);
    // Serialize message field [num1]
    bufferOffset = _serializer.int16(obj.num1, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Num
    let len;
    let data = new Num(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [start]
    data.start = std_msgs.msg.Time.deserialize(buffer, bufferOffset);
    // Deserialize message field [num2]
    data.num2 = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [num1]
    data.num1 = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'random_node/Num';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5ab4760c592fe1830e3587fa9b42e8b1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/Time start
    int16 num2
    int16 num1
    
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
    # 0: no frame
    # 1: global frame
    string frame_id
    
    ================================================================================
    MSG: std_msgs/Time
    time data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Num(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.start !== undefined) {
      resolved.start = std_msgs.msg.Time.Resolve(msg.start)
    }
    else {
      resolved.start = new std_msgs.msg.Time()
    }

    if (msg.num2 !== undefined) {
      resolved.num2 = msg.num2;
    }
    else {
      resolved.num2 = 0
    }

    if (msg.num1 !== undefined) {
      resolved.num1 = msg.num1;
    }
    else {
      resolved.num1 = 0
    }

    return resolved;
    }
};

module.exports = Num;
