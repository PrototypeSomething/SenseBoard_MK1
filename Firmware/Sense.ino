#include <protothreads.h>  // includes some libraries
//#include <BLE52_Mouse_and_Keyboard.h>
#include <bluemicro_hid.h>
//#include <Microsoft_HidForWindows.h>
#include <Arduino.h>

int sliderFunction = 1;               //  Initial function of the slider 1 = volume, 2 = brightness, 3 = actuation
bool debug = false;                   //  Enables Serial output
bool rgb = false;                     //  Enables RGB
int capsColor[3] = {255, 255, 0};     //  Color Caps lock highlights when caps is activated
const int numberOfSwitches = 44;      //  Total number of switches to read, starting from switch 0 (left Windows)

static struct pt pt1, pt2, pt3, pt4;  // declares "threads" from the protothread library, which sort of emulates threads to make "multitasking" manageable on single core platforms like the Nordic-nRF52840 (1C 1T 64MHz)

// includes neccesary header files is correct order
#include "Values.h"
#include "Keymaps.h"
#include "LightingEffects.h"
#include "Slider.h"
#include "ledThread.h"
#include "switchThread.h"
#include "extrasThread.h"

void setup() {  // sets up neccecary values such as inputs and declares neccecary values for libraries
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  PT_INIT(&pt1);  // initialises the virtual threads
  PT_INIT(&pt2);
  PT_INIT(&pt3);
  PT_INIT(&pt4);
  startRGB();    // runs a quick method that sets up neopixel with necessary variables
  startSlider(sliderFunction);  // declares the use case of the slider/linear potentiometer, not really used yet
  bluemicro_hid.setBLEModel("SenseBoard_MK0.7");  // sets name to publish on bluetooth
  bluemicro_hid.setHIDMessageDelay(10);  // delay in HID polling, can be lowered but 10 is a stable middleground in some worst case scenarios for example in a crowded bluetooth space
  bluemicro_hid.begin();  // calls a function to start the library and make the device visible on bluetooth signals as well as connect to USB device if connected
}

void loop() {
  //  Protothreads
  protothreadSwitch(&pt1); // calls the switchThread first
  protothreadExtras(&pt2);  // then the extras thread
  protothreadSlider(&pt3);  // then Slider
  protothreadRGB(&pt4);  // and RGB, This ir ordered in priority, so basic keyboard functions go first, then extras (currently has no functions but some nice calculations and connectivity features are in sight), then the slider, and finally RGB as its least important to make the keyboard functional
}
