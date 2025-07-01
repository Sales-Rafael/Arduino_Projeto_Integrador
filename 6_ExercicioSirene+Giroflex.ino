#define LedAzul 12
#define LedVermelho 11
#define buzzer 10

void setup() {
  pinMode(LedAzul, OUTPUT); 
  pinMode(LedVermelho, OUTPUT); 
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(12, HIGH);
  tone(buzzer, 650);
  delay(0500);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  tone(buzzer, 1000);
  delay(0500);
}

