char comdata;

void setup()
 {
     Serial.begin(9600);
 }

void loop()
 {
  if(Serial.available())
 {
    comdata = Serial.read();
    Serial.println(comdata);
 }
 }
