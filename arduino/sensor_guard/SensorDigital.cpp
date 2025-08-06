#include "SensorDigital.h"  // Inclui o cabeçalho da própria classe (onde estão as declarações)

// Construtor da classe SensorDigital
SensorDigital::SensorDigital(String nome, int pino, String unidade1, String unidade2)
  : Sensor(nome, pino, unidade1 + "/" + unidade2),  // Inicializa a classe base 'Sensor'
    dht(pino, DHTTYPE)  // Inicializa o objeto DHT com o pino e tipo DHT22
{
  temperatura = 0;  // Inicializa os atributos de leitura
  umidade = 0;
  dht.begin();      // Inicia a comunicação com o sensor DHT22
}

// Implementação do método ler()
// Lê temperatura e umidade do sensor
void SensorDigital::ler() {
  temperatura = dht.readTemperature();  // Lê temperatura em °C
  umidade = dht.readHumidity();         // Lê umidade relativa do ar
}

// Retorna a última temperatura lida
float SensorDigital::getTemperatura() {
  return temperatura;
}

// Retorna a última umidade lida
float SensorDigital::getUmidade() {
  return umidade;
}
