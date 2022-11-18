##
# @file nodo.py
# @brief Implementación de la clase Cliente
# @author AbrahamRH, Fernanda
# @version 1
# @date 2022-11-16

from Socket import Socket

class Cliente:
    def __init__(self):
        self.socket = Socket()
        self.cache = [] # chunk handle / chunk location
        self.data = ""

    def __del__(self):
        self.socket.sockClose()

    def requestConnection(self,host, port):
        self.socket.sockConnect(host, port)

    def requestChunkInfo(self, filename, chunkIndex):
        self.socket.sockSend(filename)
        self.socket.sockSend(",")
        self.socket.sockSend(str(chunkIndex))
        chunk = self.socket.sockRecv()
        return  chunk
