const uint8_t BUZZER_PIN = 48;
unsigned int BUZZER_FREQUENCY = 14E3;
unsigned long BUZZER_DURATION = 5E3;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  tone(BUZZER_PIN, BUZZER_FREQUENCY, BUZZER_DURATION);
}

void loop() {
}
