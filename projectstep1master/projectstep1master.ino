//Tyler Gudmundsson Master to slave communications
#include <Wire.h>
#include <Serial.h>
byte byteinfo= (0x01);
byte byteinfo2=(0x02);
byte address[]= {
  0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x61,0x62,0x63};
int j=0;
int k=0;
int l=0;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  for (j=0;j<10;j++)
  {
    x=0;
      Wire.beginTransmission(address[j]);
    while(x<10){
      Wire.write(byteinfo);
      Wire.write(byteinfo2);
      Wire.write(byteinfo2);
      delay(500)
      Wire.write(byteinfo2);
      Wire.write(byteinfo2);
      Wire.write(byteinfo2);
      Wire.endTransmission();
      delay(500);
      x++;
    }
  }
  for (k=0;k<10;k++)
  {
    x=0;
      Wire.beginTransmission(address[k]);
    while(x<10){
      Wire.write(byteinfo2);
      Wire.write(byteinfo);
      Wire.write(byteinfo2);
      delay(500)
      Wire.write(byteinfo2);
      Wire.write(byteinfo2);
      Wire.write(byteinfo2);
      Wire.endTransmission();
      delay(500);
      x++;
    }
  }
  for (l=0;l<10;l++)
  {
    x=0;
      Wire.beginTransmission(address[l]);
    while(x<10){
      Wire.write(byteinfo2);
      Wire.write(byteinfo2);
      Wire.write(byteinfo);
      delay(500)
        Wire.write(byteinfo2);
      Wire.write(byteinfo2);
      Wire.write(byteinfo2);
      Wire.endTransmission();
      delay(500);
      x++;
    }
  }
}




