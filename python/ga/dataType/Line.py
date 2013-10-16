#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.Point import Point

class Line():
    def __init__(self, start, end):
        assert start != end, "起点和终点不能相同"
        self.mStartPoint = start
        self.mEndPoint = end

    def GetEquation(self):
        assert self.mStartPoint != self.mEndPoint, "起点和终点不能相同"

        if self.mStartPoint.__X__() == self.mEndPoint.__X__():
            """
            平行于 y 轴
            方程为 x - X = 0
            """
            return (1, 0, self.mStartPoint.__X__())
        elif self.mStartPoint.__Y__() == self.mEndPoint.__Y__():
            """
            平行于 X 轴
            方程为 y - Y = 0
            """
            return (0, 1, self.mStartPoint.__Y__())
        else:
            """
            使用两点式 求直线方程

            两点式: (y - y1) / (x - x1) = (y2 - y1) / (x2 - x1)
            斜截式: y = kx + c

            """
            k = (self.mEndPoint.__Y__() - self.mStartPoint.__Y__()) / (self.mEndPoint.__X__() - self.mStartPoint.__X__())
            c = self.mStartPoint.__Y__() - k * self.mStartPoint.__X__()
            return(k, -1, c)

    def Print(self):
        self.mStartPoint.Print()
        print("===>", end = "")
        self.mEndPoint.Print()

if __name__ == "__main__":
    print("测试Line类:通过")

