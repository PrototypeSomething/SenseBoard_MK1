int static protothreadRGB(struct pt* pt) { // declares protothread
  PT_BEGIN(pt);  // chooses thread to use, from above statement, declared when thread is called in sense.ino

  if (debug) {  // prints to serial if debug is true
    Serial.println("init pt RGB");
  }

  strip.setBrightness(map(analogRead(5), potMin, potMax, 0, 100)); // sets brightness of LED's depending on slider/linear potentiometer position
  PT_WAIT_UNTIL(pt, numSwitch = numberOfSwitches);  // waits until the final switch is read in another thread
  if (debug) {  // print if debug
    Serial.println("numSwitch = numberOfSwitches");
  }

  if (rgb) {
    if (rainbowCycle) {  // declared in values.h

      if (rgbCycle > 256) {                                                                  //}
        rgbCycle = 0;                                                                        //}
      }                                                                                      //}  Rainbow cycle rgb effect
      for (int i = 0; i < strip.numPixels(); i++) {                                          //}
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + rgbCycle) & 255));     //}  sets led color to correct hue depending on the position of the "wheel" function defined in lightingEffects.h, basically all it does is returning a value from 1-255 depending on input variables 
      }                                                                                      //}

      rgbCycle++;
    }
  }

  if (caps) {  // if caps is true/ if caps is toggled on
    strip.setPixelColor(55, capsColor[0], capsColor[1], capsColor[2]);  // sets colour depending on user input in sense.ino
  } else if (!rgb) {  // doesn't toggle on led when rgb is off
    strip.setPixelColor(55, 0, 0, 0);
  }

  strip.show();  // updates neopixel lights with new parameters

  PT_END(pt);  // closes the protothread
}
