#include <FastLED.h>
#include <cmath>

#define LED_PIN     18
#define NUM_LEDS    12

float a = 255;
float c = 500; 

int intensity;
byte inds[2][6] = {
                    {3, 2, 1, 0, 11, 10},
                    {4, 5, 6, 7, 8, 9}
                  };

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2813, LED_PIN, GRB>(leds, NUM_LEDS);
  delay(20);
}

void loop() {
  for(int b = -2000; b < 7000; b=b+2)
  {
    for(int i = 0; i < (NUM_LEDS)/2; i++)
    { 
      intensity = a*exp(-pow((i*1000 - b),2)/(2*c*c));
      leds[inds[1][i]] = CRGB(0, intensity, 0);
      leds[inds[0][i]] = CRGB(0, intensity, 0);
    }
    FastLED.show();
    delay(1);
  }
}
