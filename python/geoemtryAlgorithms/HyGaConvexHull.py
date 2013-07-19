#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from HyGaPoints import *

class HyGaConvexHull():
    mInputPoints = HyGaPoints()
    mConvexHullPoints = HyGaPoints()

    def __init__(self, points = HyGaPoints()):
        self.mInputPoints = points
        #self.ComputeConvexHull()

    def draw(self, painter):
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
                #print(i - 1, i)
            painter.drawLine(self.mConvexHullPoints[size-1].ScreenPos(),
                    self.mConvexHullPoints[0].ScreenPos())
            #print(size-1, 0)
        
    def __SortedByAngle__(self):
        # TODO
        sortedPoints = self.mInputPoints
        return sortedPoints 
    
    def ComputeConvexHull(self):
        #p0 = HyGaPoint(10, 10)
        #p1 = HyGaPoint(10, 20)
        #p2 = HyGaPoint(20, 20)
        #p3 = HyGaPoint(20, 10) 
        
        #convexHull.append(p0)
        #convexHull.append(p1)
        #convexHull.append(p2)
        #convexHull.append(p3) 
        
        if self.mInputPoints.size() < 3:
            return
            
        sortedPoints = self.__SortedByAngle__() 
        
        self.mConvexHullPoints = sortedPoints

        """
        if True == self.mConvexHullOK:
            size = len(self.mConvexHullOutput)

            if size < 3:
                print("求出的凸包点数小于3")
                exit()

            pen = QPen(QColor(255, 0, 0))
            pen.setWidth(1)
            painter.setPen(pen)
            for i in range(1, size): 
                painter.drawLine(self.mConvexHullOutput[i-1].ScreenPos(),
                        self.mConvexHullOutput[i].ScreenPos())
                print(i - 1, i)
            painter.drawLine(self.mConvexHullOutput[size-1].ScreenPos(),
                    self.mConvexHullOutput[0].ScreenPos())
            print(size-1, 0)
        """

