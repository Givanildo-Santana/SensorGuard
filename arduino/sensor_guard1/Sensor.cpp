#include "Sensor.h"

Sensor::Sensor(String nome, int pino, String unidade)
  : nome(nome), pino(pino), unidade(unidade) {}

String Sensor::getNome() { return nome; }
int Sensor::getPino() { return pino; }
String Sensor::getUnidade() { return unidade; }
