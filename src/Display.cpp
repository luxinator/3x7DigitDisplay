//
// Created by lucas on 12/22/18.
//

#include <Arduino.h>
#include "Display.h"



Display::Display() {
  this->setBrightness(0x0f);

  for(int i = 0;  i < 3; i++) {
     displays[i].clear();
     displays[i].showNumberDec(8888);
     delay(500);
     this->setNumber(7777, i);
  }
}

void Display::setBrightness(uint8_t v){
  for(int i = 0;  i < 3; i++) {
    displays[i].setBrightness(v);
    }
};

void Display::setTime(int time, int d){
  displays[d].showNumberDecEx(time, 0b01000000);
}

void Display::setNumber(int n, int d) {
  displays[d].showNumberDecEx(n);
}

void Display::showDone(int d) {
    displays[d].setSegments(SEG_DONE);
}

void Display::showConn(int d){
    displays[d].setSegments(CONN);
}

void Display::toggleSpinner(int d){
  segs[0]++;
  displays[d].setSegments(segs);
}