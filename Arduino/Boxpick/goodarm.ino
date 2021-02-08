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
int basedeg = 45;
int bdeg = 45;
int shoulderdeg = 115;
int sdeg = 115;
int elbowdeg = 155;
int edeg = 155;
int wrolldeg;
int wpitchdeg;
int gripperdeg;
char distance3[5];
int r = 0;
int c = 0;
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
 Serial.begin(9600);
 Wire.begin(4);
 Wire.onReceive(receiveEvent);
 baseservo.attach(base);
 shoulderservo.attach(shoulder);
 elbowservo.attach(elbow);
 wrollservo.attach(wroll);
 wpitchservo.attach(wpitch);
 gripperservo.attach(gripper);
 
 /////////////// Making sure the arm is in resting position ////////////////////////////////////////
 delay(2000);
 elbowservo.write(150);
 delay(1000);
 shoulderservo.write(125);
 delay(1000);
 baseservo.write(25);
 delay(1000);
 wrollservo.write(15);
 delay(1000);
 wpitchservo.write(135);
 delay(1000);
 gripperservo.write(40);
 delay(1000);
}


void loop() 
{
  int distance3 = Wire.read();
  Serial.print(distance3);
  if (0<= distance3 <=10)
  {
    delay(3000);
    shoulderservo.write(150);
    delay(1000);
    gripperservo.write(8);
    delay(1000);
    shoulderservo.write(125);
    delay(1000);
    elbowservo.write(90);
    delay(2000);
    baseservo.write(100);
    delay(1000);
    shoulderservo.write(115);
    delay(1000);
    elbowservo.write(150);
    delay(2000);
    gripperservo.write(40);
    delay(2000);
    elbowservo.write(150);
    delay(1000);
    shoulderservo.write(125);
    delay(1000);
    baseservo.write(25);
    delay(1000);
    wrollservo.write(15);
    delay(1000);
    wpitchservo.write(135);
    delay(1000);
    gripperservo.write(40);
    delay(1000);
  }
  else
  {
    Serial.print("No box");
  }
  exit(0);
}
