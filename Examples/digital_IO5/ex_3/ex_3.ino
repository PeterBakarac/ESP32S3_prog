#include <FastLED.h>

#define LED_PIN     48
#define NUM_LEDS    1

CRGB leds[NUM_LEDS];

String morse_code[][2] = {
  {"A", ".-"},
  {"H", "...."},
  {"O", "---"},
  {"J", ".---"},
  {" ", " "},
  {"S", "..."},
  {"V", "...-"},
  {"E", "."},
  {"T", "-"}};
uint8_t time_unit = 200;
uint8_t code = 0;
uint8_t msg_size;

void led_blink(int duration)
{
  leds[0] = CRGB(0, 255, 0);
  FastLED.show();
  delay(duration);
  leds[0] = CRGB(0, 0, 0);
  FastLED.show();
}

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<SK6812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  msg_size = sizeof(morse_code)/sizeof(morse_code[0]);
  for(int i = 0; i < msg_size; i++)
  {
    code = morse_code[i][1].length();
    for(int j = 0; j < code; j++)
    {
      switch(morse_code[i][1][j]){
        case '.': 
          Serial.print('.');
          led_blink(time_unit);
          break;
        case '-': 
          Serial.print('-');
          led_blink(time_unit*3);
          break;
        case ' ': 
          Serial.print(' ');
          delay(time_unit*4);
          break;
      }
      delay(time_unit);
    }
    Serial.print(' ');
    delay(time_unit*3);
  }
  Serial.println();
  delay(5000);
}
