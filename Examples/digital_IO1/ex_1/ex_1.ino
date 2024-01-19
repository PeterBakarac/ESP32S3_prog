int led_pin = 12;

void setup() {
  pinMode(led_pin, OUTPUT);
}

void loop() {
  digitalWrite(led_pin, true);
  delay(500);
  digitalWrite(led_pin, false);
  delay(500);
}
