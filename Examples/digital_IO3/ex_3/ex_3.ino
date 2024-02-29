  #define PL_PIN 16
  #define CP_PIN 11
  #define Q7_PIN 15

  bool switch_states[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  void setup() {
    Serial.begin(9600);
    
    pinMode(PL_PIN, OUTPUT);
    pinMode(CP_PIN, OUTPUT);
    pinMode(Q7_PIN, INPUT);
    
    digitalWrite(PL_PIN, HIGH);
  }

  void loop() {
    digitalWrite(PL_PIN, LOW);
    delay(5);
    digitalWrite(PL_PIN, HIGH);
    
    for (int i = 7; i >= 0 ; i--) {
      switch_states[i] = digitalRead(Q7_PIN);
      Serial.print(switch_states[i]);
      digitalWrite(CP_PIN, HIGH);
      delayMicroseconds(5);  
      digitalWrite(CP_PIN, LOW);
    }
    
    Serial.println();
    Serial.println("-----------");
    delay(1000);
  }
