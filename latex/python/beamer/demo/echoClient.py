#!/usr/bin/env python3
# -- coding utf-8 -- 

import socket

gHost = '127.0.0.1'
gPort = 50007

if "__main__" == __name__:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((gHost, gPort))
    s.sendall(b'Hello, world')
    data = s.recv(1024)
    s.close()
    print('Received', repr(data))
