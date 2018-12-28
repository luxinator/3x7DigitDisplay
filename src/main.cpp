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

WiFiUDP ntpUDP;

// By default 'pool.ntp.org' is used with 60 seconds update interval and
// no offset
NTPClient timeClient(ntpUDP);

Display display;

State state;

StorageManager storageManager;

uint8_t brightness;

void wifiLoop() {
  display.showConn(0);

  while (true) {
    Serial.println("Getting SSID and Password from storage");
    display.showConn(0);

    ssid = storageManager.getSSID();
    password = storageManager.getPass();

    if (ssid != nullptr && password != nullptr) {

      Serial.printf("Trying: %s", ssid);

      WiFi.begin(ssid, password);

      int retryCount = 0;

      while (WiFi.status() != WL_CONNECTED && retryCount < 15) {
        delay(500);
        Serial.print(".");
        display.toggleSpinner(2);
        retryCount++;
      }

      if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Connected");
        Serial.print("IP: ");
        Serial.println(WiFi.localIP());
        return;
      }
    }

    // TODO: switch to ap mode
    Serial.println("Changing to AP mode");
    bool ap = WiFi.softAP("CLOCK_AP", "CLOCK_AP");
    Serial.println(WiFi.softAPIP());
    display.showAP(MIDDLE_DI);

  }
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  //TODO: Remove when AP mode works
  storageManager.storeWifiCredentials("OpenWRT2", "DF7E565ADE3F");
  storageManager.storeDisplayState(state);

  wifiLoop();

  storageManager.getDisplayState(state);

  timeClient.begin();
  Serial.println("Starting Loop");

}

void loop() {

  //Read state set displays
  display.setBrightness(state.brightnes);

  // Time stuff:
  timeClient.update();
  timeClient.setTimeOffset(state.time_correction);
  time_t time = timeClient.getEpochTime();

  int t = hour(time) * 100 + minute(time);

  display.setTime(t, state.TimeDispl);
  display.setNumber(second(time), state.SecsDispl);
  display.setTime(month(time) * 100 + day(time), state.DateDispl);
  display.setNumber(year(time), state.YearDispl);

  delay(450);
}
