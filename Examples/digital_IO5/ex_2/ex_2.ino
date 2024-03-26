const uint8_t buzzer_pin = 48;
unsigned int buzzer_freq = 5E3;

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
uint8_t time_unit = 60;
uint8_t code = 0;
uint8_t msg_size;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer_pin, OUTPUT);
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
          tone(buzzer_pin, buzzer_freq, time_unit);
          break;
        case '-': 
          Serial.print('-');
          tone(buzzer_pin, buzzer_freq, time_unit*3);
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
