// MESSAGE GOPRO_CONTROL PACKING

#define MAVLINK_MSG_ID_GOPRO_CONTROL 220

typedef struct __mavlink_gopro_control_t
{
 float extra_value; 		///< Correspondent value to given extra_param
 uint8_t target_system; 	///< System ID
 uint8_t target_component; 	///< Component ID
 uint8_t mode; 				/// GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps
 uint8_t video_size; 		///1: 720p, 2: 1080p, 3: 2k7, 4: 4k
 uint8_t video_fps; 		///1: 25 / 30 fps, 2: 50 / 60 fps, 3: 100 / 120 fps
 uint8_t video_fov; 		///1: wide, 2: medium, 3: narrow
 uint8_t battery; 			/// 0-100% battery status
 uint8_t extra_param_1;		///< Extra parameters enumeration (0 means ignore)
 uint8_t extra_param_2;		///< Extra parameters enumeration (0 means ignore)
} mavlink_gopro_control_t;

#define MAVLINK_MSG_ID_GOPRO_CONTROL_LEN 13
#define MAVLINK_MSG_ID_220_LEN 13

#define MAVLINK_MSG_ID_GOPRO_CONTROL_CRC 22
#define MAVLINK_MSG_ID_220_CRC 22



#define MAVLINK_MESSAGE_INFO_GOPRO_CONTROL { \
	"GOPRO_CONTROL", \
	10, \
	{  { "extra_value", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gopro_control_t, extra_value) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_gopro_control_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_gopro_control_t, target_component) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_gopro_control_t, mode) }, \
         { "video_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_gopro_control_t, video_size) }, \
         { "video_fps", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_gopro_control_t, video_fps) }, \
         { "video_fov", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_gopro_control_t, video_fov) }, \
         { "battery", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_gopro_control_t, battery) }, \
         { "extra_param_1", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_gopro_control_t, extra_param_1) }, \
         { "extra_param_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_gopro_control_t, extra_param_2) }, \
         } \
}


/**
 * @brief Pack a gopro_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param mode GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps
 * @param video_size 1: 720p, 2: 1080p, 3: 2k7, 4: 4k
 * @param video_fps  1: 25 / 30 fps, 2: 50 / 60 fps, 3: 100 / 120 fps
 * @param video_fov  1: wide, 2: medium, 3: narrow
 * @param battery 0-100% battery status
 * @param extra_param_1 Extra parameters enumeration (0 means ignore)
 * @param extra_param_2 Extra parameters enumeration (0 means ignore)
 * @param extra_value Correspondent value to given extra_param
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gopro_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t mode, uint8_t video_size, int8_t video_fps, uint8_t video_fov, uint8_t battery, uint8_t extra_param_1, uint8_t extra_param_2, float extra_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GOPRO_CONTROL_LEN];
	_mav_put_float(buf, 0, extra_value);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mode);
	_mav_put_uint8_t(buf, 7, video_size);
	_mav_put_int8_t(buf, 8, video_fps);
	_mav_put_uint8_t(buf, 9, video_fov);
	_mav_put_uint8_t(buf, 10, battery);
	_mav_put_uint8_t(buf, 11, extra_param_1);
	_mav_put_uint8_t(buf, 12, extra_param_2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#else
	mavlink_gopro_control_t packet;
	packet.extra_value = extra_value;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mode = mode;
	packet.video_size = video_size;
	packet.video_fps = video_fps;
	packet.video_fov = video_fov;
	packet.battery = battery;
	packet.extra_param_1 = extra_param_1;
	packet.extra_param_2 = extra_param_2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GOPRO_CONTROL;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN, MAVLINK_MSG_ID_GOPRO_CONTROL_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#endif
}

/**
 * @brief Pack a gopro_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param mode GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps
 * @param video_size 1: 720p, 2: 1080p, 3: 2k7, 4: 4k
 * @param video_fps  1: 25 / 30 fps, 2: 50 / 60 fps, 3: 100 / 120 fps
 * @param video_fov  1: wide, 2: medium, 3: narrow
 * @param battery 0-100% battery status
 * @param extra_param_1 Extra parameters enumeration (0 means ignore)
 * @param extra_param_2 Extra parameters enumeration (0 means ignore)
 * @param extra_value Correspondent value to given extra_param
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gopro_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t mode,uint8_t video_size,int8_t video_fps,uint8_t video_fov,uint8_t battery,uint8_t extra_param_1,uint8_t extra_param_2,float extra_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GOPRO_CONTROL_LEN];
	_mav_put_float(buf, 0, extra_value);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mode);
	_mav_put_uint8_t(buf, 7, video_size);
	_mav_put_int8_t(buf, 8, video_fps);
	_mav_put_uint8_t(buf, 9, video_fov);
	_mav_put_uint8_t(buf, 10, battery);
	_mav_put_uint8_t(buf, 11, extra_param_1);
	_mav_put_uint8_t(buf, 12, extra_param_2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#else
	mavlink_gopro_control_t packet;
	packet.extra_value = extra_value;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mode = mode;
	packet.video_size = video_size;
	packet.video_fps = video_fps;
	packet.video_fov = video_fov;
	packet.battery = battery;
	packet.extra_param_1 = extra_param_1;
	packet.extra_param_2 = extra_param_2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GOPRO_CONTROL;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN, MAVLINK_MSG_ID_GOPRO_CONTROL_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#endif
}

/**
 * @brief Encode a gopro_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gopro_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gopro_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gopro_control_t* gopro_control)
{
	return mavlink_msg_gopro_control_pack(system_id, component_id, msg, gopro_control->target_system, gopro_control->target_component, gopro_control->mode, gopro_control->video_size, gopro_control->video_fps, gopro_control->video_fov, gopro_control->battery, gopro_control->extra_param_1, gopro_control->extra_param_2, gopro_control->extra_value);
}

/**
 * @brief Encode a gopro_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gopro_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gopro_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gopro_control_t* gopro_control)
{
	return mavlink_msg_gopro_control_pack_chan(system_id, component_id, chan, msg, gopro_control->target_system, gopro_control->target_component, gopro_control->mode, gopro_control->video_size, gopro_control->video_fps, gopro_control->video_fov, gopro_control->battery, gopro_control->extra_param_1, gopro_control->extra_param_2, gopro_control->extra_value);
}

/**
 * @brief Send a gopro_control message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param mode GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps
 * @param video_size 1: 720p, 2: 1080p, 3: 2k7, 4: 4k
 * @param video_fps  1: 25 / 30 fps, 2: 50 / 60 fps, 3: 100 / 120 fps
 * @param video_fov  1: wide, 2: medium, 3: narrow
 * @param battery 0-100% battery status
 * @param extra_param_1 Extra parameters enumeration (0 means ignore)
 * @param extra_param_2 Extra parameters enumeration (0 means ignore)
 * @param extra_value Correspondent value to given extra_param
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gopro_control_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t mode, uint8_t video_size, int8_t video_fps, uint8_t video_fov, uint8_t battery, uint8_t extra_param_1, uint8_t extra_param_2, float extra_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GOPRO_CONTROL_LEN];
	_mav_put_float(buf, 0, extra_value);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mode);
	_mav_put_uint8_t(buf, 7, video_size);
	_mav_put_int8_t(buf, 8, video_fps);
	_mav_put_uint8_t(buf, 9, video_fov);
	_mav_put_uint8_t(buf, 10, battery);
	_mav_put_uint8_t(buf, 11, extra_param_1);
	_mav_put_uint8_t(buf, 12, extra_param_2);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_CONTROL, buf, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN, MAVLINK_MSG_ID_GOPRO_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_CONTROL, buf, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#endif
#else
	mavlink_gopro_control_t packet;
	packet.extra_value = extra_value;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mode = mode;
	packet.video_size = video_size;
	packet.video_fps = video_fps;
	packet.video_fov = video_fov;
	packet.battery = battery;
	packet.extra_param_1 = extra_param_1;
	packet.extra_param_2 = extra_param_2;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN, MAVLINK_MSG_ID_GOPRO_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_GOPRO_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gopro_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t mode, uint8_t video_size, int8_t video_fps, uint8_t video_fov, uint8_t battery, uint8_t extra_param_1, uint8_t extra_param_2, float extra_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, extra_value);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mode);
	_mav_put_uint8_t(buf, 7, video_size);
	_mav_put_int8_t(buf, 8, video_fps);
	_mav_put_uint8_t(buf, 9, video_fov);
	_mav_put_uint8_t(buf, 10, battery);
	_mav_put_uint8_t(buf, 11, extra_param_1);
	_mav_put_uint8_t(buf, 12, extra_param_2);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_CONTROL, buf, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN, MAVLINK_MSG_ID_GOPRO_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_CONTROL, buf, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#endif
#else
	mavlink_gopro_control_t *packet = (mavlink_gopro_control_t *)msgbuf;
	packet->extra_value = extra_value;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->mode = mode;
	packet->video_size = video_size;
	packet->video_fps = video_fps;
	packet->video_fov = video_fov;
	packet->battery = battery;
	packet->extra_param_1 = extra_param_1;
	packet->extra_param_2 = extra_param_2;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_CONTROL, (const char *)packet, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN, MAVLINK_MSG_ID_GOPRO_CONTROL_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_CONTROL, (const char *)packet, MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE GOPRO_CONTROL UNPACKING


/**
 * @brief Get field target_system from gopro_control message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_gopro_control_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field target_component from gopro_control message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_gopro_control_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field mode from gopro_control message
 *
 * @return GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps
 */
static inline uint8_t mavlink_msg_gopro_control_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field video_size from gopro_control message
 *
 * @return 1: 720p, 2: 1080p, 3: 2k7, 4: 4k
 */
static inline uint8_t mavlink_msg_gopro_control_get_video_size(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field video_fps from gopro_control message
 *
 * @return 1: 25 / 30 fps, 2: 50 / 60 fps, 3: 100 / 120 fps
 */
static inline int8_t mavlink_msg_gopro_control_get_video_fps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  8);
}

/**
 * @brief Get field video_fov from gopro_control message
 *
 * @return 1: wide, 2: medium, 3: narrow
 */
static inline uint8_t mavlink_msg_gopro_control_get_video_fov(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field battery from gopro_control message
 *
 * @return 0-100% battery status
 */
static inline uint8_t mavlink_msg_gopro_control_get_battery(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field extra_param from gopro_control message
 *
 * @return Command Identity (incremental loop: 0 to 255)//A command sent multiple times will be executed or pooled just once
 */
static inline uint8_t mavlink_msg_gopro_control_get_extra_param_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field extra_param from gopro_control message
 *
 * @return Correspondent value to given extra_param
 */
static inline uint8_t mavlink_msg_gopro_control_get_extra_param_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field extra_value from gopro_control message
 *
 * @return Correspondent value to given extra_param
 */
static inline float mavlink_msg_gopro_control_get_extra_value(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a gopro_control message into a struct
 *
 * @param msg The message to decode
 * @param gopro_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_gopro_control_decode(const mavlink_message_t* msg, mavlink_gopro_control_t* gopro_control)
{
#if MAVLINK_NEED_BYTE_SWAP
	gopro_control->extra_value = mavlink_msg_gopro_control_get_extra_value(msg);
	gopro_control->target_system = mavlink_msg_gopro_control_get_target_system(msg);
	gopro_control->target_component = mavlink_msg_gopro_control_get_target_component(msg);
	gopro_control->mode = mavlink_msg_gopro_control_get_mode(msg);
	gopro_control->video_size = mavlink_msg_gopro_control_get_video_size(msg);
	gopro_control->video_fps = mavlink_msg_gopro_control_get_video_fps(msg);
	gopro_control->video_fov = mavlink_msg_gopro_control_get_video_fov(msg);
	gopro_control->battery = mavlink_msg_gopro_control_get_battery(msg);
	gopro_control->extra_param = mavlink_msg_gopro_control_get_extra_param_1(msg);
	gopro_control->extra_param = mavlink_msg_gopro_control_get_extra_param_2(msg);
#else
	memcpy(gopro_control, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_GOPRO_CONTROL_LEN);
#endif
}
