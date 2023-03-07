#define BLYNK_TEMPLATE_ID "xyz"
#define BLYNK_TEMPLATE_NAME "xyz"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

WiFiUDP ntpUDP;
const long utcOffsetInSeconds = 19800;
NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", utcOffsetInSeconds);

int pin0 = 16;
int pin1 = 5;
int pin2 = 4;
int pin3 = 10;

int startTime1;
int endTime1;
int startTime2;
int endTime2;
int startTime3;
int endTime3;
int startTime4;
int endTime4;

void setup()
{
  Serial.begin(115200);
  delay(100);

  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
 
  digitalWrite(pin0, HIGH);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);

  timeClient.begin();
 
  BlynkEdgent.begin();
}

BLYNK_WRITE(V0)
{
    int value = param.asInt();
    if(value == 1)
      digitalWrite(pin0, LOW);
    else
      digitalWrite(pin0, HIGH);
}

BLYNK_WRITE(V1)
{
    int value = param.asInt();
    if(value == 1)
      digitalWrite(pin1, LOW);
    else
      digitalWrite(pin1, HIGH);
}

BLYNK_WRITE(V2)
{
    int value = param.asInt();
    if(value == 1)
      digitalWrite(pin2, LOW);
    else
      digitalWrite(pin2, HIGH);
}

BLYNK_WRITE(V3)
{
    int value = param.asInt();
    if(value == 1)
      digitalWrite(pin3, LOW);
    else
      digitalWrite(pin3, HIGH);
}


BLYNK_WRITE(V4){
 startTime1 = param[0].asInt();
 endTime1 = param[1].asInt();
 if(startTime1 == 0 && endTime1 == 0)
 {
  startTime1 = 999999;
  endTime1 = 999999;
 }
}

BLYNK_WRITE(V5){
 startTime2 = param[0].asInt();
 endTime2 = param[1].asInt();
 if(startTime2 == 0 && endTime2 == 0)
 {
  startTime2 = 999999;
  endTime2 = 999999;
 }
}

BLYNK_WRITE(V6){
 startTime3 = param[0].asInt();
 endTime3 = param[1].asInt();
 if(startTime3 == 0 && endTime3 == 0)
 {
  startTime3 = 999999;
  endTime3 = 999999;
 }
}

BLYNK_WRITE(V7){
 startTime4 = param[0].asInt();
 endTime4 = param[1].asInt();
 if(startTime4 == 0 && endTime4 == 0)
 {
  startTime4 = 999999;
  endTime4 = 999999;
 }
}

void loop() {
  timeClient.update();
  int HH = timeClient.getHours();
  int MM = timeClient.getMinutes();
  int SS = timeClient.getSeconds();
  int server_time = 3600*HH + 60*MM + SS;

   if(startTime1 == server_time)
   {
    digitalWrite(pin0, LOW);
   }

   if(startTime2 == server_time)
   {
   digitalWrite(pin1, LOW);
   }

   if(startTime3 == server_time)
   {
   digitalWrite(pin2, LOW);
   }

   if(startTime4 == server_time)
   {
   digitalWrite(pin3, LOW);
   }
   
   if(endTime1 == server_time)
   {
   digitalWrite(pin0, HIGH);
   }

   if(endTime2 == server_time)
   {
   digitalWrite(pin1, HIGH);
   }

   if(endTime3 == server_time)
   {
   digitalWrite(pin2, HIGH);
   }

   if(endTime4 == server_time)
   {
   digitalWrite(pin3, HIGH);
   }
 
  BlynkEdgent.run();
 
}
