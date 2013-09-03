#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import struct

if __name__ == '__main__': 
    if 2 != len(sys.argv):
        print("使用方法: Gbk2Utf8.py 待处理文件")
        exit()

    fIn = open(sys.argv[1], mode = "rt", encoding="gbk")
    fOut = open(sys.argv[1] + ".utf8", mode = "wb") 
    
    # 为了兼容部分软件识别 utf8 加入 BOM
    fOut.write(b"\xEF\xBB\xBF")

    while True:
        lineGbk = fIn.readline()
        if not lineGbk:
            break 

        lineUtf8 = lineGbk.encode("utf8")
        #print(lineUtf8);
        fOut.write(lineUtf8)

    fIn.close()
    fOut.close()
