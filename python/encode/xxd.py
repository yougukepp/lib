#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

gCountPerRow = 10

if __name__ == '__main__': 
    if 2 != len(sys.argv):
        print("使用方法: PrintWithBin.py 待处理文件")
        exit()

    fIn = open(sys.argv[1], mode = "rb")
    fOut = open(sys.argv[1] + ".bin", mode = "w")

    buf = fIn.read()

    count = 0
    for c in buf:
        fOut.write("0x%02X" % c)
        count += 1
        if count > gCountPerRow:
            fOut.write("\n")
            count = 0
        else:
            fOut.write(",")


    fIn.close()
    fOut.close()
