#include <Wire.h>
#include <AccelStepper.h>
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
int trigPin3=6;
int echoPin3=7;
// Height
int trigPin4=8;
int echoPin4=9;
//Width Far
int trigPin5=10;
int echoPin5=11;
// Width Close
int trigPinl=12;
int echoPinl=13;
//length
int wofconv=14; //Check conveyor Length
int interger = 0;

////Change every condition based on distance from convyor belt./////////////////////////////
long duration3;
long duration4;
long distance5;
int SA;
float w;
float l;


void setup() 
{
  Serial.begin (19200);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
  pinMode(trigPinl, OUTPUT);
  pinMode(echoPinl, INPUT);
  stepper.setMaxSpeed(1000);
  Wire.begin(); 

}

void loop() 
{
 interger = interger + 1;
 int inter1 = interger % 8000;
 if (inter1 == 0)
  {
    float duration3;
    digitalWrite(trigPin3, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);
    duration3 = pulseIn(echoPin3, HIGH);
    float distance3 = (duration3*0.0343) / 2;
    delay(30);
    
// Distance based on the dimention on conv.
    if (distance3 >= 12 || distance3 <= 1)
    {
      stepper.setSpeed(48);
      stepper.runSpeed();
    }
    else
    {
      delay(500);
      float inter11 = 14 - distance3;
      Serial.print("h = ");
      Serial.println(inter11);
      float duration4;
      digitalWrite(trigPin4, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin4, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin4, LOW);
      duration4 = pulseIn(echoPin4, HIGH);
      float distance4 = (duration4*0.0343) / 2;
      delay(30);
///////////////////////////////////////////////////
      float duration5;
      digitalWrite(trigPin5, LOW);// Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin5, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin5, LOW);
      duration5 = pulseIn(echoPin5, HIGH);
      float distance5 = (duration5*0.0343) / 2;
      delay(30);

      w = wofconv - (distance4 + distance5); // Change based on Length. Also which sensor, change based on that
      Serial.print("w = ");
      Serial.println(w);

      float durationl;
      digitalWrite(trigPinl, LOW); 
      delayMicroseconds(2); 
      digitalWrite(trigPinl, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPinl, LOW);
      durationl = pulseIn(echoPinl, HIGH);
      float distancel = (durationl*0.0343) / 2;
      delay(30);

      l = 25 - (13.5 + distancel);
      Serial.print("l = ");
      Serial.println(l);

      SA = w*l*distance3;
      Serial.print("SA = ");
      Serial.println(SA);
    }

    if (w>=6 || w<=2)
    {
      Serial.print("");
    }
    else
    {
    Wire.beginTransmission(9);  
    Wire.write(SA);            
    Wire.endTransmission();
    w = 0;
    }
  }
  else
  {
    stepper.setSpeed(48);
    stepper.runSpeed();
  }
}
