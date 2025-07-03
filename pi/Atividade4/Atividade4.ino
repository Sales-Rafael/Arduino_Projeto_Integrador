#include <Servo.h>

#define buzzer 10
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(2,OUTPUT); //vermelho
  pinMode(3,OUTPUT); //amarelo
}

int tempoAmarelo  = 100;
int tempoVermelho = 100;

void loop() {

  digitalWrite(2,HIGH);
  delay(tempoVermelho);
  digitalWrite(2,LOW);
  delay(true);

  tone(buzzer, 349); //fá
  delay(100);
  noTone(buzzer);

  digitalWrite(3,HIGH);
  delay(tempoAmarelo);
  digitalWrite(3,LOW);
  delay(true);

  tone(buzzer, 528); //dó
  delay(100);
  noTone(buzzer);
}
