int static protothreadSwitch(struct pt* pt) {
  PT_BEGIN(pt);

  modifier = 0;
  for (numSwitch = 0; numSwitch < numberOfSwitches; numSwitch++) {
    uint8_t keycode[6] = {};  // Change the array size to match the number of keys per report
    readSwitch(numSwitch);
    keycode[0] = keymaps[mux][muxChannel];
    //switchCalibration();
    actuationPoint = map(analogRead(5), potMin, potMax, 0, 100);

    switchMap();
    if (mappedSwitchValue > actuationPoint) {
      isPressed[numSwitch] = true;
    } else {
      isPressed[numSwitch] = false;
    }

    if (debug) {
      Serial.print(mappedSwitchValue);
      Serial.print("      ");
      Serial.print(actuationPoint);
      Serial.print("      ");
      Serial.print(isPressed[numSwitch]);
      Serial.print(switchValues[mux][muxChannel][1]);
      Serial.print("      ");
      Serial.print(switchValues[mux][muxChannel][2]);
      Serial.println();
      Serial.println();
      Serial.println();
      Serial.println();
      Serial.println();
    }

    if (isPressed[numSwitch]) {
      if (!hasKey[numSwitch]) {
        bluemicro_hid.keyboardReport(modifier, keycode);
        Serial.println("press");
        if (numSwitch == 3 && !caps){
          caps ^= true;
        }
        else if (numSwitch == 3){
          caps ^= true;
        }
        keysReleased = false;
      }
      hasKey[numSwitch] = true;
    } else {
      hasKey[numSwitch] = false;
    }
  }

  if (std::none_of(std::begin(hasKey), std::end(hasKey), [](bool val) {
        return val;
      })) {
    if (!keysReleased) {
      bluemicro_hid.keyboardRelease();
      keysReleased = true;
      Serial.println("Release");
    }
  }

  if (bluetoothOnly) {
    bluemicro_hid.processQueues(CONNECTION_MODE_BLE_ONLY);
  }
  if (usbOnly) {
    bluemicro_hid.processQueues(CONNECTION_MODE_USB_ONLY);
  } else {
    bluemicro_hid.processQueues(CONNECTION_MODE_AUTO);
  }

  PT_END(pt);
}
