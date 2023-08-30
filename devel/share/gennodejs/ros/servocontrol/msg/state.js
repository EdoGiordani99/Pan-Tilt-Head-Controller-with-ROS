// Auto-generated. Do not edit!

// (in-package servocontrol.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class state {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.last_cmd = null;
      this.step = null;
      this.speed = null;
      this.x = null;
      this.y = null;
    }
    else {
      if (initObj.hasOwnProperty('last_cmd')) {
        this.last_cmd = initObj.last_cmd
      }
      else {
        this.last_cmd = '';
      }
      if (initObj.hasOwnProperty('step')) {
        this.step = initObj.step
      }
      else {
        this.step = 0;
      }
      if (initObj.hasOwnProperty('speed')) {
        this.speed = initObj.speed
      }
      else {
        this.speed = 0.0;
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type state
    // Serialize message field [last_cmd]
    bufferOffset = _serializer.string(obj.last_cmd, buffer, bufferOffset);
    // Serialize message field [step]
    bufferOffset = _serializer.uint8(obj.step, buffer, bufferOffset);
    // Serialize message field [speed]
    bufferOffset = _serializer.float32(obj.speed, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.uint8(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.uint8(obj.y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type state
    let len;
    let data = new state(null);
    // Deserialize message field [last_cmd]
    data.last_cmd = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [step]
    data.step = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [speed]
    data.speed = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.last_cmd);
    return length + 11;
  }

  static datatype() {
    // Returns string type for a message object
    return 'servocontrol/state';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c95f0a0c1b57d8b8eaffcee8de0dcceb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string last_cmd
    uint8 step
    float32 speed
    uint8 x
    uint8 y
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new state(null);
    if (msg.last_cmd !== undefined) {
      resolved.last_cmd = msg.last_cmd;
    }
    else {
      resolved.last_cmd = ''
    }

    if (msg.step !== undefined) {
      resolved.step = msg.step;
    }
    else {
      resolved.step = 0
    }

    if (msg.speed !== undefined) {
      resolved.speed = msg.speed;
    }
    else {
      resolved.speed = 0.0
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0
    }

    return resolved;
    }
};

module.exports = state;
