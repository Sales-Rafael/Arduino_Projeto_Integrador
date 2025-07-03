#include <SoftwareSerial.h>
#include <Servo.h>

Servo s;

SoftwareSerial bluetooth(10, 11);  // RX, TX

#define pinoServo 12
#define trigPin 9
#define echoPin 2
#define p2m2 8
#define p1m2 7
#define pvelm2 6
#define p2m1 5
#define p1m1 4
#define pvelm1 3

int vel;

class Motor {
public:
    int p1, p2, pv;

    Motor(int p1, int p2, int v) {
        this->p1 = p1;
        this->p2 = p2;
        this->pv = v;
        pinMode(p1, OUTPUT);
        pinMode(p2, OUTPUT);
        pinMode(pv, OUTPUT);
        digitalWrite(p1, LOW);
        digitalWrite(p2, LOW);
        analogWrite(pv, 0);
    }

    void frente(int v) {
        digitalWrite(p1, HIGH);
        digitalWrite(p2, LOW);
        analogWrite(pv, v);
    }

    void tras(int v) {
        digitalWrite(p1, LOW);
        digitalWrite(p2, HIGH);
        analogWrite(pv, v);
    }

    void para() {
        digitalWrite(p1, LOW);
        digitalWrite(p2, LOW);
        analogWrite(pv, 0);
    }

    void freia() {
        digitalWrite(p1, HIGH);
        digitalWrite(p2, HIGH);
        analogWrite(pv, 255);
    }
};

Motor *md = new Motor(p1m1, p2m1, pvelm1);
Motor *me = new Motor(p1m2, p2m2, pvelm2);



void virarEsquerda(int v) {
    md->frente(v);
    me->tras(v);
}

void virarDireita(int v) {
    md->tras(v);
    me->frente(v);
}

void irFrente(int v) {
    md->frente(v);
    me->frente(v);
}

void irTras(int v) {
    md->tras(v);
    me->tras(v);
}

void parar() {
    md->para();
    me->para();
}

void freiar() {
    md->freia();
    me->freia();
}

void setup() {
    vel = 200;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);           
    bluetooth.begin(9600);
    s.attach(pinoServo);
    s.write(0);     
}

void rotaSimples1(){
  frenteLongo();
  direita90graus();
  frenteCurto();
  esquerda90graus();
  frenteLongo();
  esquerda90graus();
  frenteCurto();
  direita90graus();
}

void rotaSimples2(){
  md->frente(vel*4);
  me->frente(vel);
  delay(5000);
  parar();
  delay(500);
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
  frenteCurto();
  direita360graus();
  frenteCurto();
  direita90graus();
  frenteCurto();
  direita360graus();
  frenteCurto();
  esquerda90graus();
  frenteCurto();
  esquerda360graus();
  frenteCurto();
  esquerda90graus();
}

void rotaSimples5(){
  frenteCurto();
  frenteCurto();
  frenteCurto();
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

void loop() {
  long duration;
  int distance;

  // Servo vai de 0° a 180°
  for (int grau = 0; grau <= 180; grau += 30) {
    s.write(grau);
    Serial.print("Servo em: ");
    Serial.print(grau);
    Serial.println(" graus");

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.032 / 2;
    
    Serial.print("  Distância: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(1000);
    if (distance < 20) {
        esquerda90graus();
        Serial.println("funcionou");
    }
  }
  

  // Servo volta de 180° a 0°
  for (int grau = 180; grau >= 0; grau -= 30) {
    s.write(grau);
    Serial.print("Servo voltando para: ");
    Serial.print(grau);
    Serial.println(" graus");

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.032 / 2;

    Serial.print("  Distância: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(1000);

    if (distance < 20) {
        esquerda90graus();
        Serial.println("funcionou");
    }
  }

  // Comandos via Bluetooth
  if (bluetooth.available()) {
    char comando = bluetooth.read();

    if (comando == 'F') {
      irFrente(vel);
      bluetooth.println("Frente");

    } else if (comando == 'B') {
      irTras(vel);
      bluetooth.println("Ré");

    } else if (comando == 'L') {
      virarEsquerda(vel);
      bluetooth.println("Esquerda");

    } else if (comando == 'R') {
      virarDireita(vel);
      bluetooth.println("Direita");

    } else if (comando == 'S') {
      parar();
      bluetooth.println("Parado");

    } else if (comando == 'X') {
      freiar();
      bluetooth.println("Freio");

    } else if (comando == '1') {
      rotaSimples1();
      bluetooth.println("Rota1");

    } else if (comando == '2') {
      rotaSimples2();
      bluetooth.println("Rota2");

    } else if (comando == '3') {
      rotaSimples3();
      bluetooth.println("Rota3");

    } else if (comando == '4') {
      rotaSimples4();
      bluetooth.println("Rota4");

    } else if (comando == '5') {
      rotaSimples5();
      bluetooth.println("Rota5");

      }
    }
}