//
// Created by lucas on 12/25/18.
//

#ifndef INC_3X7DIGITDISPLAY_STORAGEMANAGER_H
#define INC_3X7DIGITDISPLAY_STORAGEMANAGER_H

// Check code for eeprom storage
// https://circuits4you.com/2016/12/16/esp8266-internal-eeprom-arduino/

#include "State.h"


/**
 * Uses the EEPROM to store stuff
 * layout is as follows:
 * [ State, SSID + \0, pass + \0 ]
 */
class StorageManager {

  const size_t STATE_BASE_ADDR = 0x0;
  const size_t MAX_ADDR = 512;
  const size_t CREDN_BASE_ADDR = STATE_BASE_ADDR + sizeof(State);
  const uint8_t SEPERATOR = 0xFF;

 public:
  StorageManager();

  bool storeWifiCredentials(const char *SSID, const char *pass);

  char* getSSID();

  char* getPass();

  void storeDisplayState(const State *state);

  void getDisplayState(State *state);

};

#endif //INC_3X7DIGITDISPLAY_STORAGEMANAGER_H
