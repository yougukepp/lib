#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from WifiPing import WifiPing

if __name__=='__main__':
    ipHead = '10.33.152.'
    for ipLast in range(1, 256):
        ip = ipHead + str(ipLast)
        rst = WifiPing(ip, 0.02)  # 20ms
        print(ip, end = '')
        print('   ', end = '')
        print(rst)


