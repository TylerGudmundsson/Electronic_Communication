#include <Wire.h>
#include <Serial.h>
byte on= 0x01;
byte off=0x02;
byte address[]= {
  0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x61,0x62,0x63};
int j=0;
int k=0;
int x=0;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  while(k<10){
  while(x<3){
  for(j=0;j<10;j++){
    if(x==0){
      Wire.beginTransmission(address[k]);
      Wire.write(0x01);
      Wire.write(0x02);
      Wire.write(0x02);
      Wire.endTransmission();
      delay(500);
    }

    if(x==1){

      Wire.beginTransmission(address[k]);
      Wire.write(0x02);
      Wire.write(0x01);
      Wire.write(0x02);
      Wire.endTransmission();
      delay(500);
    }

    if(x==2){

      Wire.beginTransmission(address[k]);
      Wire.write(0x02);
      Wire.write(0x02);
      Wire.write(0x01);
      Wire.endTransmission();
      delay(500);
    }

    Wire.beginTransmission(address[k]);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.write(0x02);
    Wire.endTransmission();
    delay(500);
  }
  x++;
  }
  x=0;
  k++;
  }
  k=0;
}










