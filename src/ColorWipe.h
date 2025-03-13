#include <Adafruit_NeoPixel.h>

// Fill the dots one after the other with a color
//change of color of whole strip

void colorWipe(Adafruit_NeoPixel& strip, uint32_t c) 
{
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
  }
}

void colorWipe(Adafruit_NeoPixel& strip, uint32_t c, uint8_t wait) 
{
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}