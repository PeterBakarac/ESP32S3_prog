uint8_t random_number;

void setup() {
  Serial.begin(9600);
}

void loop() {
  random_number = random(0, 255);
  Serial.println(random_number);
  delay(1000);
}
