void setup() {
  pinMode(13,OUTPUT); //vermelho
  pinMode(12,OUTPUT); //amarelo
  pinMode(11,OUTPUT); // verde

}

int tempoAmarelo  = 1000;
int tempoVermelho = 2000;
int tempoVerde = 4000;
void loop() {
  digitalWrite(13,HIGH);
  delay(tempoVermelho);
  digitalWrite(13,LOW);
  delay(true);
  digitalWrite(12,HIGH);
  delay(tempoAmarelo);
  digitalWrite(12,LOW);
  delay(true);
  digitalWrite(11,HIGH);
  delay(tempoVerde);
  digitalWrite(11,LOW);
  delay(true);
}
