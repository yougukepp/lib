#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.Point import Point

class Line():
    def __init__(self, start, end):
        assert start != end, "起点和终点不能相同"
        self.mStartPoint = start
        self.mEndPoint = end

    def GetEquation(line):
        pass

    def Print(self):
        self.mStartPoint.Print()
        print("===>", end = "")
        self.mEndPoint.Print()

if __name__ == "__main__":
    print("测试Line类:通过")
