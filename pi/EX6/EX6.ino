#include <HCSR04.h>

#define trigPin 9
#define echoPin 10 // 2
#define ledPin 6
#define buzzerPin 7

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.032 / 2;
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 10){
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 10000);
  } else{
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    
  }

delay(500);

}
