#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>


#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "balkanbot"
#define REMOTEXY_SERVER_PORT 6377


#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,5,0,0,0,60,0,8,13,0,
  1,0,12,9,12,12,2,31,94,0,
  1,0,12,41,12,12,2,31,86,0,1
  1,0,77,9,12,12,2,31,94,0,
  1,0,77,41,12,12,2,31,86,0,
  2,0,39,26,22,11,2,26,31,31,
  79,78,0,79,70,70,0 };
  

struct {


  uint8_t leftForward; // =1 if button pressed, else =0 
  uint8_t leftBackward; 
  uint8_t rightForward; 
  uint8_t rightBackward; 


} RemoteXY;
#pragma pack(pop)


#define PIN_LEFTFORWARD D2
#define PIN_LEFTBACKWARD D3
#define PIN_RIGHTFORWARD D6
#define PIN_RIGHTBACKWARD D7


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_LEFTFORWARD, OUTPUT);
  pinMode (PIN_LEFTBACKWARD, OUTPUT);
  pinMode (PIN_RIGHTFORWARD, OUTPUT);
  pinMode (PIN_RIGHTBACKWARD, OUTPUT);
  

}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_LEFTFORWARD, (RemoteXY.leftForward==0)?LOW:HIGH);
  digitalWrite(PIN_LEFTBACKWARD, (RemoteXY.leftBackward==0)?LOW:HIGH);
  digitalWrite(PIN_RIGHTFORWARD, (RemoteXY.rightForward==0)?LOW:HIGH);
  digitalWrite(PIN_RIGHTBACKWARD, (RemoteXY.rightBackward==0)?LOW:HIGH);
  

}
