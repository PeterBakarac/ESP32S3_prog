uint8_t LED_pins[3] = {12, 13, 14};
uint8_t states[4][3] = {{1, 0, 0}, {1, 1, 0}, {0, 0, 1}, {0, 1, 0}};
uint8_t stage = 0;
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
uint16_t interval = 5000;

void setup() {
  for(int i = 0; i < 3; i++){
    pinMode(LED_pins[i], OUTPUT);
  }
}

void loop() {
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval){
    if(stage == 3){
      stage = 0;
    }
    else {
      stage++;
    }
    previousMillis = currentMillis;
  }
  for(int i = 0; i < 3; i++){
    digitalWrite(LED_pins[i], states[stage][i]);
  }
}
