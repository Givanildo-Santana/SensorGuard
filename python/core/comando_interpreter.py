class InterpretadorComandos:
    def __init__(self, serial_link, debug_monitor):
        self.link = serial_link
        self.monitor = debug_monitor

    def executar(self, comando: str):
        comando = comando.strip().upper()
        if not comando:
            return

        if comando == "SAIR":
            print("Encerrando conexão...")
            self.monitor.parar()
            exit(0)

        elif comando == "DEBUG_ON":
            self._ativar_debug()

        elif comando == "DEBUG_OFF":
            self.link.set_debug(False)
            self.monitor.finalizar_leitura_antes_de_parar()

        elif comando == "PING":
            self.link.conexao.write(b"PING\n")

        elif comando == "STATUS":
            self.link.conexao.write(b"STATUS\n")

        else:
            self.link.conexao.write((comando + "\n").encode())

    def _ativar_debug(self):
        print("\n[DEBUG] Qual modo deseja ativar?")
        print("  1 - debug_arduino")
        print("  2 - debug_py")
        print("  3 - debug_all")

        opcao = input("Digite o número da opção desejada: ").strip()

        if opcao == "1":
            self.link.set_debug(True)
            self.monitor.iniciar("arduino")

        elif opcao == "2":
            self.monitor.iniciar("python")

        elif opcao == "3":
            self.link.set_debug(True)
            self.monitor.iniciar("todos")

        else:
            print("❌ Opção inválida. Nenhum modo de debug foi iniciado.")
