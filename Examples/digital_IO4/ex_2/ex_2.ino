#include <FastLED.h>

#define LED_PIN     18
#define NUM_LEDS    12

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2813, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {

  for(int i = 0; i <= 255; i++)
  {
    for(int j = 0; j < NUM_LEDS; j++)
    {
      leds[j] = CRGB(0, i, 0);
    }
    FastLED.show();
    delay(20);
  }
}
