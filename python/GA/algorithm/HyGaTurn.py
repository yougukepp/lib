#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.HyGaVector import HyGaVector

def HyGaIsCollineation(p0, p1, p2):
    rst = False

    p02 = HyGaVector(p0, p2)
    p01 = HyGaVector(p0, p1)

    d = p01.X() * p02.Y() - p02.X() * p01.Y()

    if 0 == d:
        rst = True

    return rst

def HyGaIsTurnLeft(p0, p1, p2):
    rst = False

    p02 = HyGaVector(p0, p2)
    p01 = HyGaVector(p0, p1)

    d = p01.X() * p02.Y() - p02.X() * p01.Y()

    if d > 0:
        rst = True
    else:
        rst = False

    return rst

def HyGaIsTurnRight(p0, p1, p2):
    if HyGaIsCollineation(p0, p1, p2):
        return False

    if HyGaIsTurnLeft(p0, p1, p2):
        return False

    return True

