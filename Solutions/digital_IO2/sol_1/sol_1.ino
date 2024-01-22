int red_pin = 12;
int yellow_pin = 13;
int green_pin = 14;
int button_pin = 3;
bool button_state;
bool toggled = false;
int state = 1;

void setup() {
  pinMode(red_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLDOWN);
}

void loop() {
  if(state == 1)
  {
    digitalWrite(red_pin, true);
    digitalWrite(yellow_pin, false);
    digitalWrite(green_pin, false);
  }
  else if(state == 2)
  {
    digitalWrite(red_pin, false);
    digitalWrite(yellow_pin, true);
    digitalWrite(green_pin, false);
  }
  else if(state == 3)
  {
    digitalWrite(red_pin, false);
    digitalWrite(yellow_pin, false);
    digitalWrite(green_pin, true);
  }
  button_state = digitalRead(button_pin);
  if(button_state)
  {
    if(!toggled)
    {
      if(state < 3)
        state = state + 1;
      else
        state = 1;
    }
    toggled = true;
  }
  else
  {
    toggled = false;
  }
}
