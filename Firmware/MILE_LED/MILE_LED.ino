// SPDX-License-Identifier: GPL-3.0-only
// Based on NeoPixel Ring simple sketch (c) 2013 Shae Erisson.
// Adapted for constant RGB illumination in the MILE fingertip sensor.

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Arduino digital-pin number, not the ATtiny85 package-pin number.
// Default for the pictured ATtiny85 board: P3 / PB3.
// Match this value to the signal-wire connection and selected board core.
const uint8_t LED_PIN = 3;

// Pixel indices start at the first LED connected to the signal-input end.
// Red, red, red, blue, blue, green, green, green, blue, blue.
// If only the first eight LEDs are physically present, they keep the same
// colors (RRRBBGGG); the final two blue positions have no attached LEDs.
// This assumes LEDs are omitted only from the end of the signal chain.
const char LED_PATTERN[] = "RRRBBGGGBB";
const uint16_t NUMPIXELS = sizeof(LED_PATTERN) - 1;

// Adjustable starting values, not recovered experimental calibration.
// Tune each channel with the assembled camera, exposure, and gel.
const uint8_t RED_LEVEL = 15;
const uint8_t GREEN_LEVEL = 15;
const uint8_t BLUE_LEVEL = 15;

// Retained from the supplied code; verify the actual strip format.
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Preserve the supplied Adafruit example's 16 MHz ATtiny85 setup.
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
  pixels.clear();
  for (uint16_t i = 0; i < NUMPIXELS; ++i) {
    switch (LED_PATTERN[i]) {
      case 'R': pixels.setPixelColor(i, RED_LEVEL, 0, 0); break;
      case 'G': pixels.setPixelColor(i, 0, GREEN_LEVEL, 0); break;
      case 'B': pixels.setPixelColor(i, 0, 0, BLUE_LEVEL); break;
    }
  }
  pixels.show();
}

void loop() {
  // Constant illumination: pixels retain the last transmitted colors.
}
