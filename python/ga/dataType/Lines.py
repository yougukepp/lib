#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Lines():
    mLines = []

    def __init__(self, points = []):
        if [] == points:
            self.mLines = []
        else: 
            assert(0 != points.Size() % 2, "线段集初始化的点数必须为偶数")

            i = 0
            while i < points.Size():
                line = Line(points[i], points[i+1])
                i += 2
                self.mLines.append(line)

    def Print(self):
        index = 0
        for l in self.mLines:
            print(str(index) + ":", end = "")
            l.Print()
            index += 1

    def Append(self, line):
        self.mLines.append(line)

    def Size(self):
        return len(self.mLines)

    def Clear(self):
        self.mLines = []

if __name__ == "__main__":
    print("测试Lines类:通过")
