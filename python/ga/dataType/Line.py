#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from Point import Point

class Line():
    mStartPoint = Point()
    mEndPoint = Point()

    def __init__(self, start = Point(), end = Point()):
        mStartPoint = start
        mEndPoint = end

    def StartPoint():
        return mStartPoint

    def EndPoint():
        return mEndPoint

if __name__ == "__main__":
    print("测试Line类:通过")


