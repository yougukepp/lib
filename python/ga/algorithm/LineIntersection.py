#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.Vector import Vector


def GetInterSectPoint(line1, line2):
    return None

def LineIntersection(lineList, IntersectionDict): 
    print("实现中......")
    print("输入线集,如下:")
    for line in lineList:
        line.Print()
        print()


    # 两两 相交测试
    iMax = lineList.Size()
    for i in range(0, iMax):
        for j in range(i + 1, iMax):
            # 相交测试
            if None != GetInterSectPoint(lineList[i], lineList[j]):
                pass
            else:
                pass


if __name__ == "__main__":
    print("测试LineIntersection算法:通过")

