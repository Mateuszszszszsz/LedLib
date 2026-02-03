#pragma once
#include <Adafruit_NeoPixel.h>
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(200, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

// 32-bit color value. Most significant byte is white (for
//                   RGBW pixels) or ignored (for RGB pixels), next is red,
//                   then green, and least significant byte is blue. If all
//                   arguments are unspecified, this will be 0 (off).

#define RED	    0xff0000
#define GREEN	0x00ff00
#define BLUE	0x0000ff

#define YELLOW	0xffff00
#define MAGENTA	0xff00ff
#define CYAN	0x00ffff

#define BLACK	0x000000
#define WHITE	0xffffff

