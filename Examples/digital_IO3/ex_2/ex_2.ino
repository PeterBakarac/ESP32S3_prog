#define Q7_PIN 15
#define CP_PIN 11
#define PL_PIN 16

byte read_shift_register(byte data_pin, byte clock_pin, byte load_pin) {
  byte incoming = 0;
  digitalWrite(load_pin, LOW);
  delay(5);
  digitalWrite(load_pin, HIGH);
  incoming = shiftIn(data_pin, clock_pin, LSBFIRST);
  return incoming;
} 

void setup() {
  Serial.begin(9600);
  pinMode(Q7_PIN, INPUT);
  pinMode(CP_PIN, OUTPUT);
  pinMode(PL_PIN, OUTPUT);
  digitalWrite(PL_PIN, HIGH);
}

void loop() {
  byte switches = read_shift_register(Q7_PIN, CP_PIN, PL_PIN);
  Serial.println(switches, BIN);
  Serial.println(switches);
  delay(1000);
}
