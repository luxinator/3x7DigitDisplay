//
// Created by lucas on 12/28/18.
//

#ifndef INC_3X7DIGITDISPLAY_WIFICONFIG_H
#define INC_3X7DIGITDISPLAY_WIFICONFIG_H

/**
 * Simple wrapper no need for shared_ptr/unique_ptr stuff..
 */
class WifiConfig {
  char *ssid;
  char *password;


 public:
  void setSSID(char *new_ssid) {
    if (ssid == nullptr) {
      ssid = new_ssid;
    } else if (strcmp(ssid, new_ssid) != 0) {
      delete ssid;
      this->ssid = new_ssid;
    } else {
      delete new_ssid;
    }
  }

  void setPassword(char *new_password) {
    if (password == nullptr) {
      password = new_password;
    } else if (strcmp(password, new_password) != 0) {
      delete password;
      this->password = new_password;
    } else {
      delete new_password;
    }
  }

  char *getSSID() {
    return ssid;
  }

  char *getPassword() {
    return password;
  }

  ~WifiConfig() {
    delete ssid;
    delete password;
  }

};

#endif //INC_3X7DIGITDISPLAY_WIFICONFIG_H
