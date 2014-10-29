#!/usr/bin/env python3

from socket import *

#recvHost = '127.0.0.1'
#recvHost = '255.255.255.255'
recvHost ='<broadcast>'
recvPort = 8001
recvAddr = (recvHost, recvPort)

sendData = b'\00\01\02'

udpSendSocket = socket(AF_INET, SOCK_DGRAM)
udpSendSocket.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)

udpSendSocket.sendto(sendData, recvAddr)

udpSendSocket.close()

