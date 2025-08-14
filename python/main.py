from core.serial_link import SerialLink

def main():
    link = SerialLink()
    link.iniciar_arduino()

    while True:
        try:
            comando = input("> ").strip().upper()
            if not comando:
                continue

            if comando == "SAIR":
                print("Encerrando...")
                break

            link.enviar_comando(comando)

            respostas = link.ler_respostas()
            for linha in respostas:
                print(linha)

        except Exception as e:
            print(f"[ERRO] {e}")

if __name__ == "__main__":
    main()
