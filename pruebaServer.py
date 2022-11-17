from Socket import Socket

Servidor = Socket()

Servidor.sockBind("",55000)
Servidor.sockAccept()

while True:
    data = Servidor.sockRecv()
    if data is not None:
        p = data
    else: 
        break

print(repr(p))
Servidor.printSockInfo()

