I apologise for this absolute mess of a document..

#include <BLE52_Mouse_and_Keyboard.h>
//#include <bluemicro_hid.h>
#include <Microsoft_HidForWindows.h>
#include <Arduino.h>
#include "Values.h"

bool debug = false;  //enables Serial output
bool rgb = false;    //enables RGB

#include "LightingEffects.h"
#include "Keymaps.h"
#include "Slider.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  startRGB();
  /*bluemicro_hid.setBLEModel("SenseBoard_MK1");
  bluemicro_hid.setHIDMessageDelay(10);
  bluemicro_hid.begin();*/
  Keyboard.begin();
  if (debug) {
    Serial.begin(115200);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (rgb) {
    rainbowCycle(20);
  }

  anyKeyPressed = false;
  modifier = 0;

  for (int i = 0; i < 22; i++) {
    uint8_t keycode[80] = {};
    readSwitch(i);
    keycode[i] = keymaps[mux][muxChannel];
    actuationPoint = map(analogRead(5), potMin, potMax, 0, 100);
    //calibration(mux, muxChannel, switchValue);      FEL!

    switchMap();
    if (mappedSwitchValue > actuationPoint) {
      isPressed[i] = true;
    } else {
      isPressed[i] = false;
    }
    if (debug) {
      Serial.print(mappedSwitchValue);
      Serial.print("      ");
      Serial.print(actuationPoint);
      Serial.print("      ");
      Serial.print(isPressed[i]);
      Serial.print(switchValues[mux][muxChannel][1]);
      Serial.print("      ");
      Serial.print(switchValues[mux][muxChannel][2]);
      Serial.println();
      Serial.println();
      Serial.println();
      Serial.println();
      Serial.println();
    }

    if (isPressed[i]) {
      if (has_key[i] == false) {
        Keyboard.press(keymaps[mux][muxChannel]);
        //bluemicro_hid.keyboardReport(modifier, keycode);
        //bluemicro_hid.keyboardPress(keymaps[mux][muxChannel]);
      }
      anyKeyPressed = true;
      keyPressedPreviously = true;
      has_key[i] = true;
    }

    if (/*!anyKeyPressed && keyPressedPreviously*/ has_key[i] && !isPressed[i]) {
      Keyboard.release(keymaps[mux][muxChannel]);
      has_key[i] = false;
      //keyPressedPreviously = false;
    }

    /*if(isPressed[i]) {
      bluemicro_hid.keyboardReport(modifier, keycode);
      has_key[i] = true;
    }
    else{
      if(has_key[i] == true){
        bluemicro_hid.keyboardRelease();
      }
      has_key[i] = false;
    }*/
  }

  if (!anyKeyPressed && keyPressedPreviously) {
    //bluemicro_hid.keyboardRelease();
    Serial.println("pressed");
    keyPressedPreviously = false;
  }

  /*if (bluetoothOnly) {
    bluemicro_hid.processQueues(CONNECTION_MODE_BLE_ONLY);  //THERE HAS TO BE SOMETHING THAT JUST QUEUES 6 THINGS
  }
  if (usbOnly) {
    bluemicro_hid.processQueues(CONNECTION_MODE_USB_ONLY);
  } else {
    bluemicro_hid.processQueues(CONNECTION_MODE_AUTO);
  }*/
}
