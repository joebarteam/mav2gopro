#ifndef GOPRO_COMMAND
#define GOPRO_COMMAND
typedef enum GOPRO_COMMAND
{
	GOPRO_COMMAND_POWER=1, 			/* (Get/Set) | val 0 or 1 (ON)*/
	GOPRO_COMMAND_CAPTURE_MODE=2, 		/* (Get/Set) | */
	GOPRO_COMMAND_SHUTTER=3,		/* (___/Set) | val 0 or 1 (ON)*/
	GOPRO_COMMAND_BATTERY=4,		/* (Get/___) | */
	GOPRO_COMMAND_MODEL=5,                  /* not used */
	GOPRO_COMMAND_VIDSIZE=6,		/* (Get/___) | */
	GOPRO_COMMAND_FPS=7,			/* (Set/___) | */
	GOPRO_COMMAND_FOV=8,			/* (Set/___) | */	
} GOPRO_COMMAND;
#endif

#ifndef GOPRO_PWR
#define GOPRO_PWR
typedef enum GOPRO_PWR
{
	GOPRO_PWR_ON=1, 			/* (Get/Set) | */
	GOPRO_PWR_OFF=2, 			/* (Get/Set) | */
} GOPRO_PWR;
#endif

#ifndef GOPRO_SHUT
#define GOPRO_SHUT
typedef enum GOPRO_SHUT
{
	GOPRO_SHUT_REC=1, 			/* (Get/Set) | */
	GOPRO_SHUT_STOP=2,			/* (Get/Set) | */
} GOPRO_SHUT;
#endif

#ifndef GOPRO_MODE
#define GOPRO_MODE
typedef enum GOPRO_MODE
{
	GOPRO_MODE_VID=0, 			/* (Get/Set) | */
	GOPRO_MODE_PHOTO=1,			/* (Get/Set) | */
	GOPRO_MODE_BURST=2,	 		/* (Get/Set) | */
	GOPRO_MODE_TIMLAP=3,                    /* (Get/Set) | */
        GOPRO_MODE_MENU=4,
} GOPRO_MODE;
#endif

#ifndef GOPRO_VIDSIZE
#define GOPRO_VIDSIZE
typedef enum GOPRO_VIDSIZE
{
	GOPRO_VIDSIZE_720=1, 			/* (Get/Set) | */
	GOPRO_VIDSIZE_940=2,			/* (Get/Set) | */
	GOPRO_VIDSIZE_1080=3,	 		/* (Get/Set) | */
	GOPRO_VIDSIZE_2k7=4,			/* (Get/Set) | */
        GOPRO_VIDSIZE_2k7cin=5,			/* (Get/Set) | */
        GOPRO_VIDSIZE_4k=6,			/* (Get/Set) | */
        GOPRO_VIDSIZE_4kcin=7,			/* (Get/Set) | */
        GOPRO_VIDSIZE_1080SUPER=8,		/* (Get/Set) | */
        GOPRO_VIDSIZE_720SUPER=9,		/* (Get/Set) | */
} GOPRO_VIDSIZE;
#endif

#ifndef GOPRO_FPS
#define GOPRO_FPS
typedef enum GOPRO_FPS
{
	GOPRO_FPS12=0,                          /* (Get/Set) | */
	GOPRO_FPS15=1,                          /* (Get/Set) | */
	GOPRO_FPS24=2,                          /* (Get/Set) | */
        GOPRO_FPS25=3,                          /* (Get/Set) | */
        GOPRO_FPS30=4,                          /* (Get/Set) | */
        GOPRO_FPS48=5,                          /* (Get/Set) | */
        GOPRO_FPS50=6,                          /* (Get/Set) | */
        GOPRO_FPS60=7,                          /* (Get/Set) | */
        GOPRO_FPS100=8,                         /* (Get/Set) | */
        GOPRO_FPS120=9,                         /* (Get/Set) | */
        GOPRO_FPS240=10,                        /* (Get/Set) | */
} GOPRO_FPS;
#endif

#ifndef GOPRO_FOV
#define GOPRO_FOV
typedef enum GOPRO_FOV
{
	GOPRO_FOV_W=1,	 			/* (Get/Set) | */
	GOPRO_FOV_M=2,				/* (Get/Set) | */
	GOPRO_FOV_N=3,				/* (Get/Set) | */
} GOPRO_FOV;
#endif

#ifndef GOPRO_VERSION_3
#define GOPRO_VERSION_3
typedef enum GOPRO_VERSION_3
{
  GOPRO_HERO3WHITE=1,
  GOPRO_HERO3SILVER=2,
  GOPRO_HERO3BLACK=3,
  GOPRO_HERO3PLUSSILVER=10,
  GOPRO_HERO3PLUSBLACK=11,
} GOPRO_VERSION_3;
#endif

#ifndef GOPRO_VERSION_4
#define GOPRO_VERSION_4
typedef enum GOPRO_VERSION_4
{
  GOPRO_HERO4SILVER=1,
  GOPRO_HERO4BLACK=3,
} GOPRO_VERSION_4;
#endif

#ifndef HAVE_ENUM_GOPRO_HEARTBEAT_STATUS
#define HAVE_ENUM_GOPRO_HEARTBEAT_STATUS
typedef enum GOPRO_HEARTBEAT_STATUS
{
	GOPRO_HEARTBEAT_STATUS_DISCONNECTED=0, /* No GoPro connected | */
	GOPRO_HEARTBEAT_STATUS_INCOMPATIBLE=1, /* The detected GoPro is not Mav2GoPro compatible | */
	GOPRO_HEARTBEAT_STATUS_CONNECTED_POWER_OFF=2, /* A Mav2GoPro compatible GoPro is connected | */
	GOPRO_HEARTBEAT_STATUS_CONNECTED_POWER_ON=3, /* A Mav2GoPro compatible GoPro is connected | */
	GOPRO_HEARTBEAT_STATUS_RECORDING=4, /* A Mav2GoPro compatible GoPro is connected and recording | */
	GOPRO_HEARTBEAT_STATUS_ERR_OVERTEMP=5, /* A Mav2GoPro compatible GoPro is connected and overtemperature | */
	GOPRO_HEARTBEAT_STATUS_ERR_STORAGE=6, /* A Mav2GoPro compatible GoPro is connected and storage is missing or full | */
	GOPRO_HEARTBEAT_STATUS_ENUM_END=7, /*  | */
} GOPRO_HEARTBEAT_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_GOPRO_SET_RESPONSE_RESULT
#define HAVE_ENUM_GOPRO_SET_RESPONSE_RESULT
typedef enum GOPRO_SET_RESPONSE_RESULT
{
	GOPRO_SET_RESPONSE_RESULT_FAILURE=0, /* The write message with ID indicated failed | */
	GOPRO_SET_RESPONSE_RESULT_SUCCESS=1, /* The write message with ID indicated succeeded | */
	GOPRO_SET_RESPONSE_RESULT_ENUM_END=2, /*  | */
} GOPRO_SET_RESPONSE_RESULT;
#endif 
