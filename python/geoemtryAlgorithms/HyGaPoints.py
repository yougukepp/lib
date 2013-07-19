#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class HyGaPoints():
    mPoints = []

    def __init__(self):
        self.mPoints = []

    def draw(self, painter):
        for p in self.mPoints:
            p.draw(painter) 

    def append(self, point):
        self.mPoints.append(point)

    def size(self):
        return len(self.mPoints)

    # 禁用 索引 赋值 (a[i] = v)
    """
    def __setitem__(self, key, val):
        self._res[key]=val 
    """
            
    # 使用索引引用 (v = a[i])
    def __getitem__(self, key): 
        if key < self.size():
            return self.mPoints[key]
        else:
            print("HyGaPoints 索引越界:size(" + str(self.size()) + ")<=index(" + str(key) + ")" )

