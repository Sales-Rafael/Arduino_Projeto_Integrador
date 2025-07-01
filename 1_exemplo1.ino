void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT); 
  //output: Saída
  //INPUT: Entrada
}

int tempo = 1000;

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12, HIGH);
  //HIGH: Alto ligado, 5v
  delay(tempo);
  digitalWrite(12, LOW);
  //LOW: Baixo, Desligado, 0v
  delay(tempo);
  tempo = tempo + 1000;
}
