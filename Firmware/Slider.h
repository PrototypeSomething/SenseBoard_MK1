void startSlider(int value){
  if (value == 1){
    sliderVolume = true;
    sliderBrightness = false;
    sliderActuation = false;
  }
  else if (value == 2){
    sliderVolume = false;
    sliderBrightness = true;
    sliderActuation = false;
  }
  else if (value == 3){
    sliderVolume = false;
    sliderBrightness = false;
    sliderActuation = true;
  }
}


int static protothreadSlider(struct pt* pt) {
  PT_BEGIN(pt);

  if (mux = 3 && muxChannel == 6){
    
  }

  PT_END(pt);
}
