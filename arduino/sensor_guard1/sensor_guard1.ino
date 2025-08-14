#include <DHT.h>

// ------------ Pinos ------------
const int mq2 = A0;
const int mq7 = A1;
const int dhtPin = A2;
const int statusOn = 2;
const int statusAlerta = 3;

DHT dht(dhtPin, DHT22);

// ------------ Estado simples ------------
bool sistemaOn = false;   // OFF no início
bool modoDebug = false; 

// ------------ Variáveis de leitura ------------
int   mq2_adc = 0;
int   mq7_adc = 0;
float tempC   = 0.0;
float umid    = 0.0;
bool  dhtOk   = false;

// ------------ Declaração de funções ------------
void setupHardware();
void esperarHandshake();
void processarComando(String cmd);
void lerSensores();
void imprimirLeituras();
void debug(String msg);

void setup() {
  setupHardware();
  debug("Iniciando comunicação");
  esperarHandshake();   // fica aqui até receber "STATUS"
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    cmd.toUpperCase();
    processarComando(cmd);
  }
}

// ------------ Implementações ------------
void setupHardware() {
  pinMode(mq2, INPUT);
  pinMode(mq7, INPUT);
  pinMode(statusOn, OUTPUT);
  pinMode(statusAlerta, OUTPUT);

  digitalWrite(statusOn, LOW);
  digitalWrite(statusAlerta, HIGH);

  Serial.begin(115200);
  dht.begin();
  delay(100);
}

void esperarHandshake() {
  // Só libera quando chegar "STATUS".
  while (!sistemaOn) {
    if (Serial.available() > 0) {
      String cmd = Serial.readStringUntil('\n');
      cmd.trim();
      cmd.toUpperCase();

      if (cmd == "PING") {
        Serial.println("PONG");
      } else if (cmd == "INICIAR") {
        Serial.println("ARDUINO_PRONTO");  // primeira linha útil
        sistemaOn = true;
        digitalWrite(statusAlerta, LOW);
        digitalWrite(statusOn, HIGH);
        debug("ON");
      }
    }
  }
}

void processarComando(String cmd) {
  if (cmd == "PING") {
    Serial.println("PONG");
    return;
  }

  if (!sistemaOn) return;

  if (cmd == "LER") {
    debug("Lendo Sensores ...");
    lerSensores();
    imprimirLeituras();
  }

  else if (cmd == "DEBUG_ON"){
    if (modoDebug){
      Serial.println("[DEBUG] Modo debug já está ativado");
    }else{
      modoDebug = true;
      Serial.println("[DEBUG] Modo debug ativado");
    }
  }

  else if (cmd == "DEBUG_OFF") {
  if (!modoDebug) {
    Serial.println("[DEBUG] Modo debug já está desativado"); // <- Mensagem direta
  } else {
    modoDebug = false;
    Serial.println("[DEBUG] Modo debug desativado"); // <- Mensagem direta
  }
}
}

void lerSensores() {
  mq2_adc = analogRead(mq2);
  mq7_adc = analogRead(mq7);

  tempC = dht.readTemperature();
  umid  = dht.readHumidity();
  dhtOk = !(isnan(tempC) || isnan(umid));

  delay(5);
}

void imprimirLeituras() {
  Serial.print("MQ2;adc=");  Serial.println(mq2_adc);
  Serial.print("MQ7;adc=");  Serial.println(mq7_adc);

  if (dhtOk) {
    Serial.print("TEMP;value="); Serial.print(tempC); Serial.println(";unit=C");
    Serial.print("UMID;value="); Serial.print(umid);  Serial.println(";unit=%");
    debug("OK");
  } else {
    Serial.println("TEMP;error=nan");
    Serial.println("UMID;error=nan");
    debug("DHT NaN");
  }
}

void debug(String msg){
  if(modoDebug){
    Serial.print("[DEBUG] ");
    Serial.println(msg);
  }
}