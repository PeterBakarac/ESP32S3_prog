// Define the pins
#define LOAD_PIN 16   // Parallel load pin (PL, active low)
#define CLOCK_PIN 11  // Clock pin (CP)
#define DATA_PIN 15   // Serial data in pin (QH')
int positionV2 = 0;

void readShiftRegisters() {
  uint8_t inputData = 0;
  byte value;
  bool switches[8];
  // Parallel load to grab the states of the inputs.
  digitalWrite(LOAD_PIN, LOW);
  delayMicroseconds(5);  // Short delay for stability
  digitalWrite(LOAD_PIN, HIGH);

  for(int i = 7; i > 0; i--) {
    switches[i] = (digitalRead(DATA_PIN));
    digitalWrite(CLOCK_PIN, HIGH);
    delayMicroseconds(5);  
    digitalWrite(CLOCK_PIN, LOW);
  }

  for(int i = 0; i < 8; i++) {
    Serial.print(switches[i]);
  }
  Serial.println(" ");
}


void setup() {
  Serial.begin(9600);
  
  pinMode(LOAD_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, INPUT);
  
  digitalWrite(LOAD_PIN, HIGH);
  digitalWrite(CLOCK_PIN, LOW);
}

void loop() {
  int8_t data = readShiftRegisters();
  Serial.println(" ");
  Serial.println("----");
  Serial.println("nejaky retazec " + String(data));

  delay(2000);
  
}
