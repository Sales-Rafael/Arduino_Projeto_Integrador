#include <DHT.h>

#define DHTPIN 2        // Pino conectado ao DHT11
#define DHTTYPE DHT11   // Tipo do sensor
#define LedVermelho 11
#define LedAzul 12

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
}

void loop() {
  delay(2000); // Espera entre leituras

  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature(); // Celsius por padrão

  
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print(" % | Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  if (temperatura >= 26.5) {
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedVermelho, LOW);
  } else {
    digitalWrite(LedAzul, LOW);
    digitalWrite(LedVermelho, HIGH);
  }
}
