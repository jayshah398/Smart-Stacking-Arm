#include <Servo.h>
#include <Wire.h>
/////////////////////////////////////////////////////////////////////////////////////
const int base = 10;
const  int shoulder = 9;
const  int elbow = 8;
const  int wroll = 7;
const  int wpitch = 6;
const  int gripper = 5;
//////////////////////////////////////////////////////////////////////////////////////
int x = 0;
int pitchdeg = 163;
int pitch = 163;
int basedeg = 70;
int dbase = 70;
int trigPin = 12;
int echoPin = 11;
long duration;
//////////////////////////////////////////////////////////////////////////////////////
Servo baseservo;
Servo shoulderservo;
Servo elbowservo;
Servo wrollservo;
Servo wpitchservo;
Servo gripperservo;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  baseservo.attach(base);
  shoulderservo.attach(shoulder);
  elbowservo.attach(elbow);
  wrollservo.attach(wroll);
  wpitchservo.attach(wpitch);
  gripperservo.attach(gripper);
 
 /////////////// Making sure the arm is in resting position ////////////////////////////////////////
  delay(2000);
  elbowservo.write(80);
  delay(1000);
  shoulderservo.write(163);
  delay(1000);
  baseservo.write(28);
  delay(1000);
  wrollservo.write(15);
  delay(1000);
  wpitchservo.write(123);
  delay(1000);
  gripperservo.write(40);
  delay(1000);
  Serial.begin(19200);
}

void loop()
{
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    float distance = (duration*0.0343) / 2;
    Serial.println(distance);
    delay(30);
    //////////////////////////
}
