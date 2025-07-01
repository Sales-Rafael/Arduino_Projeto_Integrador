#define an5 A5
#define buzzer 9
void setup() {
  pinMode(an5, INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}


void loop() {
  Serial.println(analogRead(an5));
  int valor = analogRead(an5);
   // Frequência mínima = 200 Hz, máxima = 2000 Hz
  float frequencia = 200 + (valor / 1023.0) * (2000 - 200);


  tone(buzzer, (int)frequencia); // Converte para inteiro e envia ao buzzer
  Serial.println(frequencia);
  analogWrite(buzzer, frequencia);  
 
  delay(1000);
}
