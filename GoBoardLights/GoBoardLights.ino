#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 81

#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
}

void loop() {
  // Turn the LED on, then pause
  for (int i = 0; i < NUM_LEDS; i += 2) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();

  delay(500);
  // Now turn the LED off, then pause
  for (int i = 0; i < NUM_LEDS; i += 2) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(500);
}
