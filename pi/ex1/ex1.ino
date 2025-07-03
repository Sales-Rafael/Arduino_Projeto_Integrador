void setup() {
  pinMode(13,OUTPUT);

}

int tempo = 0;

void loop() {
  tempo = tempo + 5000;
  digitalWrite(13,HIGH);
  delay(tempo);
  digitalWrite(13,LOW);
  delay(tempo);

}
