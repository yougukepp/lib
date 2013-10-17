#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.Point import Point

class Line():
    def __init__(self, start, end):
        assert start != end, "起点和终点不能相同"
        self.mStartPoint = start
        self.mEndPoint = end

    def GetEquation(self):
        """
        返回值:
        直线方程一般式
        ax+by=c
        (a,b,c)
        """
        assert self.mStartPoint != self.mEndPoint, "起点和终点不能相同"

        if self.mStartPoint.__X__() == self.mEndPoint.__X__():
            """
            平行于 y 轴
            方程为 x = C
            """
            return (1, 0, self.mStartPoint.__X__())
        elif self.mStartPoint.__Y__() == self.mEndPoint.__Y__():
            """
            平行于 X 轴
            方程为 y = C
            """
            return (0, 1, self.mStartPoint.__Y__())
        else:
            """
            使用两点式 求直线方程

            两点式: (y - y1) / (x - x1) = (y2 - y1) / (x2 - x1)
            斜截式: y = kx + c
            方程为: kx - y = - C
            """
            k = (self.mEndPoint.__Y__() - self.mStartPoint.__Y__()) / (self.mEndPoint.__X__() - self.mStartPoint.__X__())
            c = self.mStartPoint.__Y__() - k * self.mStartPoint.__X__()
            return(k, -1, -c) 
        
    def Cotain(self, p):
        (x, y) = p.Get2Pos()
        if self.MinX() <= x <= self.MaxX() and self.MinY() <= y <= self.MaxY():
            return True
        else:
            return False


    def MaxX(self):
        if self.mStartPoint.__X__() > self.mEndPoint.__X__():
            return self.mStartPoint.__X__()
        else:
            return self.mEndPoint.__X__()

    def MinX(self):
        if self.mStartPoint.__X__() < self.mEndPoint.__X__():
            return self.mStartPoint.__X__()
        else:
            return self.mEndPoint.__X__()

    def MaxY(self):
        if self.mStartPoint.__Y__() > self.mEndPoint.__Y__():
            return self.mStartPoint.__Y__()
        else:
            return self.mEndPoint.__Y__()

    def MinY(self):
        if self.mStartPoint.__Y__() < self.mEndPoint.__Y__():
            return self.mStartPoint.__Y__()
        else:
            return self.mEndPoint.__Y__()

    def Print(self):
        self.mStartPoint.Print()
        print("===>", end = "")
        self.mEndPoint.Print()

if __name__ == "__main__":
    print("测试Line类:通过")

