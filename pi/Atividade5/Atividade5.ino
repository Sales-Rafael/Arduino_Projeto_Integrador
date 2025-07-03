#include <Servo.h>

#define pot A5
#define pinoServo 9

Servo s;
void setup() {
  pinMode(pot, INPUT);
  Serial.begin(9600);
  s.attach(pinoServo);
  s.write(0);
}

void loop() {
  int valorPot = analogRead(pot);
  Serial.println(valorPot);

  float angulo = (valorPot / 1023.0) * 180.0;
  Serial.println(angulo);

  s.write((int)angulo);
  delay(15);

}
