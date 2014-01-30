//Tyler Gudmundsson Master to slave communications
#include <Wire.h>
#include <Serial.h>
byte byteinfo= 0;

void setup()
{
Wire.begin();
Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
  byteinfo=Serial.read();
  Serial.print(byteinfo);
  }
  Wire.beginTransmission(11);
  Wire.write(byteinfo);
  Wire.endTransmission();
  byteinfo=0;
  delay(1000);
}
  
