// MESSAGE GOPRO_STATUS PACKING

#define MAVLINK_MSG_ID_GOPRO_STATUS 155

typedef struct __mavlink_gopro_status_t
{
 float gpversion; ///< Hero version ##,## main version, model type 
 uint8_t target_system; ///< System ID
 uint8_t target_component; ///< Component ID
 uint8_t mode; ///< GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps 
 uint8_t video_size; ///< Video capture size
 uint8_t video_fps; ///< Video Frame Per Second
 int8_t video_fov; ///< Video FOV 0: wide, 1: medium, 2: narrow 
 uint8_t battery; ///< Battery status in %
 uint8_t rec_min; ///< recording minute field
 uint8_t rec_sec; ///< recording seconds field
 uint8_t photo_num; ///< Photo number counter
 uint8_t video_num; ///< Video number counter
 uint8_t extra_param; ///< Extra parameters enumeration (0 means ignore)
} mavlink_gopro_status_t;

#define MAVLINK_MSG_ID_GOPRO_STATUS_LEN 16
#define MAVLINK_MSG_ID_155_LEN 16

#define MAVLINK_MSG_ID_GOPRO_STATUS_CRC 167
#define MAVLINK_MSG_ID_155_CRC 167



#define MAVLINK_MESSAGE_INFO_GOPRO_STATUS { \
	"GOPRO_STATUS", \
	13, \
	{  { "gpversion", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gopro_status_t, gpversion) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_gopro_status_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_gopro_status_t, target_component) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_gopro_status_t, mode) }, \
         { "video_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_gopro_status_t, video_size) }, \
         { "video_fps", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_gopro_status_t, video_fps) }, \
         { "video_fov", NULL, MAVLINK_TYPE_INT8_T, 0, 9, offsetof(mavlink_gopro_status_t, video_fov) }, \
         { "battery", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_gopro_status_t, battery) }, \
         { "rec_min", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_gopro_status_t, rec_min) }, \
         { "rec_sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_gopro_status_t, rec_sec) }, \
         { "photo_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_gopro_status_t, photo_num) }, \
         { "video_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_gopro_status_t, video_num) }, \
         { "extra_param", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_gopro_status_t, extra_param) }, \
         } \
}


/**
 * @brief Pack a gopro_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param mode GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps 
 * @param video_size Video capture size
 * @param video_fps Video Frame Per Second
 * @param video_fov Video FOV 0: wide, 1: medium, 2: narrow 
 * @param battery Battery status in %
 * @param rec_min recording minute field
 * @param rec_sec recording seconds field
 * @param photo_num Photo number counter
 * @param video_num Video number counter
 * @param gpversion Hero version ##,## main version, model type 
 * @param extra_param Extra parameters enumeration (0 means ignore)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gopro_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t mode, uint8_t video_size, uint8_t video_fps, int8_t video_fov, uint8_t battery, uint8_t rec_min, uint8_t rec_sec, uint8_t photo_num, uint8_t video_num, float gpversion, uint8_t extra_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GOPRO_STATUS_LEN];
	_mav_put_float(buf, 0, gpversion);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mode);
	_mav_put_uint8_t(buf, 7, video_size);
	_mav_put_uint8_t(buf, 8, video_fps);
	_mav_put_int8_t(buf, 9, video_fov);
	_mav_put_uint8_t(buf, 10, battery);
	_mav_put_uint8_t(buf, 11, rec_min);
	_mav_put_uint8_t(buf, 12, rec_sec);
	_mav_put_uint8_t(buf, 13, photo_num);
	_mav_put_uint8_t(buf, 14, video_num);
	_mav_put_uint8_t(buf, 15, extra_param);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#else
	mavlink_gopro_status_t packet;
	packet.gpversion = gpversion;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mode = mode;
	packet.video_size = video_size;
	packet.video_fps = video_fps;
	packet.video_fov = video_fov;
	packet.battery = battery;
	packet.rec_min = rec_min;
	packet.rec_sec = rec_sec;
	packet.photo_num = photo_num;
	packet.video_num = video_num;
	packet.extra_param = extra_param;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GOPRO_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GOPRO_STATUS_LEN, MAVLINK_MSG_ID_GOPRO_STATUS_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#endif
}

/**
 * @brief Pack a gopro_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param mode GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps 
 * @param video_size Video capture size
 * @param video_fps Video Frame Per Second
 * @param video_fov Video FOV 0: wide, 1: medium, 2: narrow 
 * @param battery Battery status in %
 * @param rec_min recording minute field
 * @param rec_sec recording seconds field
 * @param photo_num Photo number counter
 * @param video_num Video number counter
 * @param gpversion Hero version ##,## main version, model type 
 * @param extra_param Extra parameters enumeration (0 means ignore)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gopro_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t mode,uint8_t video_size,uint8_t video_fps,int8_t video_fov,uint8_t battery,uint8_t rec_min,uint8_t rec_sec,uint8_t photo_num,uint8_t video_num,float gpversion,uint8_t extra_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GOPRO_STATUS_LEN];
	_mav_put_float(buf, 0, gpversion);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mode);
	_mav_put_uint8_t(buf, 7, video_size);
	_mav_put_uint8_t(buf, 8, video_fps);
	_mav_put_int8_t(buf, 9, video_fov);
	_mav_put_uint8_t(buf, 10, battery);
	_mav_put_uint8_t(buf, 11, rec_min);
	_mav_put_uint8_t(buf, 12, rec_sec);
	_mav_put_uint8_t(buf, 13, photo_num);
	_mav_put_uint8_t(buf, 14, video_num);
	_mav_put_uint8_t(buf, 15, extra_param);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#else
	mavlink_gopro_status_t packet;
	packet.gpversion = gpversion;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mode = mode;
	packet.video_size = video_size;
	packet.video_fps = video_fps;
	packet.video_fov = video_fov;
	packet.battery = battery;
	packet.rec_min = rec_min;
	packet.rec_sec = rec_sec;
	packet.photo_num = photo_num;
	packet.video_num = video_num;
	packet.extra_param = extra_param;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GOPRO_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GOPRO_STATUS_LEN, MAVLINK_MSG_ID_GOPRO_STATUS_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#endif
}

/**
 * @brief Encode a gopro_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gopro_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gopro_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gopro_status_t* gopro_status)
{
	return mavlink_msg_gopro_status_pack(system_id, component_id, msg, gopro_status->target_system, gopro_status->target_component, gopro_status->mode, gopro_status->video_size, gopro_status->video_fps, gopro_status->video_fov, gopro_status->battery, gopro_status->rec_min, gopro_status->rec_sec, gopro_status->photo_num, gopro_status->video_num, gopro_status->gpversion, gopro_status->extra_param);
}

/**
 * @brief Encode a gopro_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gopro_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gopro_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gopro_status_t* gopro_status)
{
	return mavlink_msg_gopro_status_pack_chan(system_id, component_id, chan, msg, gopro_status->target_system, gopro_status->target_component, gopro_status->mode, gopro_status->video_size, gopro_status->video_fps, gopro_status->video_fov, gopro_status->battery, gopro_status->rec_min, gopro_status->rec_sec, gopro_status->photo_num, gopro_status->video_num, gopro_status->gpversion, gopro_status->extra_param);
}

/**
 * @brief Send a gopro_status message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param mode GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps 
 * @param video_size Video capture size
 * @param video_fps Video Frame Per Second
 * @param video_fov Video FOV 0: wide, 1: medium, 2: narrow 
 * @param battery Battery status in %
 * @param rec_min recording minute field
 * @param rec_sec recording seconds field
 * @param photo_num Photo number counter
 * @param video_num Video number counter
 * @param gpversion Hero version ##,## main version, model type 
 * @param extra_param Extra parameters enumeration (0 means ignore)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gopro_status_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t mode, uint8_t video_size, uint8_t video_fps, int8_t video_fov, uint8_t battery, uint8_t rec_min, uint8_t rec_sec, uint8_t photo_num, uint8_t video_num, float gpversion, uint8_t extra_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GOPRO_STATUS_LEN];
	_mav_put_float(buf, 0, gpversion);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mode);
	_mav_put_uint8_t(buf, 7, video_size);
	_mav_put_uint8_t(buf, 8, video_fps);
	_mav_put_int8_t(buf, 9, video_fov);
	_mav_put_uint8_t(buf, 10, battery);
	_mav_put_uint8_t(buf, 11, rec_min);
	_mav_put_uint8_t(buf, 12, rec_sec);
	_mav_put_uint8_t(buf, 13, photo_num);
	_mav_put_uint8_t(buf, 14, video_num);
	_mav_put_uint8_t(buf, 15, extra_param);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_STATUS, buf, MAVLINK_MSG_ID_GOPRO_STATUS_LEN, MAVLINK_MSG_ID_GOPRO_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_STATUS, buf, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#endif
#else
	mavlink_gopro_status_t packet;
	packet.gpversion = gpversion;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mode = mode;
	packet.video_size = video_size;
	packet.video_fps = video_fps;
	packet.video_fov = video_fov;
	packet.battery = battery;
	packet.rec_min = rec_min;
	packet.rec_sec = rec_sec;
	packet.photo_num = photo_num;
	packet.video_num = video_num;
	packet.extra_param = extra_param;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_STATUS, (const char *)&packet, MAVLINK_MSG_ID_GOPRO_STATUS_LEN, MAVLINK_MSG_ID_GOPRO_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_STATUS, (const char *)&packet, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_GOPRO_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gopro_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t mode, uint8_t video_size, uint8_t video_fps, int8_t video_fov, uint8_t battery, uint8_t rec_min, uint8_t rec_sec, uint8_t photo_num, uint8_t video_num, float gpversion, uint8_t extra_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, gpversion);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mode);
	_mav_put_uint8_t(buf, 7, video_size);
	_mav_put_uint8_t(buf, 8, video_fps);
	_mav_put_int8_t(buf, 9, video_fov);
	_mav_put_uint8_t(buf, 10, battery);
	_mav_put_uint8_t(buf, 11, rec_min);
	_mav_put_uint8_t(buf, 12, rec_sec);
	_mav_put_uint8_t(buf, 13, photo_num);
	_mav_put_uint8_t(buf, 14, video_num);
	_mav_put_uint8_t(buf, 15, extra_param);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_STATUS, buf, MAVLINK_MSG_ID_GOPRO_STATUS_LEN, MAVLINK_MSG_ID_GOPRO_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_STATUS, buf, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#endif
#else
	mavlink_gopro_status_t *packet = (mavlink_gopro_status_t *)msgbuf;
	packet->gpversion = gpversion;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->mode = mode;
	packet->video_size = video_size;
	packet->video_fps = video_fps;
	packet->video_fov = video_fov;
	packet->battery = battery;
	packet->rec_min = rec_min;
	packet->rec_sec = rec_sec;
	packet->photo_num = photo_num;
	packet->video_num = video_num;
	packet->extra_param = extra_param;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_STATUS, (const char *)packet, MAVLINK_MSG_ID_GOPRO_STATUS_LEN, MAVLINK_MSG_ID_GOPRO_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOPRO_STATUS, (const char *)packet, MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE GOPRO_STATUS UNPACKING


/**
 * @brief Get field target_system from gopro_status message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_gopro_status_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field target_component from gopro_status message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_gopro_status_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field mode from gopro_status message
 *
 * @return GoPro mode 1: video, 2: photo, 3: burst, 4: timelaps 
 */
static inline uint8_t mavlink_msg_gopro_status_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field video_size from gopro_status message
 *
 * @return Video capture size
 */
static inline uint8_t mavlink_msg_gopro_status_get_video_size(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field video_fps from gopro_status message
 *
 * @return Video Frame Per Second
 */
static inline uint8_t mavlink_msg_gopro_status_get_video_fps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field video_fov from gopro_status message
 *
 * @return Video FOV 0: wide, 1: medium, 2: narrow 
 */
static inline int8_t mavlink_msg_gopro_status_get_video_fov(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  9);
}

/**
 * @brief Get field battery from gopro_status message
 *
 * @return Battery status in %
 */
static inline uint8_t mavlink_msg_gopro_status_get_battery(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field rec_min from gopro_status message
 *
 * @return recording minute field
 */
static inline uint8_t mavlink_msg_gopro_status_get_rec_min(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field rec_sec from gopro_status message
 *
 * @return recording seconds field
 */
static inline uint8_t mavlink_msg_gopro_status_get_rec_sec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field photo_num from gopro_status message
 *
 * @return Photo number counter
 */
static inline uint8_t mavlink_msg_gopro_status_get_photo_num(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field video_num from gopro_status message
 *
 * @return Video number counter
 */
static inline uint8_t mavlink_msg_gopro_status_get_video_num(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field gpversion from gopro_status message
 *
 * @return Hero version ##,## main version, model type 
 */
static inline float mavlink_msg_gopro_status_get_gpversion(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field extra_param from gopro_status message
 *
 * @return Extra parameters enumeration (0 means ignore)
 */
static inline uint8_t mavlink_msg_gopro_status_get_extra_param(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Decode a gopro_status message into a struct
 *
 * @param msg The message to decode
 * @param gopro_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_gopro_status_decode(const mavlink_message_t* msg, mavlink_gopro_status_t* gopro_status)
{
#if MAVLINK_NEED_BYTE_SWAP
	gopro_status->gpversion = mavlink_msg_gopro_status_get_gpversion(msg);
	gopro_status->target_system = mavlink_msg_gopro_status_get_target_system(msg);
	gopro_status->target_component = mavlink_msg_gopro_status_get_target_component(msg);
	gopro_status->mode = mavlink_msg_gopro_status_get_mode(msg);
	gopro_status->video_size = mavlink_msg_gopro_status_get_video_size(msg);
	gopro_status->video_fps = mavlink_msg_gopro_status_get_video_fps(msg);
	gopro_status->video_fov = mavlink_msg_gopro_status_get_video_fov(msg);
	gopro_status->battery = mavlink_msg_gopro_status_get_battery(msg);
	gopro_status->rec_min = mavlink_msg_gopro_status_get_rec_min(msg);
	gopro_status->rec_sec = mavlink_msg_gopro_status_get_rec_sec(msg);
	gopro_status->photo_num = mavlink_msg_gopro_status_get_photo_num(msg);
	gopro_status->video_num = mavlink_msg_gopro_status_get_video_num(msg);
	gopro_status->extra_param = mavlink_msg_gopro_status_get_extra_param(msg);
#else
	memcpy(gopro_status, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_GOPRO_STATUS_LEN);
#endif
}
