#define  pin   7    // char pin=7;
void setup(){
  pinMode(pin, OUTPUT);
  noTone(pin);
}

 void loop(){
       tone(pin, 350); delay(800);     //3 E
       tone(pin, 294); delay(800);   //1 D
       tone(pin, 350); delay(400);    //3(0.5)E
       tone(pin, 350); delay(400);   //3(0.5) E
       tone(pin, 147); delay(800);  //1 C
}

