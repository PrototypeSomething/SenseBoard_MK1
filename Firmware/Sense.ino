#include <protothreads.h>
//#include <BLE52_Mouse_and_Keyboard.h>
#include <bluemicro_hid.h>
//#include <Microsoft_HidForWindows.h>
#include <Arduino.h>

int sliderFunction = 1;               //  Initial function of the slider 1 = volume, 2 = brightness, 3 = actuation
bool debug = false;                   //  Enables Serial output
bool rgb = false;                     //  Enables RGB
int capsColor[3] = {255, 255, 0};     //  Color Caps lock highlights when caps is activated
const int numberOfSwitches = 44;      //  Total number of switches to read, starting from switch 0 (left Windows)

static struct pt pt1, pt2, pt3, pt4;

#include "Values.h"
#include "Keymaps.h"
#include "LightingEffects.h"
#include "Slider.h"
#include "ledThread.h"
#include "switchThread.h"
#include "extrasThread.h"

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  PT_INIT(&pt1);
  PT_INIT(&pt2);
  startRGB();
  startSlider(sliderFunction);
  bluemicro_hid.setBLEModel("SenseBoard_MK0.7");
  bluemicro_hid.setHIDMessageDelay(10);
  bluemicro_hid.begin();
  // Keyboard.begin();
  // if (debug) {
  //   Serial.begin(115200);
  //   delay(5000);
  //   Serial.println("Started Serial");
  // }
}

void loop() {
  //  Protothreads, ILY Dunkels
  protothreadSwitch(&pt1);
  protothreadExtras(&pt2);
  protothreadSlider(&pt3);
  protothreadRGB(&pt4);
}