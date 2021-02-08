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
int basedeg = 60;
int dbase = 60;
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
  wpitchservo.write(137);
  delay(1000);
  gripperservo.write(40);
  delay(1000);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(19200);
}

void receiveEvent(int bytes) 
{
  x = Wire.read();      
}

void loop()
{
  for(int bn = 0; bn <= 3; ++bn)
  {
    long y = x;
    Serial.println(x);
    if (y >= 12 || y <= 1)
    {
      Serial.println("No box");
      bn = bn - 1; 
    }
    else
    {
      shoulderservo.write(127);
      delay(2000);
      gripperservo.write(8);
      delay(2000);
      shoulderservo.write(163);
      delay(2000); 
      baseservo.write(basedeg);
      delay(1000);
    /////////////////////////////////
      wpitchservo.write(163);
      delay(1000);
      for (int sho = 163; sho >= 103; sho = sho - 1)
      {
        shoulderservo.write(sho);
        delay(100);
      }
      delay(1000);
      elbowservo.write(77);
      delay(2000);
      gripperservo.write(40);
      delay(2000);
    //////////////////////////
      shoulderservo.write(163);
      delay(1000);
      elbowservo.write(80);
      delay(1000);
      wpitchservo.write(137);
      delay(1000);
      baseservo.write(28);
      delay(1000);
      basedeg = basedeg + 20;
    }
    delay(1000); 
  }

  
}  
