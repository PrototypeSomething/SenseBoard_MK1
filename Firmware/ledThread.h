int static protothreadRGB(struct pt* pt) {
  PT_BEGIN(pt);

  if (debug) {
    Serial.println("init pt RGB");
  }

  strip.setBrightness(map(analogRead(5), potMin, potMax, 0, 100));
  PT_WAIT_UNTIL(pt, numSwitch = numberOfSwitches);
  if (debug) {
    Serial.println("numSwitch = numberOfSwitches");
  }

  if (rgb) {
    if (rainbowCycle) {

      if (rgbCycle > 256) {
        rgbCycle = 0;
      }
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + rgbCycle) & 255));
      }

      rgbCycle++;
    }
  }

  if (caps) {
    strip.setPixelColor(55, capsColor[0], capsColor[1], capsColor[2]);
  } else if (!rgb) {
    strip.setPixelColor(55, 0, 0, 0);
  }

  strip.show();

  PT_END(pt);
}