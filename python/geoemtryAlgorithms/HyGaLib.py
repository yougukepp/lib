#!/usr/bin/env python3
# -*- coding: utf-8 -*-

gCanvasWidth = 800
gCanvasHeight = 800

def HyGaLibScreen2Ga(x, y):
    rstX = x
    rstY = gCanvasHeight - y - 1

    return (rstX, rstY)

def HyGaLibGa2Screen(x, y):
    return HyGaLibScreen2Ga(x, y)

