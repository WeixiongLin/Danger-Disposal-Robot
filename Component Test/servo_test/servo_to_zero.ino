#include <Servo.h>

Servo myservo; 
void setup() 
{
  myservo.attach(9);
  myservo.write(180);
}
void loop() 
{ 
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(10);
  delay(1000);
  
}
