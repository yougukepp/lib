#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from socket import *

#host = '192.168.4.2'
#host = '127.0.0.1'
host = ''
port = 8001
bufSize = 1024

addr = (host, port)

udpSerSock = socket(AF_INET, SOCK_DGRAM)
udpSerSock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
udpSerSock.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)
udpSerSock.bind(addr)

print('wating for message...')

while True:
  (recvData, clientAddr) = udpSerSock.recvfrom(bufSize)
  print(clientAddr)
  print(recvData)

udpSerSock.close()


