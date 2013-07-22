#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from HyGaLib import *

from PyQt4.QtGui import *
from PyQt4.QtCore import *

def Ga2Screen(point):
    (rstX, rstY) = HyGaLibGa2Screen(point.X(), point.Y())
    return QPoint(rstX, rstY)

class HyGaPoint():
    x = 0;
    y = 0;
    z = 0;
    w = 1;

    def __init__(self, x, y, z = 0, w = 1):
        self.x = x;
        self.y = y;
        self.z = z;
        self.w = w;

    def draw(self, painter):
        pen = QPen(QColor(0, 255, 0))
        pen.setWidth(1)
        painter.setPen(pen)
        painter.drawPoint(Ga2Screen(self))

    def X(self):
        return self.x;

    def Y(self):
        return self.y;

    def Z(self):
        return self.z;

    def W(self):
        return self.W;

