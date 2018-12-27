//
// Created by lucas on 12/22/18.
//

#ifndef INC_3X7DIGITDISPLAY_STATE_H
#define INC_3X7DIGITDISPLAY_STATE_H


#include <Arduino.h>

class State {

 public:

  uint8_t TimeDispl = 1;

  uint8_t SecDispl = 2;

  uint8_t DateDispl = 0;

  uint8_t YearDispl = 4;

  uint8_t brightnes = 0x06;
};
#endif //INC_3X7DIGITDISPLAY_STATE_H
