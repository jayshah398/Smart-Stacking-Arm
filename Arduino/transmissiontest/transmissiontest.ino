#include <Wire.h>
int SA;
void setup() 
{
  // put your setup code here, to run once:
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(19200);
}

void receiveEvent(int bytes) 
{
  SA = Wire.read();      
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(SA);
  SA = 0;
  delay(1000);

}
