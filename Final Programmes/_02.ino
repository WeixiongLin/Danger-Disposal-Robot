#include <SoftwareSerial.h>
#include<Servo.h>
Servo servo_1;////////////////////////网兜
Servo servo_2;////////////////////////基座
SoftwareSerial BT(5,A0);//二号口没用
int M1 = 3; //PWMA
int M2 = 4; //PWMB
int E1 = 6; //PWMA
int E2 = 7; //PWMB

const int TrigPin = 8; //发出超声波
const int EchoPin = 9; //收到反射回来的超声波
const int buzzer=10;//设置控制蜂鸣器的数字IO脚
float cm; //因为测得的距离是浮点型的
int angle_1 = 180;
int angle_2 = 180;
char x;

void forward()
{
  digitalWrite(M1, HIGH);//the speed value of motorA is HIGH
   digitalWrite(M2, LOW);
    digitalWrite(E1, HIGH);
    digitalWrite(E2, LOW);
}

void backward()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(E1, LOW); 
  digitalWrite(E2, HIGH);
}
void left()
{
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(E1, HIGH); 
    digitalWrite(E2, LOW);
 }
 void right()
 {
      digitalWrite (M1, HIGH); 
      digitalWrite (M2, LOW);
      digitalWrite(E1, LOW);
      digitalWrite(E2, LOW);
  }
  void rotright()
{
      digitalWrite (M1, HIGH); 
      digitalWrite (M2, LOW);
      digitalWrite(E1, LOW);
      digitalWrite(E2, HIGH);
  }
void rotleft()
{
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    digitalWrite(E1, HIGH); 
    digitalWrite(E2, LOW);
 }
  
  void brake()
  {
      digitalWrite(M1, LOW); 
      digitalWrite(E1, LOW); 
      digitalWrite(M2, LOW);
      digitalWrite(E2, LOW); 
 }

//舵机和超声报警
void bee_open()
{
  digitalWrite(buzzer,LOW);//发声音
}

void bee_close()
{
  digitalWrite(buzzer,HIGH);//关声音
}

void ultrawave()
{
  digitalWrite(TrigPin, LOW); //低电平发一个短时间脉冲去TrigPin 
  delayMicroseconds(2);       // delayMicroseconds在更小的时间内延时准确
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW); //通过这里控制超声波的发射
  cm = pulseIn(EchoPin, HIGH) / 58.0; //将回波时间换算成cm 
  if(cm<35)
  {
    bee_open();
  }
  else
  {
    bee_close();
  }
}

void downdown()
{
  angle_1 = angle_1 - 10;
  servo_1.write(angle_1);
}

void upup()
{
  angle_1 = angle_1 + 10;
  servo_1.write(angle_1);
}

void putdown()/////////////////////////////放下网兜
{
  angle_1 = 90;
  servo_1.write(angle_1);
}

void lift90()
{
  angle_1 = 180;
  servo_1.write(angle_1);
}

void liftup()/////////////////////////////抬起网兜
{
  angle_1 = 140;
  servo_1.write(angle_1);
}

void sweep_1()////////////////////////////向后扫糖_1
{
  angle_2 = 110;
  servo_2.write(110);
}

void sweep_2()////////////////////////////向后扫糖_2
{
  servo_2.write(60);
  angle_2 = 60;
}

void clockwise()
{
  angle_2 = angle_2 - 10;
  servo_2.write(angle_2);
}

void counterclockwise()
{
  angle_2 = angle_2 + 10;
  servo_2.write(angle_2);
}

void sweepback()////////////////////////////扫糖复位
{
  servo_2.write(180);
}

void setup() {
Serial.begin(9600);
BT.begin(9600);
pinMode(E1, OUTPUT);
digitalWrite(E1, LOW); // When not sending PWM, we want it low
pinMode(M1, OUTPUT);
digitalWrite(M1, LOW); // When not sending PWM, we want it low
pinMode(E2, OUTPUT);
digitalWrite(E2, LOW); // When not sending PWM, we want it low
pinMode(M2, OUTPUT);
digitalWrite(M2, LOW); // When not sending PWM, we want it low
  ////////////////////////////////////////超声模块
  pinMode(TrigPin, OUTPUT); 
  pinMode(EchoPin, INPUT); 
  ////////////////////////////////////////蜂鸣器模块
  pinMode(buzzer,OUTPUT);//设置数字IO脚模式，OUTPUT为输出
  ////////////////////////////////////////舵机群
  servo_1.attach(11);
  servo_1.write(180);
  servo_2.attach(12);
  servo_2.write(180);
} 

/*
小车分为上下两层，分别执行机械臂和动力操作。
机械臂使用串口：超声波(8,9)，蜂鸣器(10), 机械臂(11,12,13)。
动力操作使用串口：3~7, A0。
 */

void loop() 
{ 
  ultrawave();
  if(Serial.available())
 {
    x = Serial.read();
    switch(x)
    {
      case'w':lift90();break;
      case'a':downdown();break;
      case'e':upup();break;
      case'u':liftup();break;
      case'd':putdown();break;
      case's':sweep_1();break;
      case'q':sweep_2();break;
      case'b':sweepback();break;
      case'c':clockwise();break;
      case'o':counterclockwise();break;
    }
  }
  if(BT.available()>0){
    char c=BT.read();
  if(c=='f')
  {
    forward();
   }
  else if(c=='l')
  {
       left(); 
   }
  else if(c=='r')
  {
    right();
   }
   else if(c=='b')
  {
      backward();
  }
  else if(c=='s')
  {
      brake();
   }
   else if(c=='c')
   {
      rotleft();      
    }
    else if(c=='o')
    {
      rotright();
     }
  }
}

