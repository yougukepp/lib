#!/usr/bin/env python3
# -- coding utf-8 -- 

import socket

gHost = ''
gPort = 50007

if "__main__" == __name__:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((gHost, gPort))
    s.listen(1)
    conn, addr = s.accept()
    
    print('Connected by', addr)
    while True:
        data = conn.recv(1024)
        if not data: break
        conn.sendall(data)
        print('Received', repr(data))

    conn.close()
