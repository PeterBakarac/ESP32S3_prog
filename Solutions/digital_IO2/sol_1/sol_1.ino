uint8_t LED_pins[3] = {12, 13, 14};
uint8_t states[4][3] = {{1, 0, 0}, {1, 1, 0}, {0, 0, 1}, {0, 1, 0}};
uint8_t stage = 0;

int button_pin = 3;
bool button_state;
bool toggled = false;

void setup() {
  for(int i = 0; i < 3; i++){
    pinMode(LED_pins[i], OUTPUT);
  }
  pinMode(button_pin, INPUT_PULLDOWN);
}

void loop() {
  button_state = digitalRead(button_pin);
  if(button_state)
  {
    if(!toggled)
    {
      if(stage == 3)
        stage = 0;
      else
        stage++;
    }
    toggled = true;
  }
  else
  {
    toggled = false;
  }

  for(int i = 0; i < 3; i++){
    digitalWrite(LED_pins[i], states[stage][i]);
  }
}
