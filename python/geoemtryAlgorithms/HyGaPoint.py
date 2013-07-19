#!/usr/bin/env python3
# -*- coding: utf-8 -*-

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

    def draw(self, painter):
        pen = QPen(QColor(0, 255, 0))
        pen.setWidth(1)
        painter.setPen(pen)
        painter.drawPoint(self.ScreenPos())

    def ScreenPos(self):
        x = self.x
        y = self.y
        screenPos = QPoint(x, y)
        return screenPos

