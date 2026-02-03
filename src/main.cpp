#include <Adafruit_NeoPixel.h>
#include "StripConfig.h"
#include "Rainbow.h"
#include "Wheel.h"
#include "ColorWipe.h"
#include "TheaterChase.h"
#include "Arduino.h"

uint32_t adcToHexColor(int adcValue, int maxAdcValue = 1023);


#ifdef __AVR__
#include <avr/power.h>
#endif

#define BUTTON_UP    3
#define BUTTON_DOWN  4

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  pinMode(A0, INPUT); ///pin A0 as adc input for color choice
  pinMode(BUTTON_UP, INPUT_PULLUP); 
  pinMode(BUTTON_DOWN, INPUT_PULLUP);

  strip.begin();
  strip.setBrightness(40);
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
  
}

void loop() 
{
  uint8_t currentBrightness = 40;  // Starting brightness
  
  while(1)
  { 

     // Read ADC value for color selection
    int adcValue = analogRead(A0);
    uint32_t selectedColor = adcToHexColor(adcValue);
    
    // Check BUTTON_UP for brightness increase
    if (digitalRead(BUTTON_UP) == LOW) {
      if (currentBrightness < 255) {
        currentBrightness += 10;
        strip.setBrightness(currentBrightness);
        strip.show();
      }
      delay(200);  // Debounce delay
    }
    
    // Check BUTTON_DOWN for brightness decrease
    if (digitalRead(BUTTON_DOWN) == LOW) {
      if (currentBrightness > 0) {
        currentBrightness -= 10;
        strip.setBrightness(currentBrightness);
        strip.show();
      }
      delay(200);  // Debounce delay
    }
    
    
if (adcValue<100)
    rainbow(strip,20); //rainbow if adc low
else
    colorWipe(strip, selectedColor, 10);// inf higher adc the selected color is wiped
    delay(50);
  }
}



void function1(Adafruit_NeoPixel& strip, uint32_t& color, uint8_t wait = 10) //strobo przelatujące binarnie po kolorach dobrać szybkość zmian (wait jako prescaler albo zmieniać wartość incrementu ) 
{
  colorWipe(strip, color, wait);
  strip.show();
  color+=10000;
}

// Convert ADC value to hex color format (0xFFFFFF)
// Input: ADC value (0-1023 for 10-bit Arduino, or 0-4095 for 12-bit)
// Output: uint32_t hex color (0xRRGGBB format)
uint32_t adcToHexColor(int adcValue, int maxAdcValue = (int)1023) {
  // Map ADC value to 0-255 range for Wheel function
  byte wheelValue = map(adcValue, 0, maxAdcValue, 0, 255);
  
  // Use Wheel to get RGB values, then convert to hex
  uint32_t color = Wheel(wheelValue);
  
  return color;
}