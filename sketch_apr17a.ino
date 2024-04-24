#include <math.h>
#include <stdio.h>

const int dirPin1 = 3;
const int dirPin2 = 5;
const int stepPin1 = 2;
const int stepPin2 = 4;
const int stepsPerRevolution = 360;
 
void spin()
{
  digitalWrite(dirPin1, HIGH); 
  // digitalWrite(dirPin2, HIGH);
  digitalWrite(stepPin1, HIGH);
  delayMicroseconds(2000);
  digitalWrite(stepPin1, LOW);
  //for(int x = 0; x < stepsPerRevolution; x++)
  {
    //digitalWrite(stepPin1, HIGH);
    //digitalWrite(stepPin2, HIGH);
    //delayMicroseconds(2000);
    //digitalWrite(stepPin1, LOW);
    //digitalWrite(stepPin2, LOW);
    //delayMicroseconds(2000);
  }
}

void rotate(float x, float y, float z)
{
  float radius = sqrt(x*x + y*y + z*z);
  float polar = (acos(z/radius) * 180) / M_PI;
  float azimut = (atan2(y, x) * 180) / M_PI;
}

void setup()
{
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  float x;
  float y;
  float z;
  float g;
  int c; 

  char line[100];
  //while(!feof(file))
  //{
  //    fgets(line, sizeof(line), stdin);
  //    sscanf(line, "G%d ", &c);
  //    if (c == 1)
  //    {
  //        sscanf(line, "G1 X%f Y%f Z%f", &x, &y, &z);
  //    }
  //}
  //rotate(x, y, z);
  for (int i = 0; i < 200; i++)
    spin();
}

void loop()
{
 

}
