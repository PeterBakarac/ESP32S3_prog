uint8_t LED_pins[3] = {12, 13, 14};
uint8_t states[4][3] = {{1, 0, 0}, {1, 1, 0}, {0, 0, 1}, {0, 1, 0}};
uint8_t stage = 0;
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
uint16_t interval = 2000;
unsigned long but_cur_Millis = 0;
unsigned long but_prev_Millis = 0;
uint16_t but_interval = 3000;
int button_pin = 3;
bool button_state;
bool toggled = false;
bool flag = true;

void setup() {
  for(int i = 0; i < 3; i++){
    pinMode(LED_pins[i], OUTPUT);
  }
  pinMode(button_pin, INPUT_PULLDOWN);
}

void loop() {
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval){
    if(flag){
      if(stage == 3){
        stage = 0;
      }
      else {
        stage++;
      }
      for(int i = 0; i < 3; i++){
        digitalWrite(LED_pins[i], states[stage][i]);
      }
    }
    else {
      digitalWrite(LED_pins[1], !digitalRead(LED_pins[1]));
    }
    previousMillis = currentMillis;
  }
  
  button_state = digitalRead(button_pin);
  if(button_state)
  {
    if(!toggled)
    {
      but_prev_Millis = millis();
    }
    else {
      but_cur_Millis = millis();
      if(but_cur_Millis - but_prev_Millis >= but_interval){
        flag = !flag;
        for(int i = 0; i < 3; i++){
          digitalWrite(LED_pins[i], false);
        }
        but_prev_Millis = but_cur_Millis;
      }
    }
    toggled = true;
  }
  else
  {
    toggled = false;
  }  
}
