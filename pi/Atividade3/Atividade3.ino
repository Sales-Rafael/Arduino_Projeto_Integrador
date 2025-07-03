#define buzzer 10
void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer, 349); //fá
  delay(500);
  noTone(buzzer);

  tone(buzzer, 528); //dó
  delay(500);
  noTone(buzzer);
}
