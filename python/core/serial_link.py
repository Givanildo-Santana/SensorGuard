import serial
import time
from dependencias import config

class SerialLink:
    def __init__(self):
        try:
            self.conexao = serial.Serial(config.porta, config.baudrate, timeout=config.timeout)
            time.sleep(2)
            self.conexao.reset_input_buffer()
            print(f"✅ Conectado em {self.conexao.port}")
        except Exception as e:
            print(f"[ERRO] Falha ao conectar na porta {config.porta}: {e}")
            raise

    def iniciar_arduino(self):
        print("Enviando comando INICIAR...")
        self.conexao.write(b"INICIAR\n")

        while True:
            if self.conexao.in_waiting > 0:
                resposta = self.conexao.readline().decode("utf-8", "ignore").strip()
                if resposta == "ARDUINO_PRONTO":
                    print("🚀 Arduino pronto para receber comandos!")
                    break
                else:
                    print("[INFO]", resposta)

    def enviar_comando(self, comando: str):
        self.conexao.write((comando + "\n").encode())

    def ler_respostas(self, delay=0.1):
        time.sleep(delay)
        respostas = []
        while self.conexao.in_waiting > 0:
            resposta = self.conexao.readline().decode("utf-8", "ignore").strip()
            if resposta:
                respostas.append(resposta)
        return respostas
