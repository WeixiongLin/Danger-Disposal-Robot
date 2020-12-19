#include <Servo.h>

#define IN1 4
#define IN2 10
#define IN3 12
#define IN4 11
Servo servo_afthand;
Servo servo_prehand;
Servo servo_head;
Servo servo_claw;
char x;
//电机初始化
void IniMotor()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //pinMode(ENA,OUTPUT);
  //pinMode(ENB,OUTPUT);
}

//舵机初始化
void iniServo()
{
  servo_claw.attach(3);
  servo_afthand.attach(5);
  servo_head.attach(9);
  servo_prehand.attach(6);
  servo_afthand.write(90);
  servo_prehand.write(90);
  servo_head.write(85);
  servo_claw.write(10);

}
//直走
void goLine()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

//右转
void turnRight()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  delay(100);
}
//左转
void turnLeft()
{
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(100);
}

//制动
void stopp()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  //analogWrite(ENA,rightSpeed);
  //analogWrite(ENB,leftSpeed); 
}

//放下臂
void handup()
{
    int  i = servo_afthand.read();
    for(i;i<=145;i++)
    {
        servo_afthand.write(i);
        delay(25);
    } 
    int j = servo_prehand.read();
    for(j;j>=70;j--)
    {
        servo_prehand.write(j);
        delay(25);
    }
 }

//收起臂
void handback()
{
   int j = servo_prehand.read();
   for(int j=70;j<=90;j++)
    {
        servo_prehand.write(j);
        delay(25);
    }
    int  i = servo_afthand.read();
    for(int i=145;i>=90;i--)
    {
        servo_afthand.write(i);
        delay(25);
    } 
}

//打开爪
void clawopen()
{
   int k = servo_claw.read();
    for(k;k<=130;k++)
    {
        servo_claw.write(k);
        delay(30); 
}
}

//关闭爪
void clawoff(){
    int k = servo_claw.read();
    for(k;k>=10;k--)
    {
      servo_claw.write(k);
      delay(30);
    }
}

//机械臂转向左90°
void switchleft()
{
    int p = servo_head.read();
    int q = p+90;
    if(q>180)
   {
    for(p;p<=180;p++)
   {
    servo_head.write(p);
    delay(20);
   }

   }
   if(q<=180)
    {
    for(p;p<=q;p++)
   {
    servo_head.write(p);
    delay(20);
   }
    }
}

//机械臂转向右90°
void switchright()
{
    int p = servo_head.read();
    int q = p-90;
    if(q<0)
   {
    for(p;p>=0;p--)
   {
    servo_head.write(p);
    delay(20);
   }

   }
   if(q>=0)
    {
    for(p;p>=q;p--)
   {
    servo_head.write(p);
    delay(20);
   }
    }
}


void setup() {
  IniMotor();
  iniServo();
  Serial.begin(9600);

}

void loop() {

 if(Serial.available())
 {
    x = Serial.read();
    switch(x)
    {
       //motor_control
       case'a':goLine();Serial.println("go staight!");break;
       case 'b':stopp();Serial.println("stop!");break;
       case 'c':turnLeft();Serial.println("turn left!");break;
       case 'd':turnRight();Serial.println("turn right!");break;
       //servo_control
       case 'e' :handup();Serial.println("hand up!");break;
       case 'f' :handback();Serial.println("hand back!");break;
       case 'g':clawopen();Serial.println("claw open!");break;
       case 'h':clawoff();Serial.println("claw off!");break;
       case 'i':switchleft();Serial.println("servo switch left!");break;
       case 'j': switchright();Serial.println("servo switch right");break;
    }
 }
}
