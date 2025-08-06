# SensorGuard

🎯 Sistema embarcado de monitoramento ambiental com Arduino, sensores de gás e temperatura, comunicação em tempo real com Python e armazenamento em banco de dados.

---

## 📦 Visão Geral

O **SensorGuard** é um sistema de detecção e alerta que utiliza sensores analógicos e digitais para monitorar temperatura, umidade, gases inflamáveis (MQ-2) e monóxido de carbono (MQ-7). Os dados são enviados via serial para um software Python que:

- Armazena os dados em um banco de dados local
- Exibe informações em tempo real
- Analisa condições de risco
- Envia comandos ao Arduino para ativar atuadores

---

## 🧱 Componentes Utilizados

### 📟 Hardware
- Arduino UNO
- MQ-2 (gás/fumaça)
- MQ-7 (monóxido de carbono)
- DHT-22 (temperatura e umidade)
- Buzzer + LED vermelho (alerta)
- LED verde (status)
- Jumpers e resistores

### 💻 Software
- Arduino IDE
- Python 3
- SQLite (ou outro banco)
- Bibliotecas Python:
  - `pyserial`
  - `sqlite3`
  - `datetime`
  - (opcional) `matplotlib`, `dash`

---

## 🗂️ Estrutura do Projeto

