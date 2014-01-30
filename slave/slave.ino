//Tyler Gudmundsson Master to slave communications
#include <Wire.h>
int red = 13;
int green = 12;
int yellow = 11;
void setup()
{
  Wire.begin(0x12);
  Wire.onReceive (receiveEvent);
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
}
void loop()
{
  //delay(100);
}
void receiveEvent(int howMany)
{
  byte a = Wire.read();   //receive first byte
  byte b = Wire.read();  //receive second byte
  byte c = Wire.read(); // receive third byte
  Serial.print(a);     // print the bytes for debugging
  Serial.print(b);     
  Serial.println(c);

  if (a == 0x01)  // case 1 : led on
  {
    digitalWrite(red,HIGH);
  }
  if (a == 0x02)//case 2 :led off
  {
    digitalWrite(red,LOW);
  }

  if (a != 0x01 && a != 0x02) //case 3 blink if invalid command
  {
    digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(16000);               // wait for 1.6 seconds
    digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
    delay(16000);               // wait for 1.6 seconds
  }

  if (b == 0x01) //repeated cases for each led
  {
    digitalWrite(green,HIGH);
  }
  if (b == 0x02)
  {
    digitalWrite(green,LOW);
  }

  if (b != 0x01 && b != 0x02)
  {
    digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(16000);               // wait for a second
    digitalWrite(green, LOW);    // turn the LED off by making the voltage LOW
    delay(16000);               // wait for a second
  }



  if (c == 0x01)
  {
    digitalWrite(yellow,HIGH);
  }
  if (c == 0x02)
  {
    digitalWrite(yellow,LOW);
  }

  if (c != 0x01 && c != 0x02)
  {
    digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(16000);               // wait for a second
    digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
    delay(16000);               // wait for a second
  }
}



