const uint8_t buzzer_pin = 48;
unsigned int buzzer_frequency = 9E3;
unsigned long buzzer_duration = 13E3;

void setup() {
  pinMode(buzzer_pin, OUTPUT);
  tone(buzzer_pin, buzzer_frequency, buzzer_duration);
}

void loop() {
}
