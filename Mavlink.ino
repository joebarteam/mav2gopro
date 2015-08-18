#define MAVLINK_COMM_NUM_BUFFERS 1
#define MAVLINK_USE_CONVENIENCE_FUNCTIONS
#undef MAVLINK_MAX_DIALECT_PAYLOAD_SIZE
#define MAVLINK_MAX_DIALECT_PAYLOAD_SIZE 101    // reduced from 254, defined in version.h

void requestMavLink(){
  if (ConnectMavlink && mavlink_active && !busy){  
    /* Request all needed streams */
      busy = TRUE;
      uint16_t len;
      const int maxStreams = 3;
      const uint8_t MAVStreams[maxStreams] = {MAV_DATA_STREAM_ALL, 
                                              MAV_DATA_STREAM_EXTRA1,
                                              MAV_DATA_STREAM_EXTRA3};                                         
      const uint16_t MAVRates[maxStreams] = {0x01, 0x02, 0x02};
    
      mavlink_message_t msg; 
      uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    
      for (int i=0; i < maxStreams; i++) {
        mavlink_msg_request_data_stream_pack(MY_SYSID, MY_CMPID, &msg, aq_mav_system, aq_mav_component,  MAVStreams[i], MAVRates[i], 1);
        uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
        _MavLinkSerial.write(buf, len);  
      }
      #ifdef SERDB
        DPL("Request send");
      #endif
      mavlink_request = TRUE;
  }
  busy = FALSE;
}

void _MavLink_receive() {
  busy = TRUE; 
  mavlink_message_t msg;
  mavlink_status_t status;

  while(_MavLinkSerial.available()) { 
    uint8_t c = _MavLinkSerial.read();
    if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
      messageCounter = 0; // reset after receive message
      mavlink_active = TRUE;
      
      switch(msg.msgid){
      case MAVLINK_MSG_ID_HEARTBEAT:  // 0
        aq_mav_system    = msg.sysid;
        aq_mav_component = msg.compid;
        aq_base_mode     = (mavlink_msg_heartbeat_get_base_mode(&msg) & 0x80) > 7;
        aq_custom_mode   = mavlink_msg_heartbeat_get_custom_mode(&msg);
        tMavLed = millis(); // signaling
        doSig = TRUE;     
      #ifdef SERDB
        DPL("");
        DPN(millis());
        DPN("\tMAVLINK_MSG_ID_SYS_STATUS: base_mode: ");
        DPN((mavlink_msg_heartbeat_get_base_mode(&msg) & 0x80) > 7);
        DPN(", custom_mode: ");
        DPN(mavlink_msg_heartbeat_get_custom_mode(&msg));
        DPL();
      #endif              
        MavLink_Connected_timer=millis(); 
        if(!mavlink_active); {
          hb_count++;   
          if((hb_count++) > 10) {        // If  received > 10 heartbeats from MavLink then we are connected
            mavlink_active=1;
            hb_count=0;
          }
        }
      break;
      case MAVLINK_MSG_ID_GOPRO_SET_REQUEST: // 218
        goproCommand    = mavlink_msg_gopro_set_request_get_cmd_id(&msg);
        goproCommandVal = mavlink_msg_gopro_set_request_get_value(&msg);
        SendUrl = TRUE;
        switch (goproCommand){
          case GOPRO_COMMAND_POWER:
            if (goproCommandVal == GOPRO_PWR_ON)       CmdUrl =gopro_off;
            if (goproCommandVal == GOPRO_PWR_OFF)      CmdUrl =gopro_on;
          break;
          case GOPRO_COMMAND_CAPTURE_MODE:
		        CmdUrl =mode_capture;
          break;
          case GOPRO_COMMAND_SHUTTER:
            if (goproCommandVal == GOPRO_SHUT_REC)     CmdUrl =start_rec;
            if (goproCommandVal == GOPRO_SHUT_STOP)    CmdUrl =stop_rec;
          break;
          case GOPRO_COMMAND_VIDSIZE:
            CmdUrl =video_size;
          break;
          case GOPRO_COMMAND_FPS:
            CmdUrl =video_frRate;
          break;
          case GOPRO_COMMAND_FOV:
            CmdUrl =video_fov;
          break;
          default:
          break;
        }
      
      #ifdef SERDB
        DPN(millis());
        DPN("\tMAVLINK_MSG_ID_GOPRO_SET_REQUEST: ");
        DPN(mavlink_msg_gopro_set_request_get_cmd_id(&msg));
        DPN("\t");
        DPN(mavlink_msg_gopro_set_request_get_value(&msg));
        DPL();
      #endif
      break;
   
      case MAVLINK_MSG_ID_STATUSTEXT:     // 253
        mavlink_msg_statustext_decode(&msg,&statustext);
        aq_status_severity = statustext.severity;
        aq_status_send_count = 5;
          
      #ifdef SERDB
        DPN(millis());
        DPN("\tMAVLINK_MSG_ID_STATUSTEXT: severity ");
        DPN(statustext.severity);
        DPN(", text");
        DPN(statustext.text);
        DPL();
      #endif
      break;
      default:
        //Do nothing
      break;
      } // end switch
      delayMicroseconds(138); // next message
    } 
  } // end while loop
  busy = FALSE;
} // end _MavLink_receive       


void send_heartbeat() {
  if (!busy) { 
    /* request status from GoPro if powered on, or bacpac if powered off */
    if (WiFi_Connected){
      if (goproPowered) {
        CmdUrl =status_gopro;   // request current status
        reqGoProStatus = TRUE;
        sendCmd (CmdUrl);       // send the command to the GoPro
        getResponse();          // get the response back from the command
          delay (10);
        CmdUrl =status_batt;    // now get the battery level
        reqGoProBatt = TRUE;
        sendCmd (CmdUrl);
        getResponse();      
      }
      if (!goproPowered) {
        CmdUrl =status_bacpac;
        reqGoProPowered = TRUE;
        sendCmd (CmdUrl);
        getResponse();    
      }
    }
  
    delay (20);      // give the ESP8266 some timeslices
    
    if (!WiFi_Connected) 
        GoProStat = GOPRO_HEARTBEAT_STATUS_DISCONNECTED;
    if (WiFi_Connected) {
      if (!goproPowered) 
        GoProStat = GOPRO_HEARTBEAT_STATUS_CONNECTED_POWER_OFF;
      if (goproPowered && !extInfo[recordStat])
        GoProStat = GOPRO_HEARTBEAT_STATUS_CONNECTED_POWER_ON;
      if (goproPowered &&  extInfo[recordStat])
         GoProStat = GOPRO_HEARTBEAT_STATUS_RECORDING;             
    }
    
    if (ConnectMavlink && mavlink_active){
      mavlink_message_t msg; 
      uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    
      mavlink_msg_gopro_heartbeat_pack(MY_SYSID, MY_CMPID, &msg, GoProStat);
      uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
      _MavLinkSerial.write(buf, len);
  
      delay(20);
      
      // detailed GoPro status to send 
      mavlink_msg_gopro_status_pack(MY_SYSID, MY_CMPID, &msg, aq_mav_system, aq_mav_component, extInfo[camMode], extInfo[vidSize], extInfo[vidFPS], extInfo[vidFov], stdInfo[20], extInfo[recMin], extInfo[recSec], extInfo[photoNum], extInfo[vidNum], goproSeries, 0);
      len = mavlink_msg_to_send_buffer(buf, &msg);
      _MavLinkSerial.write(buf, len);    
    }
  }
  busy = FALSE;
} /* end send_heartbeat */

