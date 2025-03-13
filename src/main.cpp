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

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.setBrightness(40);
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
  
}

void loop() 
{
int i = 0;
  while(1)
  { 

 // rainbow(strip,30);
  //rainbowheart(strip, 30,0);
  //rainbowCycle(strip,30);
  //rainbowheart(strip, 30,1);
  int aDel = 1;
  aquatronic(strip,aDel,8);
  aquatronic(strip,aDel,6);
  rainbowheart(strip,aDel,0);
  aquatronic(strip,aDel,0);
  aquatronic(strip,aDel,1);
  aquatronic(strip,aDel,2);
  aquatronic(strip,aDel,0);
  aquatronic(strip,aDel,3);
  aquatronic(strip,aDel,4);
  aquatronic(strip,aDel,5);
  aquatronic(strip,aDel,6);
  aquatronic(strip,aDel,7);
  aquatronic(strip,aDel,8);
  rainbowheart(strip,2*aDel,0);    
//  theaterChase(strip,WHITE,100);
  
  i++;
  i= i%256;
  delay(100);
  //Serial.println(i);
  }
}



// // Wczytywanie danej z klawiatury po UART
// if(Serial.available()>0)
// {
// int width = Serial.parseInt();
// Serial.print("otrzymalem:");
// Serial.println(width);
// strip.setBrightness(width);
// }

void function1(Adafruit_NeoPixel& strip, uint32_t& color, uint8_t wait = 10) //strobo przelatujące binarnie po kolorach dobrać szybkość zmian (wait jako prescaler albo zmieniać wartość incrementu ) 
{
  colorWipe(strip, color, wait);
  strip.show();
  color+=10000;
}
