int static protothreadSwitch(struct pt* pt) {  // declares the protothread
  PT_BEGIN(pt);  // chooses which thread to use

  
  modifier = 0;  // sets modifier (ctrl, shift, alt, etc) to 0, used in keyboard report down the line
  for (numSwitch = 0; numSwitch < numberOfSwitches; numSwitch++) {
    uint8_t keycode[6] = {};  // The array size translates to how many keys that can be reported at the same time, The library only support 6 so its set to 6 here
    readSwitch(numSwitch);    // reads switch number numSwitch / position in for loop
    keycode[0] = keymaps[mux][muxChannel];  //sets keycode[0] to the keycode corresponding to the correct switch im reading, mux and muxChannel comes from the switchReader section in switchReader.h
    switchCalibration();      // calibrates max and min values of the switch map / analog value of each key
    actuationPoint = map(analogRead(5), potMin, potMax, 0, 100);  // maps the actuation point based on the position of the slider

    switchMap();  // maps the position of current key depending on the actuation point and min and max values for corresponding switch
    if (mappedSwitchValue > actuationPoint) {   // if switch is pressed, set isPressed[numSwitch] to true, else, set to false
      isPressed[numSwitch] = true;
    } else {
      isPressed[numSwitch] = false;
    }

    if (debug) {    // writes terminal stuff, not updated for quite a while and not really used
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

    // this section is a mess and i sincerely apoligize for everything
    
    if (isPressed[numSwitch]) {  // if current switch is pressed
      if (!hasKey[numSwitch]) {  // check if it doesnt previously have a key/ is previously pressed and not released since
        bluemicro_hid.keyboardReport(modifier, keycode);  // report to queue
        Serial.println("press");
        if (numSwitch == 3 && !caps){   // Toggle for caps solid light when toggled
          caps ^= true;
        }
        else if (numSwitch == 3){
          caps ^= true;
        }
        keysReleased = false;  // set keys released to false to indicate that at least one key is pressed
      }
      hasKey[numSwitch] = true;  // sets current key to pressed
    } else {
      hasKey[numSwitch] = false;  // sets current key to not pressed if that were to be the case
    }
  }

  if (std::none_of(std::begin(hasKey), std::end(hasKey), [](bool val) {  // checks if every argument in the hasKey array is false 
        return val;
      })) {
    if (!keysReleased) {  // checks if keys is not released
      bluemicro_hid.keyboardRelease();  // report release to queue
      keysReleased = true;
      Serial.println("Release");
    }
  }

  if (bluetoothOnly) {   // processes queues automatically depending on preffered or auto connection type
    bluemicro_hid.processQueues(CONNECTION_MODE_BLE_ONLY);
  }
  if (usbOnly) {
    bluemicro_hid.processQueues(CONNECTION_MODE_USB_ONLY);
  } else {
    bluemicro_hid.processQueues(CONNECTION_MODE_AUTO);
  }

  PT_END(pt);  // closes the protothread
}
