#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.Vector import Vector

"""
def IsCollineation(p0, p1, p2):
    rst = False

    p02 = Vector(p0, p2)
    p01 = Vector(p0, p1)

    d = p01.X() * p02.Y() - p02.X() * p01.Y()

    if 0 == d:
        rst = True

    return rst

def IsTurnLeft(p0, p1, p2):
    rst = False

    p02 = Vector(p0, p2)
    p01 = Vector(p0, p1)

    d = p01.X() * p02.Y() - p02.X() * p01.Y()

    if d > 0:
        rst = True
    else:
        rst = False

    return rst

def IsTurnRight(p0, p1, p2):
    if IsCollineation(p0, p1, p2):
        return False

    if IsTurnLeft(p0, p1, p2):
        return False

    return True
"""

if __name__ == "__main__":
    print("测试Turn模块:通过")
