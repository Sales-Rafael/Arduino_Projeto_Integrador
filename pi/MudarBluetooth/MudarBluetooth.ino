#include <SoftwareSerial.h>

SoftwareSerial BT(10,11);

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Digite comandos AT: ");
}

void loop() {
  if (Serial.available()) {
    BT.write(Serial.read());
  }

  if (BT.available()) {
    Serial.write(BT.read());
  }

}




// codigo

void rotaSimples1(){
  frenteLongo();
  direta90graus();
  frenteCurto();
  esquerda90graus();
  frenteLongo();
  esquerda90graus();
  frenteCurto();
  direita90graus();
}

void rotaSimples2(){
  esquerda22graus();
}

void rotaSimples3(){
  direita45graus();
  direita45graus();
  frenteCurto();
  esquerda45graus();
  esquerda45graus();
  frenteCurto();
}

void rotaSimples4(){
  frenteCurto();/
  direita360graus();/
  frenteCurto();/
  direita90graus();/
  frenteCurto();/
  direita360graus();/
  frenteCurto();/
  esquerda90graus();/
  frenteCurto();/
  esquerda360graus();
  frenteCurto();
  esquerda90graus();
}

void frenteLongo(){
  irFrente(vel);
  delay(1000);
  parar();
  delay(500);
}

void frenteCurto(){
  irFrente(vel);
  delay(500);
  parar();
  delay(500);
}

void direita90graus(){
  virarDireita(vel);
  delay(500);
  parar();
  delay(500);
}

void direita360graus(){
  virarDireita(vel);
  delay(1000);
  parar();
  delay(500);
}

void esquerda90graus(){
  virarEsquerda(vel);
  delay(500);
  parar();
  delay(500);
}

void esquerda360graus(){
  virarEsquerda(vel);
  delay(1000);
  parar();
  delay(500);
}
void direita45graus(){
  virarDireita(vel);
  delay(250);
  parar();
  delay(500);
}
void direita22graus(){
  virarDireita(vel);
  delay(125);
  parar();
  delay(500);
}
void esquerda45graus(){
  virarEsquerda(vel);
  delay(250);
  parar();
  delay(500);
}

void esquerda22graus(){
  virarEsquerda(vel);
  delay(125);
  parar();
  delay(500);
}