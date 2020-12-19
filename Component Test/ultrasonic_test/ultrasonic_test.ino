const int TrigPin = 8; //发出超声波
const int EchoPin = 9; //收到反射回来的超声波
const int buzzer=10;//设置控制蜂鸣器的数字IO脚
float cm; //因为测得的距离是浮点型的
bool state = true;

void setup() 
{ 
  Serial.begin(9600); //设置波特率
  ////////////////////////////////////////超声模块
  pinMode(TrigPin, OUTPUT); 
  pinMode(EchoPin, INPUT); 
  ////////////////////////////////////////蜂鸣器模块
  pinMode(buzzer,OUTPUT);//设置数字IO脚模式，OUTPUT为输出
} 

void bee()
{
  digitalWrite(buzzer,LOW);//不发声音
  delay(500);//延时1ms
  digitalWrite(buzzer,HIGH);//发声音
  delay(200);//延时m
}

void ultrawave()
{
  digitalWrite(TrigPin, LOW); //低电平发一个短时间脉冲去TrigPin 
  delayMicroseconds(2);       // delayMicroseconds在更小的时间内延时准确
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW); //通过这里控制超声波的发射
  cm = pulseIn(EchoPin, HIGH) / 58.0; //将回波时间换算成cm 
  Serial.println(cm);
  if(cm<10)
  {
    if(state)
    Serial.println("bee");
    bee();
  }
  delay(1000); 
}

void loop() 
{ 
  ultrawave();
}

