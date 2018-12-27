//
// Created by lucas on 12/25/18.
//

#include <EEPROM.h>
#include "StorageManager.h"

bool StorageManager::storeWifiCredentials(const char *SSID, const char *pass) {
  Serial.println("\nStoring SSID and Pass to EEPROM");

  size_t j = CREDN_BASE_ADDR;

  // cannot store strings to long
  if (CREDN_BASE_ADDR + strlen(SSID) + strlen(pass) + 2 > MAX_ADDR) {
    return false;
  }

  size_t range = CREDN_BASE_ADDR + strlen(SSID);
  for (; j < range; ++j) {
    auto c = (uint8_t) SSID[j - CREDN_BASE_ADDR];
    EEPROM.write(j, c);
    Serial.print(SSID[j - CREDN_BASE_ADDR]);
  }
  EEPROM.write(j, SEPERATOR);
  j++;
  Serial.println();

  range = CREDN_BASE_ADDR + strlen(SSID) + strlen(pass);
  for (; j < range; ++j) {
    EEPROM.write(j, (uint8_t) pass[j - (CREDN_BASE_ADDR + strlen(SSID))]);
    Serial.print(pass[j - (CREDN_BASE_ADDR + strlen(SSID))]);
  }
  Serial.println();
  EEPROM.write(j, SEPERATOR);

  EEPROM.commit();

  return true;

}

char *StorageManager::getSSID() {
  size_t i = CREDN_BASE_ADDR;
  Serial.printf("CREDN_BASE_ADDR: %d\n",i);

  //get size of ssid:
  char c = ' ';
  while (c != SEPERATOR && i < MAX_ADDR) {
    c = EEPROM.read(i);
    Serial.print(c);
    i++;
  }

  Serial.printf("SSID Size: %d\n", i - CREDN_BASE_ADDR);

  if (i >= MAX_ADDR) {
    return nullptr;
  }
  char *ssid = new char[i - CREDN_BASE_ADDR];
  size_t endAddr = i;
  for (i = CREDN_BASE_ADDR; i < endAddr; i++) {
    ssid[i - CREDN_BASE_ADDR] = EEPROM.read(i);
    Serial.print(ssid[i - CREDN_BASE_ADDR]);
  }
  Serial.print('\n');
  return ssid;
}

void StorageManager::storeDisplayState(const State *state) {
  EEPROM.write(STATE_BASE_ADDR, state->YearDispl);
  EEPROM.write(STATE_BASE_ADDR + 1, state->DateDispl);
  EEPROM.write(STATE_BASE_ADDR + 2, state->SecsDispl);
  EEPROM.write(STATE_BASE_ADDR + 3, state->brightnes);
  EEPROM.write(STATE_BASE_ADDR + 4, state->TimeDispl);
  EEPROM.write(STATE_BASE_ADDR + 5, state->time_correction);
}

void StorageManager::getDisplayState(State *state) {
  state->YearDispl = EEPROM.read(STATE_BASE_ADDR);
  state->DateDispl = EEPROM.read(STATE_BASE_ADDR + 1);
  state->SecsDispl = EEPROM.read(STATE_BASE_ADDR + 2);
  state->brightnes = EEPROM.read(STATE_BASE_ADDR + 3);
  state->TimeDispl = EEPROM.read(STATE_BASE_ADDR + 4);
  state->time_correction = EEPROM.read(STATE_BASE_ADDR + 5);
}

StorageManager::StorageManager() {
  EEPROM.begin(512);
}
