#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# 内部格式 使用数学坐标

from PyQt4.QtCore import QPoint

from config.config import gCanvasHeight

class Point():
    def __init__(self, x = 0, y = 0, z = 0, w = 1, pointType = "Screen"):
        """
        默认输入的坐标 为Qt屏幕坐标 即左上角 原点
        """
        rstY = y
        if "Screen" == pointType:
            rstY = gCanvasHeight - y - 1
        elif "Ga" == pointType:
            pass
        else:
            print("未实现" + pointType + "类型的点")

        self.mX = x;
        self.mY = rstY;
        self.mZ = z;
        self.mW = w;

    # 重载相等运算符 (p1 == p2)
    def __eq__(self, other):
        assert isinstance(other, Point), "使用非Point对象 Point比较无意义"

        if self.__X__() == other.__X__() and self.__Y__() == other.__Y__():
            return True
        else:
            return False

    def Print(self):
        print("(%3d,%3d)" % (self.__X__(), self.__Y__()), end = "")

    def Get2Pos(self):
        return (self.__X__(), self.__Y__())

    def Get2PosStr(self):
        pos =  "(%d, %d)" % (self.__X__(), self.__Y__())
        return pos

    def GetScreenPoint(self):
        rstY = gCanvasHeight - self.__Y__() - 1
        return QPoint(self.__X__(), rstY)

    def GetGaPoint(self):
        return self

    #TODO: 使数据域不可见
    def __X__(self):
        return self.mX;

    def __Y__(self):
        return self.mY;

    """
    def __Z__(self):
        return self.z;

    def __W__(self):
        return self.W;
    """

if __name__ == "__main__":
    print("测试Point类:通过")

