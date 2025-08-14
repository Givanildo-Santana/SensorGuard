#include "SensorAnalogico.h"
#include "SensorDigital.h"

// Instâncias dos sensores
SensorAnalogico mq2("MQ-2", A0, "ppm", 0.25);
SensorAnalogico mq7("MQ-7", A5, "ppm", 0.25);
SensorDigital dht22("DHT22", A2, "°C", "%");


  void setup() {
  Serial.begin(115200);
  while (!Serial);  // Aguarda a inicialização da porta (opcional)
  Serial.println("ARDUINO_PRONTO");
}



void loop() {
  mq2.ler();
  mq7.ler();
  dht22.ler();

  Serial.println("MQ2;" + String(mq2.getValorConvertido()) + ";ppm");
  Serial.println("MQ7;" + String(mq7.getValorConvertido()) + ";ppm");
  Serial.println("TEMP;" + String(dht22.getTemperatura()) + ";C");
  Serial.println("UMID;" + String(dht22.getUmidade()) + ";%");

  delay(1000);
}
