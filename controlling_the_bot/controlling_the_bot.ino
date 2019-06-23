/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.3.5 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.3.1 or later version;
     - for iOS 1.3.5 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "balkanbot"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,5,0,0,0,60,0,8,13,0,
  1,0,12,9,12,12,2,31,94,0,
  1,0,12,41,12,12,2,31,86,0,1
  1,0,77,9,12,12,2,31,94,0,
  1,0,77,41,12,12,2,31,86,0,
  2,0,39,26,22,11,2,26,31,31,
  79,78,0,79,70,70,0 };
  
// this structure defines all the variables of your control interface 
struct {

    // input variable
  uint8_t leftForward; // =1 if button pressed, else =0 
  uint8_t leftBackward; // =1 if button pressed, else =0 
  uint8_t rightForward; // =1 if button pressed, else =0 
  uint8_t rightBackward; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

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
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_LEFTFORWARD, (RemoteXY.leftForward==0)?LOW:HIGH);
  digitalWrite(PIN_LEFTBACKWARD, (RemoteXY.leftBackward==0)?LOW:HIGH);
  digitalWrite(PIN_RIGHTFORWARD, (RemoteXY.rightForward==0)?LOW:HIGH);
  digitalWrite(PIN_RIGHTBACKWARD, (RemoteXY.rightBackward==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer


}
