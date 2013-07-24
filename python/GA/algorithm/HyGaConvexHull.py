#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from dataType.HyGaPoints import HyGaPoints
from algorithm.HyGaTurn import HyGaIsTurnLeft

class HyGaConvexHull():
    mInputPoints = HyGaPoints()
    mConvexHullPoints = HyGaPoints()

    def __init__(self, points = HyGaPoints()):
        # 避免多次加入同一个点 导致错误
        size = points.Size()
        for i in range(0, size):
            p = points[i]
            print("测试" + str(p.X()) + "," + str(p.Y()), end="")
            if self.mInputPoints.CotainThisPoint(p):
                print("未通过")
                print("已经加入过 (" + str(p.X())+ "," + str(p.Y()) + ")" + ", 故此次不加入");
            else:
                print("通过")
                self.mInputPoints.Append(p)

        self.mInputPoints.Print()
        self.ComputeConvexHull()

    def draw(self, painter):
        if None == self.mConvexHullPoints:
            return

        size = self.mConvexHullPoints.Size()

        if size < 3:
            return
        else:
            for i in range(1, size):
                pen = QPen(QColor(255, 0, 0))
                pen.setWidth(1)
                painter.setPen(pen)
                painter.drawLine(self.mConvexHullPoints[i-1].ScreenPos(),
                        self.mConvexHullPoints[i].ScreenPos())
                self.mConvexHullPoints[i-1].drawLabel(painter, str(i))
            pen = QPen(QColor(255, 0, 0))
            pen.setWidth(1)
            painter.setPen(pen)
            painter.drawLine(self.mConvexHullPoints[size-1].ScreenPos(),
                    self.mConvexHullPoints[0].ScreenPos())
            self.mConvexHullPoints[i-1].drawLabel(painter, str(i))

    def ComputeConvexHull(self):
        self.mConvexHullPoints.Clear()
        size = self.mInputPoints.Size()
        if size < 3:
            return

        self.mInputPoints.SortedByXAndY()
        iPoints = self.mInputPoints

        oPointsUp = []
        oPointsDown = []

        # 上凸包
        oPointsUp.append(iPoints[0])
        oPointsUp.append(iPoints[1])

        for i in range(2, size):
            oPointsUp.append(iPoints[i])
            #print(str(i) + ":")
            #oPointsUP.print()
            while len(oPointsUp) >= 3 and HyGaIsTurnLeft(oPointsUp[-3], oPointsUp[-2], oPointsUp[-1]):
                #print("oPointsUp size:" + str(oPointsUp.size()))
                del oPointsUp[-2]
        #oPointsUp.print()

        for p in oPointsUp:
            self.mConvexHullPoints.Append(p)

        # 下凸包
        oPointsDown.append(iPoints[size-1])
        oPointsDown.append(iPoints[size-2])

        for i in range(2, size):
            index = size - 1 - i   # 逆序遍历
            oPointsDown.append(iPoints[index])
            while len(oPointsDown) >= 3 and HyGaIsTurnLeft(oPointsDown[-3], oPointsDown[-2], oPointsDown[-1]):
                del oPointsDown[-2]

        del oPointsDown[0] # 删除与上凸包重合的X值最大的点
        for p in oPointsDown:
            self.mConvexHullPoints.Append(p)
