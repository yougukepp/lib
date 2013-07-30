#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.HyGaPoints import HyGaPoints
from algorithm.HyGaTurn import HyGaIsTurnLeft

class HyGaConvexhull():
    mInputPoints = HyGaPoints()
    mConvexhullPoints = HyGaPoints()

    def __init__(self, points = HyGaPoints()):
        for p in points:
            """
            避免多次加入同一个点 导致错误
            """
            if self.mInputPoints.CotainThisPoint(p):
                print("已经加入过 (" + str(p.X())+ "," + str(p.Y()) + ")" + ", 故此次不加入");
            else:
                self.mInputPoints.Append(p)

        self.ComputeConvexhull()

    def Size(self):
        return self.mConvexhullPoints.Size()

    def IsValid(self):
        if self.Size() > 2:
            return True
        else:
            return False

    def __getitem__(self, key):
        """
        使用索引引用 (v = a[i])
        """
        if key < 0:
            return self.mConvexhullPoints[key + self.Size()]
        if key < self.Size():
            return self.mConvexhullPoints[key]
        else:
            print("HyGaPoints 索引越界:size(" + str(self.Size()) + ")<=index(" + str(key) + ")" )

    def ComputeConvexhull(self):
        self.mConvexhullPoints.Clear()
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
            while len(oPointsUp) >= 3 and HyGaIsTurnLeft(oPointsUp[-3], oPointsUp[-2], oPointsUp[-1]):
                del oPointsUp[-2]

        for p in oPointsUp:
            self.mConvexhullPoints.Append(p)

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
            self.mConvexhullPoints.Append(p)
