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
        self.con.sockSend(chunkIndex)
        test = self.con.sockRecv()
        return test

if __name__ == "__main__":
    cliente = Cliente()
    cliente.requestConnection("",44000)
    cliente.requestChunkInfo("pedidos.txt",1)
    cliente.con.printSockInfo()

