from ServidorMaestro import Maestro
ADDR = "192.168.100.1"
PORT = 65000
SERVER = (ADDR,PORT)

if __name__ == "__main__":
    servidor = Maestro(ADDR,PORT)
    servidor.addFile("pedidos.txt")
    try: 
        print(f"[SERVIDOR ESCUCHANDO] {SERVER} ")
        while True:
            d = servidor.listenRequests()
            if d is not None:
                servidor.giveData(servidor.processData(d))
            else:
                pass
    except KeyboardInterrupt as e:
        print("Apagando servidor.")

    print("")
    print("="*50)
    print("Información de la conexión")
    print("="*50)
    servidor.socket.printSockInfo()
