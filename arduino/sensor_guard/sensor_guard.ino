#include "SensorAnalogico.h"
#include "SensorDigital.h"

// Instâncias dos sensores
SensorAnalogico mq2("MQ-2", A0, "ppm", 0.25);
SensorAnalogico mq7("MQ-7", A5, "ppm", 0.25);
SensorDigital dht22("DHT22", A2, "°C", "%");

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Ler sensores analógicos
  mq2.ler();
  mq7.ler();

  // Ler sensor digital
  dht22.ler();

  // Exibir dados do MQ-2
  Serial.print("Sensor: ");
  Serial.print(mq2.getNome());
  Serial.print(" | Bruto: ");
  Serial.print(mq2.getValorBruto());
  Serial.print(" | Convertido: ");
  Serial.print(mq2.getValorConvertido());
  Serial.print(" ");
  Serial.println(mq2.getUnidade());
  Serial.println();

  delay(1000);

  // Exibir dados do MQ-7
  Serial.print("Sensor: ");
  Serial.print(mq7.getNome());
  Serial.print(" | Bruto: ");
  Serial.print(mq7.getValorBruto());
  Serial.print(" | Convertido: ");
  Serial.print(mq7.getValorConvertido());
  Serial.print(" ");
  Serial.println(mq7.getUnidade());
  Serial.println();

  delay(1000);

  // Exibir dados do DHT22
  Serial.print("Sensor: ");
  Serial.print(dht22.getNome());
  Serial.print(" | Temperatura: ");
  Serial.print(dht22.getTemperatura());
  Serial.print(" ");
  Serial.print(" | Umidade: ");
  Serial.print(dht22.getUmidade());
  Serial.println(" ");
  Serial.println();

  delay(1000);
}
