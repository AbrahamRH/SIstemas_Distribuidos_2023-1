##
# @file nodo.py
# @brief Implementación de la clase del servidor maestro
# @author AbrahamRH, Fernanda
# @version 1
# @date 2022-11-16

from Socket import Socket
import random

class Maestro:
    def __init__(self, host, port):
        self.chunkIndex = 0
        self.namespace = {}  # [ind] = (handler, ubicación)
        self.socket = Socket()
        self.socket.sockBind(host, port)
        self.socket.sockAccept()

    def __del__(self):
        self.socket.sockClose()

    def listenRequests(self):
        return self.socket.sockRecv()

    def addFile(self, file):
        self.namespace[self.chunkIndex] = (random.randint(1,1000000),"/ruta/" + file)
        self.chunkIndex = self.chunkIndex + 1

    def getChunkInfo(self, index):
        return self.namespace[index]

    def processData(self, data):
        name, index = data.split(",")
        chunk = self.getChunkInfo(int(index))
        if name in chunk[1].split("/"):
            return chunk

    def giveData(self, chunkInfo):
        handler, route = chunkInfo
        client = self.socket.getNewSocket()
        self.socket.sockSend(str(handler), client[0])
        self.socket.sockSend(",", client[0])
        self.socket.sockSend(route, client[0])
