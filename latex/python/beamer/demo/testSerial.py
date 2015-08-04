#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import serial

gData = b"hello\x7e\x16"

def test(timeOut, recvBufSize):
    ser = serial.Serial(0)
    ser.timeout = timeOut
    print("use com port:", ser.portstr)

    w = ser.write(gData)
    r = ser.read(recvBufSize)
    print(r)
    ser.close()

if __name__ == "__main__":
    recvBufSize = 2048
    timeOut = 1
    test(timeOut, recvBufSize)

