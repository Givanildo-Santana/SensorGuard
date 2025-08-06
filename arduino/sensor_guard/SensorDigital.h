#ifndef SENSOR_DIGITAL_H
#define SENSOR_DIGITAL_H

#include <DHT.h>         
#include "Sensor.h"

#define DHTTYPE DHT22    
class SensorDigital : public Sensor {
  private: 
    float temperatura;
    float umidade;
    DHT dht;             

  public:
    SensorDigital(String nome, int pino, String unidade1, String unidade2);
    void ler() override;
    float getTemperatura();
    float getUmidade();
};

#endif
