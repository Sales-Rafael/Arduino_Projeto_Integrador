void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(10, OUTPUT); 
  //output: Saída
  //INPUT: Entrada
}

void loop() {
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(4000);
  digitalWrite(10, LOW);
}
