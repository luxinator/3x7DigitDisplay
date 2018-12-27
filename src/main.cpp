#include <Arduino.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <EEPROM.h>
#include <Time.h>
#include <SPISlave.h>

#include "Clock.h"
#include "State.h"
#include "Display.h"
#include "StorageManager.h"

char ssid[] = "OpenWRT2";
char password[] = "DF7E565ADE3F";

WiFiUDP ntpUDP;

// By default 'pool.ntp.org' is used with 60 seconds update interval and
// no offset
NTPClient timeClient(ntpUDP);

Display display;

State state;

StorageManager storageManager;

uint8_t brightness;

void setup() {
  Serial.begin(115200);


//  storageManager.storeDisplayState(&state);

  storageManager.storeWifiCredentials(ssid, password);
  char *ssid2 = storageManager.getSSID();
  if (ssid2 == nullptr){
    Serial.println("FAILURE");
  }
  else {
    for (size_t i = 0; i < strlen(ssid); ++i) {
      Serial.printf("SSID: %c, ssid2: %c\n", ssid[i], ssid2[i]);
    }
  }

  WiFi.begin(ssid, password);

  display.showConn(0);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    display.toggleSpinner(2);
  }

  timeClient.begin();
  display.showConn(0);
  brightness = 5;
}

void loop() {
  // show message

  // show time

  // show status

  // Update user defined stuff


  //Read state set displays



  display.setBrightness(state.brightnes);

  timeClient.update();
  timeClient.setTimeOffset(state.time_correction);
  time_t time = timeClient.getEpochTime();

  int t = hour(time) * 100 + minute(time);  // timeClient.getMinutes() + timeClient.getHours() * 100;

  display.setTime(t, state.TimeDispl);
  display.setNumber(second(time), state.SecsDispl);
  display.setTime(month(time) * 100 + day(time), state.DateDispl);
  display.setNumber(year(time), state.YearDispl);

  delay(500);

}
