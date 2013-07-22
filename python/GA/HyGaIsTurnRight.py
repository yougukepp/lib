#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from HyGaVector import *

def HyGaIsTurnRight(p0, p1, p2):
    rst = False

    p02 = HyGaVector(p0, p2)
    p01 = HyGaVector(p0, p1)

    d = p01.X() * p02.Y() - p02.X() * p01.Y()

    #p0.print()
    #p1.print()
    #p2.print()

    #p01.print()
    #print(" 到 ", end = "")
    #p02.print()

    if d > 0:
        #print(" 左转 ")
        rst = True
    else:
        #print(" 非左转 ")
        rst = False

    return rst

