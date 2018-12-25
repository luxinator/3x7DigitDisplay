//
// Created by lucas on 12/22/18.
//

#ifndef INC_3X7DIGITDISPLAY_STATE_H
#define INC_3X7DIGITDISPLAY_STATE_H


#include <Arduino.h>

class State {

 public:

  bool ShowStatus;

  bool ShowTime;

  bool ShowMessage;

  String message;

};
#endif //INC_3X7DIGITDISPLAY_STATE_H
