//
// Created by lucas on 12/22/18.
//

#include <Arduino.h>
#include "Display.h"

Display::Display() {
  this->setBrightness(0x0f);
  for (int i = 0; i < 3; i++) {
    displays[i].clear();
  }
}

void Display::setBrightness(uint8_t v) {
  for (int i = 0; i < 3; i++) {
    displays[i].setBrightness(v);
  }
};

void Display::setTime(int time, int d) {
  if(d >= 0 && d < 4)
    displays[d].showNumberDecEx(time, 0b01000000);

}

void Display::setNumber(int n, int d) {
  if(d >= 0 && d < 4)
    displays[d].showNumberDecEx(n);
}

void Display::showDone(int d) {
  if(d >= 0 && d < 4)
    displays[d].setSegments(SEG_DONE);
}

void Display::showConn(int d) {
  if(d >= 0 && d < 4)
    displays[d].setSegments(CONN);
}

void Display::toggleSpinner(int d) {
  if(d >= 0 && d < 4) {
    if (segs[0] == 0) {
      segs[0] = SEG_A;
      segs[1] = SEG_B;
      segs[2] = SEG_C;
      segs[3] = SEG_D;
    }
    segs[0] = segs[0] << 1;
    segs[1] = segs[1] << 1;
    segs[2] = segs[2] << 1;
    segs[3] = segs[3] << 1;

    displays[d].setSegments(segs);
  }
}
void Display::showAP(int display) {
  displays[display].setSegments(AP);
}
