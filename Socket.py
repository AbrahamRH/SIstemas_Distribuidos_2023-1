#! /usr/bin/env python3

##
# @file nodo.py
# @brief Implementación de las clases  para los servidores
# @author AbrahamRH, Fernanda
# @version 1
# @date 2022-11-16

import socket
import socketserver

class Socket: 
    s_id = 0
    def __init__(self, sock = None):
        self.info = [] #Lista con la información del socket
        self.info.append("Socket id: " + str(self.s_id))
        self.conn = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        self.s_id = self.s_id + 1
        if sock is None:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        else:
            self.sock = sock

    def sockConnect(self, host, port):
        self.sock.connect((host,port))
        self.info.append("conexión en: " + str(host) + " " + str(port))

    def sockBind(self, host, port):
        self.sock.bind((host,port))
        self.sock.listen(1)
        self.info.append("Socket en escucha en el puerto: " + str(port))
        self.info.append("Socket en escucha con el host: " + host)

    def sockAccept(self):
        tup = tuple()
        tup = self.sock.accept()
        self.conn = tup[0]
        self.info.append("Socket aceptando peticiones en: " + repr(tup))

    def sockSend(self,msg):
        self.sock.sendall(bytes(msg,'utf-8'))
        self.info.append("Realizando envio de  mensaje: " + str(msg))

    def sockRecv(self):
        datos = self.conn.recv(1024)
        if not datos: return
        self.info.append("Socket recibiendo datos: " + repr(datos))
        return datos

    def printSockInfo(self):
        for i in self.info:
            print(i)
