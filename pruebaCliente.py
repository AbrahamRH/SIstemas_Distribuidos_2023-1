from Socket import Socket

cliente = Socket()

cliente.sockConnect("",55000)

cliente.sockSend("Hola")

cliente.printSockInfo()

