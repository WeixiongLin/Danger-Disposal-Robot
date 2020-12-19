const int ti=0;
int M1 = 9; //PWMA
int M2 = 10; //PWMB
int E1 = 5; //PWMA
int E2 = 6; //PWMB
void forward()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(E1, LOW); 
  digitalWrite(E2, HIGH);
  //delay(ti);
}
void backward()
{
    digitalWrite(M1, HIGH);//the speed value of motorA is HIGH
    digitalWrite(M2, LOW);
    digitalWrite(E1, HIGH);
    digitalWrite(E2, LOW);
    //delay(ti);
}
void left()
{
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    digitalWrite(E1, LOW); 
    digitalWrite(E2, LOW);
    //delay(ti);  
 }
 void right()
 {
      digitalWrite (M1, LOW); 
      digitalWrite (M2, LOW);
      digitalWrite(E1, LOW);
      digitalWrite(E2, HIGH);
    //  delay(ti);
  }

  void brake()
  {
      digitalWrite(M1, LOW); 
      digitalWrite(E1, LOW); 
      digitalWrite(M2, LOW);
      digitalWrite(E2, LOW); 
  //    delay(ti);
 }

void setup() {
Serial.begin(9600);
pinMode(E1, OUTPUT);
digitalWrite(E1, LOW); // When not sending PWM, we want it low
pinMode(M1, OUTPUT);
digitalWrite(M1, LOW); // When not sending PWM, we want it low
pinMode(E2, OUTPUT);
digitalWrite(E2, LOW); // When not sending PWM, we want it low
pinMode(M2, OUTPUT);
digitalWrite(M2, LOW); // When not sending PWM, we want it low
}
void loop() {
  /*forward();
  backward();
  left();
  right();*/
  if(Serial.available()>0){
    char c=Serial.read();
  Serial.print(c);
  if(c=='f')
  {
    forward();
    Serial.println("forward");
   }
  else if(c=='l')
  {
       left(); 
        Serial.println("left"); 
   }
  else if(c=='r')
  {
    right();
    Serial.println("right"); 
   }
   else if(c=='b')
  {
      backward();
      Serial.println("backward"); 
  }
  else if(c=='s')
  {
      brake();
      Serial.println("brake"); 
   }
  }
}
