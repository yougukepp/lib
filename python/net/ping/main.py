#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from WifiPing import IpPool

if __name__=='__main__':
    ipPool = IpPool()

    ipHead = '10.33.152.'
    for ipLast in range(1, 30):
        ip = ipHead + str(ipLast)
        ipPool.AddIp(ip)

    ipPool.Ping(1) # 1s超时

