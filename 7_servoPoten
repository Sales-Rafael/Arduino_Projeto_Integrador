#include <Servo.h> 
#define pot A5
#define pinoServo 9 
 
Servo s; 
 
void setup (){
  pinMode(pot, INPUT);
  Serial.begin(9600);
  s.attach(pinoServo); 
  s.write(0); 
}
void loop(){
  
   int valorPot = analogRead(pot); // 0 a 1023
   Serial.println(valorPot);

  // Converte manualmente para ângulo (0 a 180 graus)
  float angulo = (valorPot / 1023.0) * 180.0;
  Serial.println(angulo);

  s.write((int)angulo); // Move o servo para o ângulo correspondente

  delay(15); // Tempo para o servo reagir
}
