void setup() {
Serial.begin(9600);
}

void loop() {
  for(int x = 0; x <= 1; x++)
  {
    for(int y = 0; y <= 1; y++)
    {
      Serial.println('x');
      delay(2000);
      break;
    }
    Serial.println('y');
    delay(2000);
  }
exit(0);
}
