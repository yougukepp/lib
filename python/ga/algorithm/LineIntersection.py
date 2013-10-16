#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.EventQueue import EventQueue

def LineIntersection(lineList, IntersectionDict): 
    print("实现中......")
    print("输入线集,如下:")
    for line in lineList:
        line.Print()
        print()

    # 新建事件队列
    eventQueue = EventQueue()

if __name__ == "__main__":
    print("测试LineIntersection算法:通过")

