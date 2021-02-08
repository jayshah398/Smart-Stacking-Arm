#include <Servo.h>
#include <Wire.h>
/////////////////////////////////////////////////////////////////////////////////////
const int base = 10;
const  int shoulder = 9;
const  int elbow = 8;
const  int wroll = 7;
const  int wpitch = 6;
const  int gripper = 5;
int trigPin = 12;
int echoPin = 11;
long duration;
//////////////////////////////////////////////////////////////////////////////////////
int SA = 0;
int pitchdeg = 163;
int pitch = 163;
int basedeg = 60;
int basedeg1;
int stackdeg = 106;
int a[4];
int o[4];
int j = 1;
//////////////////////////////////////////////////////////////////////////////////////
Servo baseservo;
Servo shoulderservo;
Servo elbowservo;
Servo wrollservo;
Servo wpitchservo;
Servo gripperservo;
///////////////////////////////////////////////////////////////////////////////////////
void setup() 
{
  baseservo.attach(base);
  shoulderservo.attach(shoulder);
  elbowservo.attach(elbow);
  wrollservo.attach(wroll);
  wpitchservo.attach(wpitch);
  gripperservo.attach(gripper);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
 /////////////// Making sure the arm is in resting position ////////////////////////////////////////
  delay(2000);
  elbowservo.write(80);
  delay(1000);
  shoulderservo.write(163);
  delay(1000);
  baseservo.write(29);
  delay(1000);
  wrollservo.write(15);
  delay(1000);
  wpitchservo.write(124);
  delay(1000);
  gripperservo.write(40.6);
  delay(1000);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(19200);
}

void receiveEvent(int bytes) 
{
  SA = Wire.read();      
}

void loop()
{
  for(int bn = 0; bn <= 3; ++bn)
  {
    delay(1000);
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    float distance = (duration*0.0343) / 2;
    delay(30);
    long s = distance;
    if (s > 19 || s < 5)
    {
      Serial.println("No box");
      bn = bn - 1; 
    }
    else
    {
      int y = 0;
      y = SA;
      Serial.println(SA);
      if (bn == 0)
      {
        a[0] = y;
        o[0] = y;
      }
      else if (bn == 1)
      {
        a[1] = y;
        o[1] = y;
      }
      else if (bn == 2)
      {
        a[2] = y;
        o[2] = y;
      }
      else if (bn == 3)
      {
        a[3] = y;
        o[3] = y;
      }
      wpitchservo.write(137);
      delay(1000);
      for (int sho = 163; sho >= 127; sho = sho - 1)
      {
        shoulderservo.write(sho);
        delay(100);
      }
      delay(1000);
      gripperservo.write(10.2);
      delay(1000);
      shoulderservo.write(165);
      delay(1000);
      shoulderservo.write(165);
      delay(1000);
      shoulderservo.write(165);
      delay(1000);
      baseservo.write(basedeg);
      delay(1000);
    /////////////////////////////////
      wpitchservo.write(163);
      delay(1000);
      for (int sho1 = 165; sho1 >= 106; sho1 = sho1 - 1)
      {
        shoulderservo.write(sho1);
        delay(100);
      }
      delay(1000);
      elbowservo.write(77);
      delay(2000);
      gripperservo.write(40.6);
      delay(2000);
    //////////////////////////
      shoulderservo.write(165);
      delay(1000);
      shoulderservo.write(165);
      delay(1000);
      shoulderservo.write(165);
      delay(1000);
      elbowservo.write(80);
      delay(1000);
      wpitchservo.write(120);
      delay(1000);
      baseservo.write(29);
      delay(1000);
      basedeg = basedeg + 20;
    }
    SA = 0;
    delay(1000); 
  }
  Serial.println("why me");
  Serial.println(a[1]);
  Serial.println(a[2]);
  Serial.println(a[3]);
/////////////////////////////Sorting//////////////////////////////////
  for(int i = 0; i<4; i++) 
  {
    for(int k = i+1; k<4; k++)
    {
      if(a[k] < a[k+1])
      {
        int temp = a[k];
        a[k] = a[k+1];
        a[k + 1] = temp;
      }
    }
  }
///////////////////////////////////////////////////////////////
  for(int z = 0; z <= 3; ++z)
  { 
    if (a[z] == o[0])
    {
      basedeg1 = 120;
      shoulderservo.write(165);
      delay(2000);
      baseservo.write(basedeg1);//if else statement to pick box
      delay(1000);
      wpitchservo.write(163);
      delay(1000);
      for (int sho = 163; sho >= 106; sho = sho - 1)
      {
        shoulderservo.write(sho);
        delay(100);
      }
      gripperservo.write(11.2);
      delay(2000);
      shoulderservo.write(165);
      delay(2000);
      shoulderservo.write(165);
      delay(2000);
      baseservo.write(160);
      delay(1000);
      for (int sho = 163; sho >= stackdeg; sho = sho - 1)
      {
       shoulderservo.write(sho);
       delay(100);
       }
      stackdeg = stackdeg + 8;
      delay(1000);
      int wp = 163;
      wpitchservo.write(wp);
      wp = wp - 3;
      delay(1000);
      gripperservo.write(40.6);
      delay(1000);
      shoulderservo.write(165);
      delay(1000);
      shoulderservo.write(165);
      delay(1000);
    }
    else if (a[z] == o[1])
    {
      basedeg1 = 100;
      shoulderservo.write(165);
    delay(2000);
    baseservo.write(basedeg1);//if else statement to pick box
    delay(1000);
    wpitchservo.write(163);
    delay(1000);
    for (int sho = 163; sho >= 106; sho = sho - 1)
    {
      shoulderservo.write(sho);
      delay(100);
    }
    gripperservo.write(11.2);
    delay(2000);
    shoulderservo.write(165);
    delay(2000);
    shoulderservo.write(165);
    delay(2000);
    baseservo.write(160);
    delay(1000);
    for (int sho = 163; sho >= stackdeg; sho = sho - 1)
    {
      shoulderservo.write(sho);
      delay(100);
    }
    stackdeg = stackdeg + 8;
    delay(1000);
    int wp = 163;
    wpitchservo.write(wp);
    wp = wp - 3;
    delay(1000);
    gripperservo.write(40.6);
    delay(1000);
    shoulderservo.write(165);
    delay(1000);
    shoulderservo.write(165);
    delay(1000);
    }
    else if (a[z] == o[2])
    {
     basedeg1 = 80;
     shoulderservo.write(165);
    delay(2000);
    baseservo.write(basedeg1);//if else statement to pick box
    delay(1000);
    wpitchservo.write(163);
    delay(1000);
    for (int sho = 163; sho >= 106; sho = sho - 1)
    {
      shoulderservo.write(sho);
      delay(100);
    }
    gripperservo.write(11.2);
    delay(2000);
    shoulderservo.write(165);
    delay(2000);
    shoulderservo.write(165);
    delay(2000);
    baseservo.write(160);
    delay(1000);
    for (int sho = 163; sho >= stackdeg; sho = sho - 1)
    {
      shoulderservo.write(sho);
      delay(100);
    }
    stackdeg = stackdeg + 8;
    delay(1000);
    int wp = 163;
    wpitchservo.write(wp);
    wp = wp - 3;
    delay(1000);
    gripperservo.write(40.6);
    delay(1000);
    shoulderservo.write(165);
    delay(1000);
    shoulderservo.write(165);
    delay(1000); 
    }
    else if (a[z] == o[3])
    {
    basedeg1 = 60;
    shoulderservo.write(165);
    delay(2000);
    baseservo.write(basedeg1);//if else statement to pick box
    delay(1000);
    wpitchservo.write(163);
    delay(1000);
    for (int sho = 163; sho >= 106; sho = sho - 1)
    {
      shoulderservo.write(sho);
      delay(100);
    }
    gripperservo.write(11.2);
    delay(2000);
    shoulderservo.write(165);
    delay(2000);
    shoulderservo.write(165);
    delay(2000);
    baseservo.write(160);
    delay(1000);
    for (int sho = 163; sho >= stackdeg; sho = sho - 1)
    {
      shoulderservo.write(sho);
      delay(100);
    }
    stackdeg = stackdeg + 8;
    delay(1000);
    int wp = 163;
    wpitchservo.write(wp);
    wp = wp - 3;
    delay(1000);
    gripperservo.write(40.6);
    delay(1000);
    shoulderservo.write(165);
    delay(1000);
    shoulderservo.write(165);
    delay(1000);
  }
  else
    {
     Serial.print(" ");
    }
 }
}
