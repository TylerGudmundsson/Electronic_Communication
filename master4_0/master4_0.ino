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
  while(k<10) //Loop for all ten addresses
  {
    while(x<3) //Loop for the 3 LED's
    {
      while(j<10) //Loop for 10 seconds
      {
        if(x==0) //First loop turn LED1 on
        {
          Wire.beginTransmission(address[k]);
          Wire.write(on);
          Wire.write(off);
          Wire.write(off);
          Wire.endTransmission();
          delay(500); //1st half a second delay to make loop 1 second long
        }

        if(x==1) //Second loop turn LED2 on
        {
          Wire.beginTransmission(address[k]);
          Wire.write(off);
          Wire.write(on);
          Wire.write(off);
          Wire.endTransmission();
          delay(500);
        }

        if(x==2) //Third loop turn LED3 on
        {
          Wire.beginTransmission(address[k]);
          Wire.write(off);
          Wire.write(off);
          Wire.write(on);
          Wire.endTransmission();
          delay(500);
        }

        Wire.beginTransmission(address[k]); //Turn all LED's off every loop
        Wire.write(off);
        Wire.write(off);
        Wire.write(off);
        Wire.endTransmission();
        delay(500); //2nd half a second delay to make loop 1 second long
        j++; //Increase 10 second count
      }
      j=0; //Rest 10 second loop
      x++; //Increase LED count
    }
    x=0; //Reset LED count
    k++; //Increase address count
  }
  k=0; //Reset address count
}











