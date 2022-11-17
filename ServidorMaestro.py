from Socket import Socket

class Maestro:
    def __init__(self, host, port):
        self.con = Socket()
        self.namespace = {} 
        self.con.sockBind(host, port)
        self.con.sockAccept()

    def listenRequests(self):
        data = self.con.sockRecv()
        if data is not None: 
            return data


if __name__ == "__main__":
    servidor = Maestro("", 44000)
    while True:
        d = servidor.listenRequests()
        if d is not None:
            p = d
        else:
            break

    print(repr(p))
    servidor.con.printSockInfo()



