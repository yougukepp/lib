#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Vector():
    def __init__(self, p0, p1):
        self.mX = p1.__X__() - p0.__X__()
        self.mY = p1.__Y__() - p0.__Y__()

    def Print(self):
        print("(%d,%d)" % (self.__X__(), self.__Y__()), end = "")

    def __X__(self):
        return self.mX

    def __Y__(self):
        return self.mY 
    
    def IsCollineation(self, v):
        assert isinstance(v, Vector), "只能使用向量(Vector)做转向测试"

        rst = False 
        
        d = self.__X__() * v.__Y__() - v.__X__() * self.__Y__()
        
        if 0 == d:
            rst = True 
            
        return rst 
    
    def IsTurnLeft(self, v):
        rst = False 
        
        d = self.__X__() * v.__Y__() - v.__X__() * self.__Y__() 
        
        if d > 0:
            rst = True
        else:
            rst = False 

        return rst 
    
    def IsTurnRight(self, v):
        if self.IsCollineation(v):
            return False 
        
        if self.IsTurnLeft(v):
            return False 
        
        return True

if __name__ == "__main__":
    print("测试Vector类,通过")
