#ifdef CONFIGWEBSERVER
void handleRoot() {
  String Content;
  Content = "<body bgcolor=\"#C1CFE3\" alink=\"#EE0000\" link=\"#0000EE\" text=\"#000000\"vlink=\"#551A8B\">";
  Content += "<title> ESP8266 MAV2GOPRO</title>";
  Content += "<p><b><span style=\"color:#A52A2A; font-size:20px; font-family:arial,helvetica,sans-serif;\">";
  Content += "MAV2GoPro config";
  if (configDone !=TRUE) 
  Content += "<strong><span style='color:#FF0000;'>&emsp;SET SSID &amp; PASSWORD!</span></strong>";
  Content += "</span></b></p>";
  Content +="<p><span style=\"font-family:courier new,courier,monospace;\">";
  Content +="<strong>AQ link:</strong>&emsp;&emsp;";
  Content +=statStr[mavlink_active];
  Content +="<br>";
  Content +="<strong>GoPro v";
  Content +=goproSeries;
  Content +=":</strong>&emsp;";
  Content +=statStr[goproPowered];
  Content +="<br />";
  Content +="<strong>Mode :</strong>&emsp;&emsp;&emsp;";
  Content +=modeStr[extInfo[camMode]];
  Content +="</span></p>";

  Content +="<form action='setgoproap'>";
  Content +="<p><span style='font-family:courier new,courier,monospace;'>";
  Content +="GoPro SSID:&emsp;";
  Content +="<input maxlength='15' name='ssid' type='text' value='";
  Content +=esid; //test
  Content +="'/><br>";
  Content +="GoPro Pwd :&emsp;";
  Content +="<input type=maxlength='25' name='pass' type='text' value='";
  Content +=epass; //test
  Content +="'/>";
  Content +="<input type='submit' value='Set'>";
  Content +="</span></p></form>";

  Content += "<table border='0'><tbody><tr><td>";
  Content += "<form action='/'>";
  Content += "<input type='submit' value='Refresh status' />&emsp;";
  Content += "</form></td>";
  Content += "<td><form action='reset'>";
  Content += "<input type='submit' value='Reboot MAV2GoPro' />";
  Content += "</form></td>";
  Content += "</tr></tbody></table>"; 
  Content +="</body></html>";

  server.send(200, "text/html", Content);
}
void handleNotFound(){
  String message = "Sorry.. Page Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void handleSetAccessPoint() {
  int httpstatus = 200;
  String qsid = server.arg("ssid");
  String qpass = server.arg("pass");
  if (qsid.length() > 0 && qpass.length() > 0) {
    for (int i = 0; i < qsid.length(); i++) {
      // Deal with (potentially) plus-encoded ssid
      qsid[i] = (qsid[i] == '+' ? ' ' : qsid[i]);
    }
    for (int i = 0; i < qpass.length(); i++) {
      // Deal with (potentially) plus-encoded password
      qpass[i] = (qpass[i] == '+' ? ' ' : qpass[i]);
    }
//    WiFi.mode(WIFI_AP_STA);
//    WiFi.begin(qsid.c_str(), qpass.c_str());
//    if (!testWifi()) {
//      content = "<!DOCTYPE HTML>\n<html>";
//      content += "Failed to connect to AP ";
//      content += qsid;
//      content += ", try again.</html>";
//    }else{
      content = "<!DOCTYPE HTML>\n<html>";
      content += "Connection passed, saving to EEPROM";
      content += "<br>reset to use </html>";
      setEEPROMClear();
      setEEPROMString (qsid,qpass);
//    }
  } else {
    content = "<!DOCTYPE HTML><html>";
    content += "Error, no ssid or password set?</html>";
    Serial1.println("Sending 404");
    httpstatus = 404;
  }
  server.send(httpstatus, "text/html", content);
}

void handleReset() {
  delay (500);
  handleRoot();
  delay (500);
  ESP.restart();
}
#endif

