#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.Point import Point

class Line():
    def __init__(self, start = Point(), end = Point()):
        self.mStartPoint = start
        self.mEndPoint = end

    def StartPoint(self):
        return self.mStartPoint

    def EndPoint(self):
        return self.mEndPoint

    def Print(self):
        self.mStartPoint.Print()
        print("===>", end = "")
        self.mEndPoint.Print()

if __name__ == "__main__":
    print("测试Line类:通过")


