/* GoPro WIFI access */
String      esid;                     // EEProm stored SSID
String      epass;                    // EEProm stored passw
const char* host     = "10.5.5.9";
const char* httpver  = " HTTP/1.1";   // important, GoPro cannot handle higher HTTP language

uint8_t configDone;

#define PASSLENGHT    25              // max epass lenght
#define APLENGHT      15              // max GoPro esid lenght
#define CONFIGDONELOC 92              // EEProm byte position for config flag

/* GoPro commands */
// basics
#define gopro_off     "/bacpac/PW?t=" + String(epass) + "&p=%00" + String(httpver)
#define gopro_on      "/bacpac/PW?t=" + String(epass) + "&p=%01" + String(httpver)
#define stop_rec      "/bacpac/SH?t=" + String(epass) + "&p=%00" + String(httpver)
#define start_rec     "/bacpac/SH?t=" + String(epass) + "&p=%01" + String(httpver)

// camera modes
#define mode_capture  "/camera/CM?t=" + String(epass) + "&p=%0" + goproCommandVal + String(httpver)

// video resolution modes
#define video_size    "/camera/VV?t=" + String(epass) + "&p=%0" + goproCommandVal + String(httpver)

// frame rates
#define video_frRate  "/camera/FS?t=" + String(epass) + "&p=%0" + goproCommandVal + String(httpver)

// Field of view 
#define video_fov     "/camera/FV?t=" + String(epass) + "&p=%0" + goproCommandVal + String(httpver)

// Photo resolution
#define photo_size    "/camera/PR?t=" + String(epass) + "&p=%0" + goproCommandVal + String(httpver)

// States
#define status_bacpac  "/bacpac/se?t=" + String(epass) + String(httpver) // WiFi bacpac can report GoPro on/off status
#define status_gopro   "/camera/sx?t=" + String(epass) + String(httpver) // receive a detailed status of the gopro hero
#define status_batt    "/camera/se?t=" + String(epass) + String(httpver) // receive a detailed status of the gopro hero
#define gopro_version  "/camera/cv" + String(httpver)

/* GoPro command Responses */
const char* respons_ok     = "HTTP/1.1 200 OK"; // command passed

String    line;           // response line from GoPro
String    CmdUrl;         
uint8_t   SendUrl;

uint8_t   WiFi_Connected;
uint8_t   goproPowered;
uint8_t   goproCommand;
uint8_t   goproCommandVal;
uint8_t   GoProStat;      // for HeartBeat status to AQ
uint8_t   resGood;        // respons valid flag 
uint8_t   reqGoProStatus; // request pending status
uint8_t   reqGoProPowered;// request pending powered
uint8_t   reqGoProVersion;// request pending version
uint8_t   reqGoProBatt;   // request pending battery in %
uint8_t   goproSeries;    // goPro main model series
uint8_t   goproModel;     // goPro model type
byte      extInfo[57];    // SE response is 31 bytes + eof, SX respons is 56 bytes
byte      stdInfo[32];    // SE response is 31 bytes + eof, SX respons is 56 bytes

/* * * * * * * * * * * * * * * * * * * * * * * * 
 * GoPro extended (/camera/sx) status structure
*/
typedef enum {
  camMode           = 2,  // current mode
  defaultMode       = 4,  // default startup mode
  spotMeter         = 5,  // spotmeter settings
  timelapsInterval  = 6,  // value between timelaps shots
  autoOff           = 7,  // autoOff setting
  vidFov            = 8,  // video Field of View (Wide, Med, Nar)
  photoRes          = 9,  // current photo resolution
  recMin            = 14, // recording minutes
  recSec            = 15, // recording seconds
  camOrientation    = 19, // up / down orientation
  battCharging      = 20, // batt charging stat  (in /SE this is the actual % left)
  photoRemain       = 23, // # photos remain on sdcard
  photoNum          = 25, // # photos
  vidRemain         = 27, // # video min remain on sdcard
  vidNum            = 29, // # video
  recordStat        = 30, // recording yes/no
  proTune           = 31, // protune yes/no
  whiteBalance      = 35, // whitebalance auto,3k,5k5,6k5,raw
  loopingTime       = 38, // looping off, 5,20,60,120min
  bat2Stat          = 46, // batteryPack #2
  camAssAttached    = 50, // attached on back: none,LCD,battery2
  vidSize           = 51, // current video resolution
  vidFPS            = 52, // current video fps
} goproExtendedInfo;

/* Global definitions */
#define COMMON_ANODE
#define rgbR    5
#define rgbG    16
#define rgbB    4

#define TRUE    1
#define FALSE   0

#ifdef SERDB
  #define _debugSerialBaud  115200
  #define _debugSerial Serial1
  #define DPL _debugSerial.println
  #define DPN _debugSerial.print
#endif

unsigned long   bootTime = millis();  /* timer since start of program */
unsigned long   tEventReq = 0;
unsigned long   tEventStatus = 0;
unsigned long   tEventFlashFreq =0;
unsigned long   tMavLed =0;
uint8_t         busy = FALSE;
uint8_t         timeOut = 0;          // wifi connection timeout
uint8_t         doSig = FALSE;
uint8_t         toCounter = 0;

#define STATFREQ    4000               // in milliseconds
#define MAVREQFREQ  8000 
#define HBFLASH     100 
#define FLASHFREQ   2500


/* MavLink */
#define _MavLinkSerial      Serial
#define _MavLinkSerialBaud  115200
#define MY_SYSID            MAV_TYPE_GIMBAL  // mavlink system id
#define MY_CMPID            72  // mavlink component id
#define GMBL_SysID          71  // default StorM32 SysID
#define GMBL_CompID         67  // default StorM32 CompId

uint8_t         buf[MAVLINK_MAX_PACKET_LEN];
uint16_t        hb_count;
static bool     mavlink_request = 0;
static uint16_t messageCounter;
static bool     mavlink_active  = 0;
unsigned long   MavLink_Connected_timer;

mavlink_message_t msg;
mavlink_system_t mavlink_system = {MY_SYSID,MY_CMPID,0,0};

// ******************************************
// Message #0  HEARTHBEAT 
uint8_t    aq_type = 0;
uint8_t    aq_autopilot = 0;
uint8_t    aq_base_mode = 0;
int32_t    aq_custom_mode = -1;
uint8_t    aq_system_status = 0;
uint8_t    aq_mavlink_version = 0;
uint8_t    aq_mav_system; 
uint8_t    aq_mav_component;

// Message #253 MAVLINK_MSG_ID_STATUSTEXT
uint16_t   aq_status_severity = 255;
uint16_t   aq_status_send_count = 0;
uint16_t   aq_status_text_id = 0;
mavlink_statustext_t statustext;


/* *******************************************
 * Wifi & webserver 
 */
String content;

const char* statStr[] = {"Off","On"};
const char* modeStr[] = {"Video","Photo","Burst","TimeLaps"};
