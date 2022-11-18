from Cliente import Cliente

ADDR = "192.168.100.1"
PORT = 65000
SERVER = (ADDR,PORT)

if __name__ == "__main__":
    cliente = Cliente()
    cliente.requestConnection(ADDR,PORT)
    cliente.requestChunkInfo("pedidos.txt",0)
    print("")
    print("="*50)
    print("Información de la conexión")
    print("="*50)
    cliente.socket.printSockInfo()

