#include <math.h>
#include <stdio.h>
#include "SPI.h"
#include "SD.h"

const int chipSelect = 10; 
const int dirPinPolar = 3;
const int dirPinAzimut = 5;
const int stepPinPolar = 2;
const int stepPinAzimut = 4;
const float angleStep = 1.8;

void rotate(int pin, float angle)
{ 
  int steps = int(angle / angleStep);
  for (int i = 0; i < steps; i++)
  {
    digitalWrite(pin, HIGH); 
    delayMicroseconds(2000);
    digitalWrite(pin, LOW);
  }
}

void rotateAzimut(float angle)
{
  if (angle > 0)
  {
    digitalWrite(dirPinAzimut, LOW); 
  }
  else
  {
    digitalWrite(dirPinAzimut, HIGH); 
  }
  rotate(stepPinAzimut, angle);
}

void rotatePolar(float angle)
{
  if (angle > 0)
  {
    digitalWrite(dirPinPolar, LOW); 
  }
  else
  {
    digitalWrite(dirPinPolar, HIGH); 
  }
  rotate(stepPinPolar, angle);
}

void setup()
{ 
  Serial.begin(9600);
  pinMode(SS, OUTPUT);
  pinMode(stepPinPolar, OUTPUT);
  pinMode(dirPinPolar, OUTPUT);
  pinMode(stepPinAzimut, OUTPUT);
  pinMode(dirPinAzimut, OUTPUT);
  
  float x = 0;
  float y = 0;
  float z = 0;
  int c;
  char line[256];

  while (!SD.begin(SPI_HALF_SPEED, 4)) {
    Serial.println("initialization failed");
  }

  File gcode = SD.open("gcode.txt");

  if (gcode) {
    fgets(line, dataFile, 256);
    dataFile.close();
    Serial.println("Success!");
  }
  else { 
    Serial.println("error opening file"); 
  }
  
  sscanf(line, "G%d ", &c);
  if (c == 1)
  {
    sscanf(line, "G1 X%f Y%f Z%f", &x, &y, &z);
  }
  
  float radius = sqrt(x*x + y*y + z*z);
  float polar = (acos(z/radius) * 180) / M_PI;
  float azimut = (atan2(y, x) * 180) / M_PI;
  if (polar != 0.0)
  {
    rotatePolar(polar);
  }

  if(azimut != 0.0)
  {
    rotateAzimut(azimut);
  }
}
   
void loop()
{
 

}
