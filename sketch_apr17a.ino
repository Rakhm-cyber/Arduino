#include <math.h>

const int dirPin1 = 3;
const int dirPin2 = 5;
const int stepPin1 = 2;
const int stepPin2 = 4;
const int stepsPerRevolution = 200;
 
void spin()
{
  digitalWrite(dirPin1, HIGH); // Установка вращения по часовой стрелки
  digitalWrite(dirPin2, HIGH);

  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(2000);
  }

}

void rotate(float x, y, z)
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


  // file reading
  rotate(x, y, z);

}

void loop()
{

}