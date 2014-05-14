#!/usr/bin/env python

from socket import *

recvHost = '127.0.0.1'
#recvHost = '192.168.1.101'
recvPort = 8001
recvAddr = (recvHost, recvPort)

sendData = b'\00\01\02'

udpSendSocket = socket(AF_INET, SOCK_DGRAM)

udpSendSocket.sendto(sendData, recvAddr)

udpSendSocket.close()

