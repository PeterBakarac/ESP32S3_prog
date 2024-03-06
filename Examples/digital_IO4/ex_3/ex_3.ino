#include <FastLED.h>

#define LED_PIN     18
#define NUM_LEDS    12

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2813, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
  delay(20);
}

void loop() {
  for(int i = 0; i < NUM_LEDS; i++)
    {
      for(int j = 0; j < NUM_LEDS; j++)
      {
        if(j == i)
        {
          leds[j] = CRGB(0, 255, 0);
        }
        else
        {
          leds[j] = CRGB(0, 0, 255);
        }
      }
      FastLED.show();
      delay(100);
    }
}
