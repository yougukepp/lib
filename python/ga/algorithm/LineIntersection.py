#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.Line import Line
from dataType.Point import Point

def ProjectionCoincidence(line1, line2):
    (rstX, rstY) = (False, False)
    maxX = line1.MaxX()
    minX = line1.MinX()
    x = line2.MinX()

    maxY = line1.MaxY()
    minY = line1.MinY()
    y = line2.MinY()

    if minX <= x <= MaxX:
        rstX = True

    if minY <= y <= MaxY:
        rstY = True

    return (rstX, rstY)


def GetInterSectPoint(line1, line2):
    (a1,b1,c1) = line1.GetEquation()
    (a2,b2,c2) = line2.GetEquation()

    D = a1 * b2 -  b1 * a2
    D1 = c1 * b2 - b1 * c2
    D2 = a1 * c2 - c1 * a2

    if 0 == D:
        if c1 == c2: # 共线
            (xCoinCidence, yCoinCidence) = ProjectionCoincidence(line1, line2)
            if xCoinCidence:
                assert yCoinCidence, "两条线段共线时,x轴投影重合,y轴投影也必然重合"
                return ("重合", None) # TODO: 返回重合部分的起点和终点
            else: # 无交点
                return ("无交点", None)
        else: # 平行
            return ("平行", None)
    else: # 相交
        x = D1 / D
        y = D2 / D

        p = Point(x, y)

        # 判断交点是否在两线段上
        if line1.Cotain(p) and line2.Cotain(p):
            return ("相交", p)
        else:
            return ("直线相交但交点不在线段上", p)

def LineIntersection(lineList, IntersectionDict): 

    # 两两 相交测试
    iMax = lineList.Size()
    for i in range(0, iMax):
        for j in range(i + 1, iMax):
            # 相交测试
            rst = GetInterSectPoint(lineList[i], lineList[j])
            if "相交" == rst[0]:
                print("交点:", end = "")
                rst[1].Print()
            else:
                print(rst[0])

    print("需要将输出设计得更美观")

if __name__ == "__main__":
    print("测试LineIntersection算法:通过")

