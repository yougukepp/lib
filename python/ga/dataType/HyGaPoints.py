#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from lib.HyGaLib import gCanvasWidth

class HyGaPoints():
    mPoints = []
    mIndex = 0     # 迭代使用

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
        return len(self.mPoints)
        """
        if [] == self.mPoints:
            return 0
        else:
            return len(self.mPoints)
        """

    def Clear(self):
        self.mPoints = []

    def __next__(self):
        if self.mIndex >= self.Size():
            self.mIndex = 0
            raise StopIteration

        rst = self.mPoints[self.mIndex]
        self.mIndex += 1
        return rst

    def __iter__(self):
        return self

    # 为避免出错 此处迭代self.mPoints而不是 self,否则出错
    def CotainThisPoint(self, point):
        for p in self.mPoints:
            if p == point:
                return True
        return False

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

