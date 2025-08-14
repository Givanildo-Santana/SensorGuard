#include "SensorAnalogico.h"

    SensorAnalogico::SensorAnalogico(String nome, int pino, String unidade, float multiplicador)
    : Sensor(nome, pino, unidade){
      this->multiplicador = multiplicador;
      this->valorBruto = 0;
    }

    void SensorAnalogico::ler(){
      valorBruto = analogRead(getPino());
    }

    int SensorAnalogico::getValorBruto(){
      return valorBruto;
    }

    float SensorAnalogico:: getValorConvertido(){
      return valorBruto * multiplicador;
    }

