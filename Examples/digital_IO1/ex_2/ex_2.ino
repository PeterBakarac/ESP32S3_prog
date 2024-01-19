int led_pin = 12;
int button_pin = 3;
bool button_state;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLDOWN);
}

void loop() {
  button_state = digitalRead(button_pin);
  if (button_state) {
    digitalWrite(led_pin, true);
  } else {
    digitalWrite(led_pin, false);
  }
  delay(2);
}
