bool temp_bit = 0;
byte my_byte = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 8; i++){
    temp_bit = random(0, 255) & 1; 
    Serial.print(temp_bit);
    my_byte |= temp_bit << i; 
  }
  Serial.println();
  Serial.println(my_byte);
  Serial.println(my_byte, BIN);
  Serial.println("-----------");
  my_byte = 0;
  delay(1000);
}
