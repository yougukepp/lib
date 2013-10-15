#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Lines():
    mLines = []
    mIndex = 0     # 迭代使用

    def __init__(self):
        self.mLines = []

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

    # 迭代内建函数
    def __next__(self):
        if self.mIndex >= self.Size():
            self.mIndex = 0
            raise StopIteration

        rst = self.mLines[self.mIndex]
        self.mIndex += 1
        return rst

    # 迭代内建函数
    def __iter__(self):
        return self

if __name__ == "__main__":
    print("测试Lines类:通过")
