#include <Arduino.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


#include "Clock.h"
#include "State.h"
#include "Display.h"

const char *ssid     = "OpenWRT2";
const char *password = "DF7E565ADE3F";


WiFiUDP ntpUDP;

// By default 'pool.ntp.org' is used with 60 seconds update interval and
// no offset
NTPClient timeClient(ntpUDP);

Display display;

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

uint8_t br = 0;

void loop()
{
  // show message

  // show time

  // show status

  // Update user defined stuff

  timeClient.update();

  int t = timeClient.getMinutes() + timeClient.getHours() * 100;
  display.setTime(t, LEFT_DISP);

  display.setNumber(timeClient.getSeconds(), RIGHT_DIS);

  display.setBrightness(br);

  delay(1000);

}
