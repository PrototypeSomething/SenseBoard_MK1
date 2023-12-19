#include "Arduino.h"
bool bluetoothOnly = false;
bool usbOnly = false;
int numSwitch;
int keyRecord;
int switchValue;
int mappedSwitchValue;
int actuationPoint;
int potMin = 1 + 10;
int potMax = 948 - 10;
int modifier;
bool keyPressedPreviously;
bool isPressed[numberOfSwitches];
bool hasKey[numberOfSwitches];
bool keysReleased;

// Extras
bool Fn;
#define fnKey = 

// Slider
#define layer = getLayer();
bool sliderVolume;
bool sliderBrightness;
bool sliderActuation;

// RGB vars
bool rainbowCycle = true;
int rgbCycle = 0;
int rgbPos = 0;
bool caps;
bool capsPressed;