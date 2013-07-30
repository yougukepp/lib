#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Point():
    x = 0;
    y = 0;
    z = 0;
    w = 1;

    def __init__(self, x, y, z = 0, w = 1):
        self.x = x;
        self.y = y;
        self.z = z;
        self.w = w;

    # 重载相等运算符 (p1 == p2)
    def __eq__(self, other):

        if not isinstance(other, Point):
            print("使用非Point对象 Point比较无意义")
            exit()

        if self.X() == other.X() and self.Y() == other.Y():
            return True
        else:
            return False

    def Print(self):
        print("(" + str(self.X()) + "," + str(self.Y()) + ")", end = "")


    def X(self):
        return self.x;

    def Y(self):
        return self.y;

    def Z(self):
        return self.z;

    def W(self):
        return self.W;
