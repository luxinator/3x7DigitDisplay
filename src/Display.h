//
// Created by lucas on 12/22/18.
//

#ifndef INC_3X7DIGITDISPLAY_DISPLAY_H
#define INC_3X7DIGITDISPLAY_DISPLAY_H


#include <TM1637Display.h>

#define LEFT_DISP 0
#define RIGHT_DIS 1
#define MIDDLE_DI 2


// Module connection pins (Digital Pins)
#define CLK 4
#define DIO_D3 12
#define DIO_D1 14
#define DIO_D2 5

const uint8_t SEG_DONE[] = {
    SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
    SEG_C | SEG_E | SEG_G,                          // n
    SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

const uint8_t CONN[] = {
    SEG_A | SEG_F | SEG_E | SEG_D,                  // C
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
    SEG_C | SEG_E | SEG_G,                          // n
    SEG_C | SEG_E | SEG_G,                          // n
};

const uint8_t AP[] = {
    SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,  // A
    SEG_A | SEG_B | SEG_E | SEG_F | SEG_G,          // P
    0,
    0
};


class Display{

  TM1637Display displays[3] = {
      TM1637Display(CLK, DIO_D1),
      TM1637Display(CLK, DIO_D2),
      TM1637Display(CLK, DIO_D3)
  };

  uint8_t segs[4] = {0, 0, 0, 0};


 public:

  Display();

  /**
   * Set the right display to the time given as an int.
   * HH.mm
   * @param time
   */
  void setTime(int time, int d);

  /**
   * Set display to number
   * @param number - number to set
   * @param display - display
   */
  void setNumber(int number, int display);

  /**
   * sets brightness of all displays
   * @param value
   */
  void setBrightness(uint8_t value);

  void showDone(int display);

  void showAP(int display);

  void showConn(int display);


  void toggleSpinner(int display);
};

#endif //INC_3X7DIGITDISPLAY_DISPLAY_H
