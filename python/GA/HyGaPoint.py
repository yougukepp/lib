#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from HyGaLib import *

from PyQt4.QtGui import *
from PyQt4.QtCore import *

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

    def print(self):
        print("(" + str(self.X()) + "," + str(self.Y()) + ")", end = "")

    def draw(self, painter):
        pen = QPen(QColor(0, 255, 0))
        pen.setWidth(1)
        painter.setPen(pen)
        painter.drawPoint(self.ScreenPos())
        # pen = QPen(QColor(255, 255, 255))
        # painter.setPen(pen)
        # painter.drawText(self.ScreenPos(), labelStr)

    def drawLabel(self, painter, labelStr):
        pen = QPen(QColor(255, 255, 255))
        painter.setPen(pen)
        painter.drawText(self.ScreenPos(), labelStr)

    def ScreenPos(self):
        (rstX, rstY) = HyGaLibGa2Screen(self.X(), self.Y())
        return QPoint(rstX, rstY)

    def X(self):
        return self.x;

    def Y(self):
        return self.y;

    def Z(self):
        return self.z;

    def W(self):
        return self.W;

