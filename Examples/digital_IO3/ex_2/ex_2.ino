#define PL_PIN 16
#define CP_PIN 11
#define Q7_PIN 15

byte switches;

byte read_shift_register(byte load_pin, byte clock_pin, byte data_pin) {
  byte incoming = 0;
  digitalWrite(load_pin, LOW);
  delay(5);
  digitalWrite(load_pin, HIGH);
  incoming = shiftIn(data_pin, clock_pin, LSBFIRST);
  return incoming;
} 

void setup() {
  Serial.begin(9600);

  pinMode(PL_PIN, OUTPUT);
  pinMode(CP_PIN, OUTPUT);
  pinMode(Q7_PIN, INPUT);
  
  digitalWrite(PL_PIN, HIGH);
}

void loop() {
  switches = read_shift_register(Q7_PIN, CP_PIN, PL_PIN);
  Serial.println(switches, BIN);
  Serial.println(switches);
  delay(1000);
}
