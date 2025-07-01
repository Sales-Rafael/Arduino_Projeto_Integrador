#define buzzer 10
void setup(){
  pinMode(buzzer, OUTPUT);
}

void loop(){
  tone(buzzer,200);
  delay(2000);
  noTone(buzzer);

  delay(1000);
}
