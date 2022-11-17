from Socket import Socket

class Cliente:
    def __init__(self):
        self.con = Socket()
        self.cache = [] # chunk handle / chunk location
        self.data = ""

    def requestConnection(self,host, port):
        self.con.sockConnect(host, port)

    def requestChunkInfo(self, filename, chunkIndex):
        self.con.sockSend(filename)
        self.con.sockSend(",")
        self.con.sockSend(str(chunkIndex))
        test = self.con.sockRecv()
        return test

if __name__ == "__main__":
    cliente = Cliente()
    cliente.requestConnection("",65000)
    cliente.requestChunkInfo("pedidos.txt",0)

    print("")
    print("="*50)
    print("Información de la conexión")
    print("="*50)
    cliente.con.printSockInfo()

