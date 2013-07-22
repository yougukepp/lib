#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from HyGaPoints import *
from HyGaIsTurnRight import *

class HyGaConvexHull():
    mInputPoints = HyGaPoints()
    mConvexHullPoints = HyGaPoints()

    def __init__(self, points = HyGaPoints()):
        self.mInputPoints = points
        self.ComputeConvexHull()

    def draw(self, painter):
        if None == self.mConvexHullPoints:
            return

        size = self.mConvexHullPoints.size()

        if size < 3:
            return
        else:
            pen = QPen(QColor(255, 0, 0))
            pen.setWidth(1)
            painter.setPen(pen)
            for i in range(1, size):
                painter.drawLine(self.mConvexHullPoints[i-1].ScreenPos(),
                        self.mConvexHullPoints[i].ScreenPos())
            painter.drawLine(self.mConvexHullPoints[size-1].ScreenPos(),
                    self.mConvexHullPoints[0].ScreenPos())

    def ComputeConvexHull(self):
        size = self.mInputPoints.size()
        if size < 3:
            return

        self.mInputPoints.SortedByXAndY()

        iPoints = self.mInputPoints
        oPoints = self.mConvexHullPoints

        oPoints.append(iPoints[0])
        oPoints.append(iPoints[1])

        for i in range(2, size):
            oPoints.append(iPoints[i])
            #print(str(i) + ":")
            #oPoints.print()
            while oPoints.size() >= 3 and (not HyGaIsTurnRight(oPoints[-3], oPoints[-2], oPoints[-1])):
                #print("oPoints size:" + str(oPoints.size()))
                del oPoints[-2]
        #oPoints.print()

