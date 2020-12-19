int E1 = 5; //PWMA
int M1 = 9; //PWMA
int E2 = 6; //PWMB
int M2 = 10; //PWMB
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
digitalWrite(M1, LOW);
digitalWrite(E1, HIGH); //the speed value of motorA is 150
digitalWrite(M2, LOW);
digitalWrite(E2, HIGH); //the speed value of motorB is 150
delay(5000);
//******** ******************************//forward
digitalWrite(M1, LOW);
digitalWrite(E1, LOW); //the speed value of motorA is 0
digitalWrite(M2, LOW);
digitalWrite(E2, LOW); //the speed value of motorB is 0
delay(1000);//********************************************//stop
digitalWrite(M1, HIGH);//the speed value of motorA is 150
digitalWrite(E1, LOW);
digitalWrite(M2, HIGH);//the speed value of motorA is 150
digitalWrite(E2, LOW);
delay(5000);//*********************************************//back
}
