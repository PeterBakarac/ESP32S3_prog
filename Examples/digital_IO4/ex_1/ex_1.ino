#include <FastLED.h>

#define LED_PIN     48
#define NUM_LEDS    1

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<SK6812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  for(int i = 0; i<=255; i++)
  {
    leds[0] = CRGB(i, 0, 0);
    FastLED.show();
    delay(20);
  }
  
  for(int i = 255; i > 0; i--)
  {
    leds[0] = CRGB(i, 0, 255-i);
    FastLED.show();
    delay(20);
  }
}
