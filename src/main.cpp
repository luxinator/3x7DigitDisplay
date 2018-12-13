#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 10
#define DIO_D1 9
#define DIO_D2 8
#define DIO_D3 7

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   500

TM1637Display disp1(CLK, DIO_D1);
TM1637Display disp2(CLK, DIO_D2);
TM1637Display disp3(CLK, DIO_D3);

TM1637Display displays[] {disp1, disp2, disp3 };

void setup()
{
}

void DoFor(uint8_t d){

  int k;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };

  TM1637Display disp = displays[d];
  
  disp.setBrightness(0x0f);
  // All segments on
  delay(TEST_DELAY);
  // Selectively set different digits
  data[0] = disp.encodeDigit(0);
  data[1] = disp.encodeDigit(1);
  data[2] = disp.encodeDigit(2);
  data[3] = disp.encodeDigit(3);
  disp.setSegments(data);
    
  delay(TEST_DELAY);
  
	// Run through all the dots
	for(k=0; k <= 4; k++) {
		disp.showNumberDecEx(0, (0x80 >> k), true);
		delay(TEST_DELAY);
	}
}

void loop()
{
  for (uint8_t i = 0; i < 3; i++){
    DoFor(i);
  }
}
