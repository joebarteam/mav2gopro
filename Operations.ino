void heartBeat(){
  messageCounter++;

  /* first request of streams after bootup + 5s */
  if (!mavlink_request && mavlink_active && (millis()>=bootTime+5000) ){  // give it some time to receive the first package
    for (int i=0;i<3;i++){
      requestMavLink();
    }
  }
   /* check if Mavlink is lost */   
  if(messageCounter >= 15 && mavlink_active) {
   #ifdef SERDB  
      DPL ("We lost MAVLink");
   #endif
   mavlink_active = 0;
   messageCounter = 0;
   mavlink_request = 0;
  }
 
  if(messageCounter >100) {
   messageCounter = 0;  /* to prevent overflow */
   #ifdef SERDB  
     DPL ("(Still) no mavlink ??");
   #endif
  }
} /* end heartBeat() */


/* * * * * WIFI Functions * * * * * * */
void sendCmd(String url){
  if (!client.connect(host, httpPort)) {
    #ifdef SERDB
      DPL("connection failed");
    #endif
    WiFi_Connected = FALSE;  
    return;
  }
  
  // This will send the request to the GoPro
  client.println(String("GET ") + url);
  client.println();
  delay(50); 
} // end sendCmd

/* Response scraper from GoPro reply */
void getResponse(){
  resGood = FALSE;
  client.setTimeout(10);   // set lower timeout to prevent waiting (default)1000ms per response line read
  
  while(client.available()){  /* NOTE: this will take 11 x timeout, set the timeout as low as possible */
    line = client.readStringUntil('\r');  /* Get first line, did GoPro execute the cmd? */
    if (line == respons_ok) resGood = TRUE;
    for (int i=0;i<9;i++){                /* skip header */
      line = client.readStringUntil('\r');
    }
    
    if (reqGoProStatus && goproPowered) {
      client.readBytes(extInfo, 56);      /* read response body */
      reqGoProStatus = FALSE;
    }

    if (reqGoProBatt && goproPowered) {   /* SE request can read battery */
      client.readBytes(stdInfo, 31);      /* read response body */
      reqGoProBatt = FALSE;
    }

    if (reqGoProPowered) {
      byte statusBuffer[16];
      client.readBytes(statusBuffer, 15); /* read response body */
      goproPowered = statusBuffer[10];    /* bacpac byte 10 indicates GoPro powered on/off */
      reqGoProPowered = FALSE;
    }
    
    if (reqGoProVersion){
      byte statusBuffer[37];
      client.readBytes(statusBuffer,37);      /* HD#.##.##.## */
      goproSeries=(int)statusBuffer[7] - 48;  /* string to numeric */
      reqGoProVersion=FALSE;
      
/*goproModel = buffer 9 en 10, hoe dit samenvoegen vanuit string?*/
//        for (int i=5;i<11;i++){
//          goproVersion$ +=statusBuffer[i];
//        }
      
    }
  }
  if (!resGood){  // no or bad response
    goproPowered = FALSE;
  }
}

/* WiFi init and connect to GoPro */
void initWiFi(){
  if (!timeOut){
    WiFi_Connected = FALSE;
    #ifdef SERDB
      DPL ();
      DPN("Connecting to ");
      DPN(esid);
      DPN(" using ");
      DPN(esid);
      DPN("/");
      DPL(epass);
    #endif
    
    WiFi.begin(esid.c_str(), epass.c_str());

    while (WiFi.status() != WL_CONNECTED && toCounter++ < 20) {
      delay(500);
      doSignaling();
    #ifdef CONFIGWEBSERVER
      server.handleClient(); 
    #endif
    }
    if(toCounter == 21){
      timeOut = TRUE;
      #ifdef SERDB
        if (timeOut) DPL ("Could not connect..");
      #endif
    }
    
    if (WiFi.status() == WL_CONNECTED) WiFi_Connected = TRUE;

    // check GoPro status and version, first try the internal wifi bacpac
    CmdUrl=status_bacpac;  
    sendCmd (CmdUrl);
    reqGoProPowered = TRUE;
    getResponse();
 
    delay(20);  // give the ESP8266 some timeslices

    if (goproPowered){  // get GoPro version
      CmdUrl=gopro_version;  
      sendCmd (CmdUrl);
      reqGoProVersion = TRUE;
      getResponse();
     }
  }
}

bool testWifi(void) {
  int c = 0;
  while ( c < 20 ) {
    if (WiFi.status() == WL_CONNECTED) {
      return true;
    }
    delay(500);
    c++;
  }
  return false;
}

void getEEPROMString(){
  // read eeprom for (stored) ssid and pass
  for (int i = 0; i < APLENGHT; ++i){
      if (EEPROM.read(i)!=32) esid += char(EEPROM.read(i)); // skip spaces
    }
  for (int i = APLENGHT; i < APLENGHT+PASSLENGHT; ++i){
      if (EEPROM.read(i)!=32) epass += char(EEPROM.read(i));
    }  
}

void setEEPROMString(String apssid, String appwd){
  for (int i = 0; i < apssid.length(); ++i) {
      EEPROM.write(i, apssid[i]);
    }
  for (int i = 0; i < appwd.length(); ++i) {
      EEPROM.write(APLENGHT+i, appwd[i]);
    }
  setConfigDone(TRUE);
  EEPROM.commit();
}

void setEEPROMClear(){
  for (int j = 0; j < (APLENGHT+PASSLENGHT); ++j) { EEPROM.write(j, 32); }  // clear with spaces (32)
  setConfigDone(FALSE);
  EEPROM.commit();
}

void setConfigDone(uint8_t stat){
  // bool at location CONFIGDONELOC (92) in EEPRom to indicate a saved GoPro config (ssid/passw)
  EEPROM.write(CONFIGDONELOC,stat);
}

void setColor(bool red, bool green, bool blue){
  // for some unknown reason analogwrite crashes, digitalwrite not??
  // so untill solution only a few color combinations are possible
 #ifdef COMMON_ANODE  // reverse signal
  red   = 1 - red;
  green = 1 - green;
  blue  = 1 - blue;
 #endif
 digitalWrite (rgbR, red);
 digitalWrite (rgbG, green);
 digitalWrite (rgbB, blue);
}

void doSignaling(){
  /* scheduled events, the ticker function did crash the sketch frequently */
  /* LED events */
  if (configDone == FALSE) setColor(1,0,0); //no config stored = orange

  if (configDone == TRUE){
    if ((millis() - tMavLed) > HBFLASH)  // Heartbeat ritme flash 100ms
      setColor(0,0,0); // black (todo: send color cmd with defined colors)
      
    if (((millis()- tEventFlashFreq)>FLASHFREQ) || doSig){
      if (!WiFi_Connected){
        if (!mavlink_active) setColor(1, 0, 0);    // no mavlink, no wifi = red
        if (mavlink_active)  setColor(1, 0, 1);    // mavlink, no wifi = yellow
      }
      if (WiFi.status() == WL_CONNECTED){
        if (!mavlink_active) setColor(0, 0, 1);   // no mavlink, wifi = blue
        if (mavlink_active)  setColor(0, 1, 0);   // mavlink, wifi = green
      }
      tEventFlashFreq = millis();
      if (doSig) doSig = FALSE; 
    }
  }
}

