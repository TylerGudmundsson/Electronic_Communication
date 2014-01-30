#include <Wire.h>
#include <Serial.h>
byte byteinfo= 0x01;
byte byteinfo2=0x02;
byte address[]= {
  0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x61,0x62,0x63};
int j=0;
int k=0;
int l=0;
int x=0;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  for(j=0;j<10;j++){
    Wire.beginTransmission(0x11);
    Wire.write(0x01);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.endTransmission();
    delay(500);

    Wire.beginTransmission(0x11);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.endTransmission();
    delay(500);

  }
  for(k=0;k<10;k++){
    Wire.beginTransmission(0x11);
    Wire.write(0x02);
    Wire.write(0x01);
    Wire.write(0x02);
    Wire.endTransmission();
    delay(500);

    Wire.beginTransmission(0x11);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.endTransmission();
    delay(500);

  }
  for(l=0;l<10;l++){
    Wire.beginTransmission(0x11);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.write(0x01);
    Wire.endTransmission();
    delay(500);

    Wire.beginTransmission(0x11);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.endTransmission();
    delay(500);

  }
}





