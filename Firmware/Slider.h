void startSlider(int value){  // this is currently not doing anything else than setting true or false to some variables, its planned later to use these variables to specify the function of the slider according to their name
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

  PT_END(pt);
}
