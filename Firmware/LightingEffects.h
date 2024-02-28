#include <Adafruit_NeoPixel.h> // includes NeoPixel
//#include "LEDsetup.h"

#define numLED 111
#define RGBpin 10


int ledArray[numberOfMuxes][muxChannels] = {  // sets up array of all LEDS corresponding to each switch on the multiplexer and position
{79, 81, 56, 55, 27, 26, 0, 1, 25, 28, 54, 57, 79, 58, 53, 29},
{24, 2, 3, 23, 30, 52, 59, 60, 51, 31, 22, 4, 5, 21, 32, 50},
{77, 61, 62, 49, 33, 20, 6, 7, 19, 34, 48, 63, 47, 35, 18, 8},
{9, 17, 36, 46, 66, 65, 75, 74, 45, 37, 16, 10, 11, 15, 38, 44},
{42, 66, 73, 72, 71, 70, 67, 68, 39, 14, 12, 13, 40, 42, 41, 69}
};

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLED, RGBpin, NEO_GRB + NEO_KHZ800); // initialises parameters

int brightness = map(analogRead(5), potMin, potMax, 0, 255);  // makes the brightness of the LED's correspond to the position of the slider

void startRGB() {  // initialises the library, clears alls LED's and updates them with new info
  strip.begin();
  strip.clear();
  strip.show();
}

void clearRGB() {  // function to clear RGB, planned to use somewhere but i dont think i do a at the moment
  strip.clear();
  strip.show();
}

uint32_t Wheel(byte WheelPos) {  // function to return a rainbow "wheel" of colors depending on how many LED's there are
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void rainbowCycleNeopixel(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 1; j++) {  // 5 cycles of all colors on wheel

    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
