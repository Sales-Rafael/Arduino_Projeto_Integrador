void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); 
  //output: Saída
  //INPUT: Entrada
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  //HIGH: Alto ligado, 5v
  delay(2000);
  digitalWrite(13, LOW);
  //LOW: Baixo, Desligado, 0v
  delay(2000);
}
