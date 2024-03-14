#include "SPI.h"
#include "LedControl.h"

// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define DATA_PIN 50
#define CLK_PIN 51
#define CS_PIN 53

LedControl lc = LedControl (DATA_PIN,CLK_PIN,CS_PIN,1);

void setup() {
  // we have to do a wakeup call
  lc.shutdown(0,false);

  // set the brightness to a medium value
  lc.setIntensity(0,0); 
}

void loop() {
    for(int x = 0; x < 8; x++) {
    for(int y = 0; y < 8; y++) {
      if(random(0,2) == 0) {
        lc.setLed(0, x, y, true);
      } else {
        lc.setLed(0, x, y, false);
      }
    }
  }

  delay(10);
}