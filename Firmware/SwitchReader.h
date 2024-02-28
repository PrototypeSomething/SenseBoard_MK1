#include <Adafruit_NeoPixel.h>  // apparently includes neopixel here, I had an error about a year or so ago that made me put this here and it worked out fine, I don't remember what triggered this

void readSwitch(uint8_t switchToRead) {  // function to read the correct switch depending on input value
  //first translates the input value to 4 bit, then writes those 4 bits to multiplexer select pins
  //if statements to read the correct multiplexer depending on which mux the selected switch/switchToRead is located on (16 channels per mux and 5 muxes, the rest should be self explanatory)

  digitalWrite(6, bitRead(switchToRead, 0));  //Write the translated bit to the correct select-channel on the MUX'es
  digitalWrite(7, bitRead(switchToRead, 1));
  digitalWrite(8, bitRead(switchToRead, 2));
  digitalWrite(9, bitRead(switchToRead, 3));

  if (switchToRead >= 0 && switchToRead <= 15) {
    mux = 0;  // Sets mux to the one being read
    muxChannel = switchToRead;  // sets channel to the one being read on
    switchValue = analogRead(0);  // sets switchValue to current analoge value of the switch being read

    if (debug) {  // I'm sorry for the mess with these blocks of serial print lines, as ive said, I wrote this over a year ago and was not very good at this stuff at the time, will clean up in the future
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

void switchMap() {  // maps value of how far down a switch is pressed
  mappedSwitchValue = map(switchValue, switchValues[mux][muxChannel][0], switchValues[mux][muxChannel][1], 0, 100);
}

void switchCalibration() {  // function to calibrate switch min and max values
  if (switchValues[mux][muxChannel][0] > (switchValue + 50)) {
    switchValues[mux][muxChannel][0] = switchValue + 50;
    Serial.println(switchValue);
  }
  if (switchValues[mux][muxChannel][1] < (switchValue - 50)) {
    switchValues[mux][muxChannel][1] = switchValue - 50;
    Serial.println(switchValue);
  }
}
