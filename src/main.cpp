#include <Adafruit_NeoPixel.h>
#include "StripConfig.h"
#include "Rainbow.h"
#include "Wheel.h"
#include "ColorWipe.h"
#include "TheaterChase.h"
#include "Arduino.h"

#ifdef __AVR__
#include <avr/power.h>
#endif

#define BUTTON 4
const unsigned long DEBOUNCE_DELAY_MS = 50;

bool lastButtonState = HIGH;
bool stableButtonState = HIGH;
unsigned long lastDebounceTime = 0;

void toggleColor(Adafruit_NeoPixel& strip, uint32_t color1, uint32_t color2) {
  static bool isColor1 = true;

  if (isColor1) {
    colorWipe(strip, color1);
  } else {
    colorWipe(strip, color2);
  }

  isColor1 = !isColor1;
} 

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined(__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  strip.begin();
  strip.setBrightness(20);
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);

  colorWipe(strip, WHITE);
}

void loop() {
  int reading = digitalRead(BUTTON);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
    lastButtonState = reading;
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY_MS) {
    if (reading != stableButtonState) {
      stableButtonState = reading;

      if (stableButtonState == LOW) {
        Serial.println("Button pressed");
        toggleColor(strip, RED, WHITE);
      } else {
        Serial.println("Button released");
      }
    }
  }

  digitalWrite(LED_BUILTIN, stableButtonState == LOW ? HIGH : LOW);
}


