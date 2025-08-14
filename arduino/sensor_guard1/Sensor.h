#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
  protected:
    const String nome;
    const int pino;
    const String unidade;

  public:
    Sensor(String nome, int pino, String unidade);
    Sensor(String nome, int pino, String unidade1, String unidade2);
    String getNome();
    int getPino();
    String getUnidade();
    virtual void ler() = 0;

};

#endif
