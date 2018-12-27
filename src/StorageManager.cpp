//
// Created by lucas on 12/25/18.
//

#include <EEPROM.h>
#include "StorageManager.h"

bool StorageManager::storeWifiCredentials(const char *SSID, const char *pass) {
  Serial.println("\nStoring SSID and Pass to EEPROM");

  size_t j = CREDN_BASE_ADDR;
  size_t maxRange = CREDN_BASE_ADDR + strlen(SSID) + strlen(pass) + 2;
  // cannot store strings to long
  if (maxRange > MAX_ADDR) {
    return false;
  }

  size_t range = CREDN_BASE_ADDR + strlen(SSID);
  for (; j < range; ++j) {
    auto c = (uint8_t) SSID[j - CREDN_BASE_ADDR];
    EEPROM.write(j, c);
  }
  EEPROM.write(j, SEPERATOR);
  j++;

  for (; j < maxRange; ++j) {
    EEPROM.write(j, (uint8_t) pass[j - (CREDN_BASE_ADDR + strlen(SSID) + 1)]);
  }
  EEPROM.write(j, SEPERATOR);

  EEPROM.commit();

  return true;

}

char *StorageManager::getSSID() {
  size_t i = CREDN_BASE_ADDR;

  //get size of ssid:
  while (EEPROM.read(i) != SEPERATOR && i < MAX_ADDR) {
    i++;
  }
  if (i >= MAX_ADDR) {
    return nullptr;
  }
  char *ssid = new char[i - CREDN_BASE_ADDR];
  size_t endAddr = i;
  for (i = CREDN_BASE_ADDR; i < endAddr; i++) {
    ssid[i - CREDN_BASE_ADDR] = EEPROM.read(i);
  }

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
char *StorageManager::getPass() {
  size_t i = CREDN_BASE_ADDR;

  //get size of ssid:
  while (EEPROM.read(i) != SEPERATOR && i < MAX_ADDR) {
    i++;
  }
  i++;

  size_t pass_begin = i;
  while (EEPROM.read(i) != SEPERATOR && i < MAX_ADDR) {
    i++;
  }

  if (i >= MAX_ADDR) {
    return nullptr;
  }
  char *pass = new char[i - pass_begin];
  size_t endAddr = i;

  for (i = pass_begin; i < endAddr; i++) {
    pass[i - pass_begin] = EEPROM.read(i);
  }
  return pass;
}
