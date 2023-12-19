// #include "class/hid/hid_device.h"
#include <Adafruit_NeoPixel.h>

void readSwitch(uint8_t switchToRead) {

  digitalWrite(6, bitRead(switchToRead, 0));  //Write the translated bit to the correct select-channel on the MUX'es
  digitalWrite(7, bitRead(switchToRead, 1));
  digitalWrite(8, bitRead(switchToRead, 2));
  digitalWrite(9, bitRead(switchToRead, 3));

  if (switchToRead >= 0 && switchToRead <= 15) {
    mux = 0;
    muxChannel = switchToRead;
    switchValue = analogRead(0);

    if (debug) {
      Serial.print(bitRead(switchToRead, 3));
      Serial.print(bitRead(switchToRead, 2));
      Serial.print(bitRead(switchToRead, 1));
      Serial.print(bitRead(switchToRead, 0));
      Serial.print(analogRead(0));
      Serial.println("  1   ");
    }
  } else if (switchToRead >= 16 && switchToRead <= 31) {
    mux = 1;
    muxChannel = switchToRead - 16;
    switchValue = analogRead(1);

    if (debug) {
      Serial.print(bitRead(switchToRead, 3));
      Serial.print(bitRead(switchToRead, 2));
      Serial.print(bitRead(switchToRead, 1));
      Serial.print(bitRead(switchToRead, 0));
      Serial.print(analogRead(1));
      Serial.println("  2   ");
    }
  } else if (switchToRead >= 32 && switchToRead <= 47) {
    mux = 2;
    muxChannel = switchToRead - 32;
    switchValue = analogRead(2);

    if (debug) {
      Serial.print(bitRead(switchToRead, 3));
      Serial.print(bitRead(switchToRead, 2));
      Serial.print(bitRead(switchToRead, 1));
      Serial.print(bitRead(switchToRead, 0));
      Serial.print(analogRead(2));
      Serial.println("  3   ");
    }
  } else if (switchToRead >= 48 && switchToRead <= 63) {
    mux = 3;
    muxChannel = switchToRead - 48;
    switchValue = analogRead(3);

    if (debug) {
      Serial.print(bitRead(switchToRead, 3));
      Serial.print(bitRead(switchToRead, 2));
      Serial.print(bitRead(switchToRead, 1));
      Serial.print(bitRead(switchToRead, 0));
      Serial.print(analogRead(3));
      Serial.println("  4   ");
    }
  } else if (switchToRead >= 64 && switchToRead <= 79) {
    mux = 4;
    muxChannel = switchToRead - 64;
    switchValue = analogRead(4);

    if (debug) {
      Serial.print(bitRead(switchToRead, 3));
      Serial.print(bitRead(switchToRead, 2));
      Serial.print(bitRead(switchToRead, 1));
      Serial.print(bitRead(switchToRead, 0));
      Serial.print(analogRead(4));
      Serial.println("  5   ");
    }
  } else {
    // Handle any other cases or errors here
  }
}

void switchMap() {
  mappedSwitchValue = map(switchValue, switchValues[mux][muxChannel][0], switchValues[mux][muxChannel][1], 0, 100);
}

void switchCalibration() {
  while (switchValues[mux][muxChannel][0] > (switchValue - 50)) {
    switchValues[mux][muxChannel][0]--;
    Serial.println("switchVal-");
  }
  while (switchValues[mux][muxChannel][1] < (switchValue + 50)) {
    switchValues[mux][muxChannel][1]++;
    Serial.println("switchVal+");
  }
}

// void calibration(uint8_t mux, uint8_t muxChannel, uint8_t switchValue) {  //FEL
//   while (switchValue < switchValues[mux][muxChannel][0]) {
//     switchValues[mux][muxChannel][0]--;
//     /*Serial.println();
//     Serial.print(switchValues[mux][muxChannel][0]);
//     Serial.print("          ");
//     Serial.print(mux);
//     Serial.print(muxChannel);*/
//   }
//   while (switchValue > switchValues[mux][muxChannel][1]) {
//     switchValues[mux][muxChannel][1]++;
//   }
// }
