#define trigPin 9
#define echoPin 10
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

  // Envia pulso de 10 microsegundos
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calcula a distância
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin,200);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(500);
}
