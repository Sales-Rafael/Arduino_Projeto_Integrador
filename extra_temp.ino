#include <DHT.h>

#define DHTPIN 2        // Pino conectado ao DHT11
#define DHTTYPE DHT11   // Tipo do sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
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
}
