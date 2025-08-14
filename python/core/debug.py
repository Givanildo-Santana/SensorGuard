import threading
import time
import keyboard

class DebugMonitor:
    def __init__(self, serial_link):
        self.link = serial_link
        self.ativo = False
        self.thread = None
        self.modo = None
        self._parar = False

    def iniciar(self, modo: str):
        if self.ativo:
            print("[DEBUG] Modo de debug já está ativo")
            return

        self.modo = modo.lower()
        self._parar = False
        self.ativo = True
        self.thread = threading.Thread(target=self._loop_debug, daemon=True)
        self.thread.start()
        print(f"\U0001F527 Modo de debug iniciado: {modo.upper()} (pressione 'q' para sair)")

    def _loop_debug(self):
        while not self._parar:
            if self.link.conexao.in_waiting > 0:
                try:
                    linha = self.link.conexao.readline().decode("utf-8", "ignore").strip()

                    if self.modo in ["arduino", "todos"] and any(chave in linha.lower() for chave in ["mq2", "mq7", "temp", "umid"]):
                        print(f"[ARDUINO] {linha}")

                except Exception as e:
                    print(f"[ERRO] Falha ao ler do Arduino: {e}")

            if keyboard.is_pressed('q'):
                self.parar()
                print("\u274C Debug desligado")
                break

            time.sleep(0.01)

    def parar(self):
        self._parar = True
        self.ativo = False
        self.modo = None
        self.thread = None

    def esta_ativo(self):
        return self.ativo

    def finalizar_leitura_antes_de_parar(self):
        if self.ativo:
            self._parar = True
            self.thread.join()
            self.ativo = False
            self.thread = None
            self.modo = None
