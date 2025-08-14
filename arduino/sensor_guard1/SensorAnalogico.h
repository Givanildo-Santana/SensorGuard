#ifndef SENSOR_ANALOGICO_H 
#define SENSOR_ANALOGICO_H 

#include "Sensor.h"


class SensorAnalogico : public Sensor{
  private:
    int valorBruto;
    float multiplicador;


  public:
    SensorAnalogico(String nome, int pino, String unidade, float multiplicador);
    void ler() override;
    int getValorBruto();
    float getValorConvertido();
};

#endif