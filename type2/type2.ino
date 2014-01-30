#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;
byte t = 0x01;
int count =0;
void loop()
{
  Wire.beginTransmission(0x11); // transmit to device #4
  //Wire.write("x is ");        // sends five bytes

  Wire.write(t);     // sends one byte  
  Wire.endTransmission();    // stop transmitting
  
  x++;
  delay(1000);
  
}
