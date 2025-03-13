
#pragma once
#include <Adafruit_NeoPixel.h>

uint32_t Wheel(byte WheelPos) // Input a value 0 to 255 to get a color value.
                                                        // The colours are a transition r - g - b - back to r.
// iterating input in loob form 0-255 generates colors:
//RED - Yellow - GREEN - CYAN -  BLUE - MAGENTA - PINK - RED
                                                  
{
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}