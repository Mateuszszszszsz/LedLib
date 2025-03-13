#pragma once 
#include "Wheel.h"

int layerHeart[][64] = 
{
{//mode0
0,0,0,0,0,0,0,0,
0,1,1,0,0,1,1,0,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
0,1,1,1,1,1,1,0,
0,0,1,1,1,1,0,0,
0,0,0,1,1,0,0,0
},
{ //mode1
0,0,1,1,0,0,0,0,
0,1,1,1,1,0,0,0,
0,1,1,1,1,0,0,0,
0,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,1,
0,1,1,1,1,1,1,1,
0,1,1,1,1,1,1,0,
0,0,0,0,0,0,0,0
}

};

int letters[][64]=
{
  {//Letter A
0,0,0,0,0,0,0,0,
0,0,1,1,1,1,0,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,1,1,1,1,1,1,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,0,0,0,0,0,0,0
},
{ //Letter Q
0,0,0,0,0,0,0,0,
0,0,1,1,1,1,0,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,1,0,0,1,0,1,0,
0,1,0,0,0,1,1,0,
0,0,1,1,1,1,1,0,
0,0,0,0,0,0,0,1
},
{ //Letter U
0,0,0,0,0,0,0,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,0,1,1,1,1,0,0,
0,0,0,0,0,0,0,0
},
{ //Letter T
0,0,0,0,0,0,0,0,
0,1,1,1,1,1,1,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,0,0,0,0,0
},
{ //Letter R
0,0,0,0,0,0,0,0,
0,1,1,1,1,1,0,0,
0,1,0,0,0,0,1,0,
0,1,1,0,0,0,1,0,
0,1,0,1,1,1,0,0,
0,1,0,0,1,0,0,0,
0,1,0,0,0,1,0,0,
0,0,0,0,0,0,0,0
},
{ //Letter O
0,0,0,0,0,0,0,0,
0,0,1,1,1,1,0,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,1,0,0,0,0,1,0,
0,0,1,1,1,1,0,0,
0,0,0,0,0,0,0,0
},
{ //Letter N
0,0,0,0,0,0,0,0,
0,1,0,0,0,0,1,0,
0,1,1,0,0,0,1,0,
0,1,0,1,0,0,1,0,
0,1,0,0,1,0,1,0,
0,1,0,0,0,1,1,0,
0,1,0,0,0,0,1,0,
0,0,0,0,0,0,0,0
},
{ //Letter I
0,0,0,0,0,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,0,0,0,0,0
},
{ //Letter K
0,0,0,0,0,0,0,0,
0,0,1,0,0,1,0,0,
0,0,1,0,1,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,0,1,0,0,0,
0,0,1,0,0,1,0,0,
0,0,1,0,0,0,1,0,
0,0,0,0,0,0,0,0
}
};



void rainbow(Adafruit_NeoPixel& strip, uint16_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
      for (uint16_t i=0; i < strip.numPixels(); i++) {
  strip.setPixelColor(i, 0);        //turn every third pixel off
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(Adafruit_NeoPixel& strip, uint16_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
    for (uint16_t i=0; i < strip.numPixels(); i++) {
  strip.setPixelColor(i, 0);        //turn every third pixel off
  }
}

void theaterChaseRainbow(Adafruit_NeoPixel& strip, uint16_t wait) //Theatre-style crawling lights with rainbow effect
{
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

void rainbowheart(Adafruit_NeoPixel& strip, uint16_t wait,int mode) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      if(layerHeart[mode][i])
        strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
        for (uint16_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0);        //turn every third pixel off
      }
}

void aquatronic(Adafruit_NeoPixel& strip, uint16_t wait,int mode) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      if(letters[mode][i])
        strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
        for (uint16_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0);        //turn every third pixel off
      }
}


