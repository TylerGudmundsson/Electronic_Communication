//Tyler Gudmundsson Master to slave communications
#include <Wire.h>
#include <Serial.h>
byte byteinfo= (0x01);
byte byteinfo2=(0x02);
byte bytestring[3]= {0x01,0x02,0x01};
int code=0;
int x=0;
void setup()
{
Wire.begin();
Serial.begin(9600);
}

void loop()
{
  
  if (Serial.available())
  {
  code=Serial.read();
  Serial.print(byteinfo);
  }
  if (code==(1))
  {
  Wire.beginTransmission(11);
  Wire.write(byteinfo);
  Wire.write(byteinfo2);
  Wire.write(byteinfo);
  Wire.endTransmission();
  byteinfo=0;
  delay(1000);
  }
  if (code==(2))
  {
  Wire.beginTransmission(11);
  Wire.write(byteinfo2);
  Wire.write(byteinfo);
  Wire.write(byteinfo2);
  Wire.endTransmission();
  byteinfo=0;
  delay(1000);
  }
  if (code==(3))
  {
  Wire.beginTransmission(11);
  for (x=0;x<2;x++)
  Wire.write(bytestring[x]);
  Wire.endTransmission();
  byteinfo=0;
  delay(1000);
  }
}
  
