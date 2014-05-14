#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from socket import *

#host = '192.168.1.100'
host = '127.0.0.1'
port = 8001
bufSize = 1024

addr = (host, port)

udpSerSock = socket(AF_INET, SOCK_DGRAM)
udpSerSock.bind(addr)

print('wating for message...')

while True:
  (recvData, clientAddr) = udpSerSock.recvfrom(bufSize)
  for c in recvData:
    print(c, end = '')
  print()

udpSerSock.close()

