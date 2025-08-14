class SensorReader:
    def __init__(self):
        self._dados = {}
        self._ultimo_comando = ""

    def marcar_comando(self, comando):
        self._ultimo_comando = comando

    def comando_foi_ler(self):
        return self._ultimo_comando in ["LER", "LER_ARDUINO"]

    def processar_linha(self, linha):
        # seu código de parsing atual
        pass

    def obter_valor(self, sensor):
        return self._dados.get(sensor)
