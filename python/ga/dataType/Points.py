#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Points():
    mPoints = []
    mIndex = 0     # 迭代使用

    def __init__(self):
        self.mPoints = []

    def Print(self):
        index = 0
        for p in self.mPoints:
            print(str(index) + ":" + "(" + str(p.X()) + "," + str(p.Y()) + ")")
            index += 1

    def Append(self, point):
        self.mPoints.append(point)

    def Size(self):
        return len(self.mPoints)

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

    def CotainThisPoint(self, point):
        """
        为避免出错 此处迭代self.mPoints而不是 self,否则出错
        """
        for p in self.mPoints:
            if p == point:
                return True
        return False

    # 禁用 索引 赋值 (a[i] = v)
    """
    def __setitem__(self, key, val):
        self._res[key]=val
    """

    def __getitem__(self, key):
        """
        使用索引引用 (v = a[i])
        """
        if key < 0:
            return self.mPoints[key + self.Size()]
        if key < self.Size():
            return self.mPoints[key]
        else:
            print("Points 索引越界:size(" + str(self.Size()) + ")<=index(" + str(key) + ")" )

    def __delitem__(self, key):
        """
        可以删除 一个点
        """
        del self.mPoints[key]

    def SortedByXAndY(self):
        rst = []

        while 0 != self.Size():
            index = self.FindMinXAndY()
            rst.append(self[index])
            del self[index]

        self.mPoints = rst

    def FindMinXAndY(self):
        """
        若 xMin 过大 则会出问题
        """
        xMin = 1e100 + 1
        yCurrent = 0
        rst = []
        minIndex = 0
        index = 0

        for p in self.mPoints:
            if (p.__X__() < xMin) or ((p.__X__() == xMin) and (p.__Y__() < yCurrent)):
                xMin = p.__X__()
                yCurrent = p.__Y__()
                minIndex = index
            index += 1

        return minIndex

if __name__ == "__main__":
    print("测试Points类:通过")
