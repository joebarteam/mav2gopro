 /*
 Copyright (c) 2015.  All rights reserved.
 An Open Source ESP8266 sketch for controlling a GoPro HERO camera via WIFI
 
  Program    : GoProClient
  Version    : v0.6, aug 2015
  Author     : joebar.rc@googlemail.com
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 http://www.gnu.org/licenses

 *  For upload of the code: pull GPIO-0 to GND and toggle power (VCC). The ESP8266 is now in flash mode
 *  for running code, pull GPIO-0 to VCC or float
 *
 *  RGBLED: Solid red:    no previous config, start webconnection to MAV2GOPRO
 *          Flash red:    mavlink: no,  GoPro connection: no (wrong ssid/passwd or not available)
 *          Flash purple: mavlink: yes, GoPro connection: no
 *          Flash blue  : mavlink: no,  GoPro connection: yes
 *          Flash green:  mavlink: yes, GoPro connection: yes
 *          
 *          flash is in the frequency of mavlink heartbeat OR 2.5sec
 */
#define ConnectGoPro    TRUE    // TRUE = Try to connect to GoPro, FALSE = do not
#define ConnectMavlink  TRUE    // TRUE = Try to connect to Mavlink, FALSE = do not
//#define SERDB                 // Option: Output debug information to debugSerial port
#define CONFIGWEBSERVER

#include <ESP8266WiFi.h>
#include "GCS_MAVLink.h"
#include "GoProClient.h"
#include <EEPROM.h>
#ifdef CONFIGWEBSERVER
  #include <ESP8266WebServer.h>
#endif

WiFiClient client;                        // Use WiFiClient class to create TCP connections
const int httpPort = 80;
#ifdef CONFIGWEBSERVER
  ESP8266WebServer server (httpPort);     // WebServer on 192.168.4.1
#endif

void setup() {
  _MavLinkSerial.begin(_MavLinkSerialBaud);
  #ifdef SERDB
    _debugSerial.begin(_debugSerialBaud);
    _debugSerial.setDebugOutput(true);    // include ESP8266 debug info
  #endif

  EEPROM.begin(512);
  configDone = EEPROM.read(CONFIGDONELOC); // previous config done?
  if (configDone == TRUE) {     // only look for TRUE or FALSE
    getEEPROMString();          // read eeprom for (stored) ssid and pass
    //ToDo test passw & ssid
  } else {
    #ifdef SERDB
      DPL ("No stored ssid/passw");
    #endif
    configDone = FALSE;
  }

  if (configDone == FALSE) WiFi.mode(WIFI_AP); 
  if (configDone == TRUE){
    WiFi.disconnect();
    #ifdef CONFIGWEBSERVER
      WiFi.mode(WIFI_AP_STA);       // setup WiFi client and accesspoint
    #else
      WiFi.mode(WIFI_STA);          // setup WiFi client
    #endif
    WiFi.config ({10,5,5,109},{10,5,5,9},{255,255,255,0}); // GoPro client and server address
  }
  
  #ifdef CONFIGWEBSERVER
    #ifdef SERDB
      DPL ("Starting webserver");
    #endif
    WiFi.softAP("Mav2GoPro");
    server.on ("/", handleRoot );
    server.on ("/reset", handleReset );
    server.on ("/setgoproap", handleSetAccessPoint );
    server.on ("/clearee", setEEPROMClear );
    server.onNotFound ( handleNotFound );
    server.begin();
  #endif

  tEventReq    = millis();  // Request mavlink streams
  tEventStatus = millis();  // Generate Heart Beat and Status
  MavLink_Connected_timer=millis();
  
  pinMode(rgbR, OUTPUT);  // LED ports
  pinMode(rgbG, OUTPUT);
  pinMode(rgbB, OUTPUT);
}

/* * * * M A I N   L O O P * * * */
void loop() {
  /* main mavlink receive loop */
  if (ConnectMavlink) _MavLink_receive();

  /* if not yet connected to the GoPro wifi, nows the time */ 
  if (millis()>=bootTime+5e3){  // give mavlink some time, if cannot connect try to connect gopro
    if ((configDone==TRUE) && (ConnectGoPro) && (!WiFi_Connected))
      initWiFi();  
  }
  
  delay(15);  // give the ESP8266 core functions some timeslices
  
  /* start processing commands */
  if (SendUrl && WiFi_Connected){  // Received a command from AQ 
    sendCmd (CmdUrl);
    getResponse();
    SendUrl = FALSE;  //reset value
  }
 
  #ifdef CONFIGWEBSERVER
    server.handleClient(); 
  #endif

  /* mavlink events */
  if ((millis() - tEventStatus) > STATFREQ) {
    send_heartbeat();
    tEventStatus = millis();
  }
  if ((millis() - tEventReq) > MAVREQFREQ) {
    requestMavLink();
    tEventReq = millis();
    if (timeOut) {
      timeOut = FALSE;
      toCounter = 0;
    }
  }  

  delay (25);
  doSignaling();
}
