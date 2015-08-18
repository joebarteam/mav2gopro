// MESSAGE EXTERN_GPS_POSITION PACKING

#define MAVLINK_MSG_ID_EXTERN_GPS_POSITION 151

typedef struct __mavlink_extern_gps_position_t
{
 double value1double; ///< value1
 double value2double; ///< value2
 double value3double; ///< value3
 float value1float; ///< value4
 float value2float; ///< value5
 float value3float; ///< value6
 float value4float; ///< value7
 float value5float; ///< value8
 float value6float; ///< value9
 float value7float; ///< value10
 float value8float; ///< value11
 float value9float; ///< value12
 float value10float; ///< value13
 float value11float; ///< value14
 float value12float; ///< value15
 uint16_t index; ///< Index of message
} mavlink_extern_gps_position_t;

#define MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN 74
#define MAVLINK_MSG_ID_151_LEN 74

#define MAVLINK_MSG_ID_EXTERN_GPS_POSITION_CRC 196
#define MAVLINK_MSG_ID_151_CRC 196



#define MAVLINK_MESSAGE_INFO_EXTERN_GPS_POSITION { \
	"EXTERN_GPS_POSITION", \
	16, \
	{  { "value1double", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_extern_gps_position_t, value1double) }, \
         { "value2double", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_extern_gps_position_t, value2double) }, \
         { "value3double", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_extern_gps_position_t, value3double) }, \
         { "value1float", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_extern_gps_position_t, value1float) }, \
         { "value2float", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_extern_gps_position_t, value2float) }, \
         { "value3float", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_extern_gps_position_t, value3float) }, \
         { "value4float", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_extern_gps_position_t, value4float) }, \
         { "value5float", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_extern_gps_position_t, value5float) }, \
         { "value6float", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_extern_gps_position_t, value6float) }, \
         { "value7float", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_extern_gps_position_t, value7float) }, \
         { "value8float", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_extern_gps_position_t, value8float) }, \
         { "value9float", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_extern_gps_position_t, value9float) }, \
         { "value10float", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_extern_gps_position_t, value10float) }, \
         { "value11float", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_extern_gps_position_t, value11float) }, \
         { "value12float", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_extern_gps_position_t, value12float) }, \
         { "index", NULL, MAVLINK_TYPE_UINT16_T, 0, 72, offsetof(mavlink_extern_gps_position_t, index) }, \
         } \
}


/**
 * @brief Pack a extern_gps_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index Index of message
 * @param value1double value1
 * @param value2double value2
 * @param value3double value3
 * @param value1float value4
 * @param value2float value5
 * @param value3float value6
 * @param value4float value7
 * @param value5float value8
 * @param value6float value9
 * @param value7float value10
 * @param value8float value11
 * @param value9float value12
 * @param value10float value13
 * @param value11float value14
 * @param value12float value15
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_extern_gps_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t index, double value1double, double value2double, double value3double, float value1float, float value2float, float value3float, float value4float, float value5float, float value6float, float value7float, float value8float, float value9float, float value10float, float value11float, float value12float)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN];
	_mav_put_double(buf, 0, value1double);
	_mav_put_double(buf, 8, value2double);
	_mav_put_double(buf, 16, value3double);
	_mav_put_float(buf, 24, value1float);
	_mav_put_float(buf, 28, value2float);
	_mav_put_float(buf, 32, value3float);
	_mav_put_float(buf, 36, value4float);
	_mav_put_float(buf, 40, value5float);
	_mav_put_float(buf, 44, value6float);
	_mav_put_float(buf, 48, value7float);
	_mav_put_float(buf, 52, value8float);
	_mav_put_float(buf, 56, value9float);
	_mav_put_float(buf, 60, value10float);
	_mav_put_float(buf, 64, value11float);
	_mav_put_float(buf, 68, value12float);
	_mav_put_uint16_t(buf, 72, index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN);
#else
	mavlink_extern_gps_position_t packet;
	packet.value1double = value1double;
	packet.value2double = value2double;
	packet.value3double = value3double;
	packet.value1float = value1float;
	packet.value2float = value2float;
	packet.value3float = value3float;
	packet.value4float = value4float;
	packet.value5float = value5float;
	packet.value6float = value6float;
	packet.value7float = value7float;
	packet.value8float = value8float;
	packet.value9float = value9float;
	packet.value10float = value10float;
	packet.value11float = value11float;
	packet.value12float = value12float;
	packet.index = index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_EXTERN_GPS_POSITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN);
#endif
}

/**
 * @brief Pack a extern_gps_position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param index Index of message
 * @param value1double value1
 * @param value2double value2
 * @param value3double value3
 * @param value1float value4
 * @param value2float value5
 * @param value3float value6
 * @param value4float value7
 * @param value5float value8
 * @param value6float value9
 * @param value7float value10
 * @param value8float value11
 * @param value9float value12
 * @param value10float value13
 * @param value11float value14
 * @param value12float value15
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_extern_gps_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t index,double value1double,double value2double,double value3double,float value1float,float value2float,float value3float,float value4float,float value5float,float value6float,float value7float,float value8float,float value9float,float value10float,float value11float,float value12float)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN];
	_mav_put_double(buf, 0, value1double);
	_mav_put_double(buf, 8, value2double);
	_mav_put_double(buf, 16, value3double);
	_mav_put_float(buf, 24, value1float);
	_mav_put_float(buf, 28, value2float);
	_mav_put_float(buf, 32, value3float);
	_mav_put_float(buf, 36, value4float);
	_mav_put_float(buf, 40, value5float);
	_mav_put_float(buf, 44, value6float);
	_mav_put_float(buf, 48, value7float);
	_mav_put_float(buf, 52, value8float);
	_mav_put_float(buf, 56, value9float);
	_mav_put_float(buf, 60, value10float);
	_mav_put_float(buf, 64, value11float);
	_mav_put_float(buf, 68, value12float);
	_mav_put_uint16_t(buf, 72, index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN);
#else
	mavlink_extern_gps_position_t packet;
	packet.value1double = value1double;
	packet.value2double = value2double;
	packet.value3double = value3double;
	packet.value1float = value1float;
	packet.value2float = value2float;
	packet.value3float = value3float;
	packet.value4float = value4float;
	packet.value5float = value5float;
	packet.value6float = value6float;
	packet.value7float = value7float;
	packet.value8float = value8float;
	packet.value9float = value9float;
	packet.value10float = value10float;
	packet.value11float = value11float;
	packet.value12float = value12float;
	packet.index = index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_EXTERN_GPS_POSITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN);
#endif
}

/**
 * @brief Encode a extern_gps_position struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param extern_gps_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_extern_gps_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_extern_gps_position_t* extern_gps_position)
{
	return mavlink_msg_extern_gps_position_pack(system_id, component_id, msg, extern_gps_position->index, extern_gps_position->value1double, extern_gps_position->value2double, extern_gps_position->value3double, extern_gps_position->value1float, extern_gps_position->value2float, extern_gps_position->value3float, extern_gps_position->value4float, extern_gps_position->value5float, extern_gps_position->value6float, extern_gps_position->value7float, extern_gps_position->value8float, extern_gps_position->value9float, extern_gps_position->value10float, extern_gps_position->value11float, extern_gps_position->value12float);
}

/**
 * @brief Send a extern_gps_position message
 * @param chan MAVLink channel to send the message
 *
 * @param index Index of message
 * @param value1double value1
 * @param value2double value2
 * @param value3double value3
 * @param value1float value4
 * @param value2float value5
 * @param value3float value6
 * @param value4float value7
 * @param value5float value8
 * @param value6float value9
 * @param value7float value10
 * @param value8float value11
 * @param value9float value12
 * @param value10float value13
 * @param value11float value14
 * @param value12float value15
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_extern_gps_position_send(mavlink_channel_t chan, uint16_t index, double value1double, double value2double, double value3double, float value1float, float value2float, float value3float, float value4float, float value5float, float value6float, float value7float, float value8float, float value9float, float value10float, float value11float, float value12float)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN];
	_mav_put_double(buf, 0, value1double);
	_mav_put_double(buf, 8, value2double);
	_mav_put_double(buf, 16, value3double);
	_mav_put_float(buf, 24, value1float);
	_mav_put_float(buf, 28, value2float);
	_mav_put_float(buf, 32, value3float);
	_mav_put_float(buf, 36, value4float);
	_mav_put_float(buf, 40, value5float);
	_mav_put_float(buf, 44, value6float);
	_mav_put_float(buf, 48, value7float);
	_mav_put_float(buf, 52, value8float);
	_mav_put_float(buf, 56, value9float);
	_mav_put_float(buf, 60, value10float);
	_mav_put_float(buf, 64, value11float);
	_mav_put_float(buf, 68, value12float);
	_mav_put_uint16_t(buf, 72, index);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERN_GPS_POSITION, buf, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERN_GPS_POSITION, buf, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN);
#endif
#else
	mavlink_extern_gps_position_t packet;
	packet.value1double = value1double;
	packet.value2double = value2double;
	packet.value3double = value3double;
	packet.value1float = value1float;
	packet.value2float = value2float;
	packet.value3float = value3float;
	packet.value4float = value4float;
	packet.value5float = value5float;
	packet.value6float = value6float;
	packet.value7float = value7float;
	packet.value8float = value8float;
	packet.value9float = value9float;
	packet.value10float = value10float;
	packet.value11float = value11float;
	packet.value12float = value12float;
	packet.index = index;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERN_GPS_POSITION, (const char *)&packet, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERN_GPS_POSITION, (const char *)&packet, MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN);
#endif
#endif
}

#endif

// MESSAGE EXTERN_GPS_POSITION UNPACKING


/**
 * @brief Get field index from extern_gps_position message
 *
 * @return Index of message
 */
static inline uint16_t mavlink_msg_extern_gps_position_get_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  72);
}

/**
 * @brief Get field value1double from extern_gps_position message
 *
 * @return value1
 */
static inline double mavlink_msg_extern_gps_position_get_value1double(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  0);
}

/**
 * @brief Get field value2double from extern_gps_position message
 *
 * @return value2
 */
static inline double mavlink_msg_extern_gps_position_get_value2double(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field value3double from extern_gps_position message
 *
 * @return value3
 */
static inline double mavlink_msg_extern_gps_position_get_value3double(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field value1float from extern_gps_position message
 *
 * @return value4
 */
static inline float mavlink_msg_extern_gps_position_get_value1float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field value2float from extern_gps_position message
 *
 * @return value5
 */
static inline float mavlink_msg_extern_gps_position_get_value2float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field value3float from extern_gps_position message
 *
 * @return value6
 */
static inline float mavlink_msg_extern_gps_position_get_value3float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field value4float from extern_gps_position message
 *
 * @return value7
 */
static inline float mavlink_msg_extern_gps_position_get_value4float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field value5float from extern_gps_position message
 *
 * @return value8
 */
static inline float mavlink_msg_extern_gps_position_get_value5float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field value6float from extern_gps_position message
 *
 * @return value9
 */
static inline float mavlink_msg_extern_gps_position_get_value6float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field value7float from extern_gps_position message
 *
 * @return value10
 */
static inline float mavlink_msg_extern_gps_position_get_value7float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field value8float from extern_gps_position message
 *
 * @return value11
 */
static inline float mavlink_msg_extern_gps_position_get_value8float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field value9float from extern_gps_position message
 *
 * @return value12
 */
static inline float mavlink_msg_extern_gps_position_get_value9float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field value10float from extern_gps_position message
 *
 * @return value13
 */
static inline float mavlink_msg_extern_gps_position_get_value10float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field value11float from extern_gps_position message
 *
 * @return value14
 */
static inline float mavlink_msg_extern_gps_position_get_value11float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field value12float from extern_gps_position message
 *
 * @return value15
 */
static inline float mavlink_msg_extern_gps_position_get_value12float(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Decode a extern_gps_position message into a struct
 *
 * @param msg The message to decode
 * @param extern_gps_position C-struct to decode the message contents into
 */
static inline void mavlink_msg_extern_gps_position_decode(const mavlink_message_t* msg, mavlink_extern_gps_position_t* extern_gps_position)
{
#if MAVLINK_NEED_BYTE_SWAP
	extern_gps_position->value1double = mavlink_msg_extern_gps_position_get_value1double(msg);
	extern_gps_position->value2double = mavlink_msg_extern_gps_position_get_value2double(msg);
	extern_gps_position->value3double = mavlink_msg_extern_gps_position_get_value3double(msg);
	extern_gps_position->value1float = mavlink_msg_extern_gps_position_get_value1float(msg);
	extern_gps_position->value2float = mavlink_msg_extern_gps_position_get_value2float(msg);
	extern_gps_position->value3float = mavlink_msg_extern_gps_position_get_value3float(msg);
	extern_gps_position->value4float = mavlink_msg_extern_gps_position_get_value4float(msg);
	extern_gps_position->value5float = mavlink_msg_extern_gps_position_get_value5float(msg);
	extern_gps_position->value6float = mavlink_msg_extern_gps_position_get_value6float(msg);
	extern_gps_position->value7float = mavlink_msg_extern_gps_position_get_value7float(msg);
	extern_gps_position->value8float = mavlink_msg_extern_gps_position_get_value8float(msg);
	extern_gps_position->value9float = mavlink_msg_extern_gps_position_get_value9float(msg);
	extern_gps_position->value10float = mavlink_msg_extern_gps_position_get_value10float(msg);
	extern_gps_position->value11float = mavlink_msg_extern_gps_position_get_value11float(msg);
	extern_gps_position->value12float = mavlink_msg_extern_gps_position_get_value12float(msg);
	extern_gps_position->index = mavlink_msg_extern_gps_position_get_index(msg);
#else
	memcpy(extern_gps_position, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_EXTERN_GPS_POSITION_LEN);
#endif
}
