#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from lib.HyGaLib import gCanvasWidth

class HyGaPoints():
    mPoints = []

    def __init__(self):
        self.mPoints = []

    def Print(self):
        index = 0
        for p in self.mPoints:
            print(index, p.X(), p.Y())
            index += 1

    def Draw(self, painter):
        for p in self.mPoints:
            p.draw(painter)

    def Append(self, point):
        self.mPoints.append(point)

    def Size(self):
        if [] == self.mPoints:
            return 0
        else:
            return len(self.mPoints)

    def Clear(self):
        self.mPoints = []

    # 禁用 索引 赋值 (a[i] = v)
    """
    def __setitem__(self, key, val):
        self._res[key]=val
    """

    # 使用索引引用 (v = a[i])
    def __getitem__(self, key):
        if key < 0:
            #print("key:" + str(key) + ",size:" + str(self.size()))
            #print("index:" + str(key + self.size()))
            return self.mPoints[key + self.Size()]
        if key < self.Size():
            return self.mPoints[key]
        else:
            print("HyGaPoints 索引越界:size(" + str(self.Size()) + ")<=index(" + str(key) + ")" )

    # 可以删除 一个点
    def __delitem__(self, key):
        del self.mPoints[key]

    def SortedByXAndY(self):
        rst = []

        while 0 != self.Size():
            index = self.FindMinXAndY()
            rst.append(self[index])
            del self[index]

        self.mPoints = rst

    def FindMinXAndY(self):
        xMin = gCanvasWidth + 1
        yCurrent = 0
        rst = []
        minIndex = 0
        index = 0

        for p in self.mPoints:
            if (p.X() < xMin) or ((p.X() == xMin) and (p.Y() < yCurrent)):
                xMin = p.X()
                yCurrent = p.Y()
                minIndex = index
            index += 1

        return minIndex

