from ServidorMaestro import Maestro

ADDR = "192.168.100.1"
PORT = 65000
SERVER = (ADDR,PORT)

if __name__ == "__main__":
    servidor = Maestro(ADDR,PORT)
    servidor.addFile("pedidos.txt")
    print(f"[SERVIDOR ESCUCHANDO] {SERVER} ")

    try: 
        while True:
            d = servidor.listenRequests()
            if d is not None:
                servidor.giveData(servidor.processData(d))
            else:
                pass
    except KeyboardInterrupt as e:
        print("\n[SERVIDOR APAGADO]")
        servidor.socket.sockClose()

    print("")
    print("="*50)
    print("Información de la conexión")
    print("="*50)
    for log in servidor.socket.getInfo():
        print(log)


