#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from tool.base import Square
from Derivative import Derivative
from FixedPoint import FixedPoint

def NewtonTransform(func):
    if not callable(func):
        print(str(func), "不可调用.")
        return None

    return lambda x : x - (func(x) / (Derivative(func))(x))

def NewtonMethod(func):
    return FixedPoint(NewtonTransform(func))

def Sqrt(x):
    if x < 0:
        print("x(%f)<0不可调用." % x)
        return 0
    elif 0 == x:
        return 0;
    else:
        return  NewtonMethod(lambda y : Square(y) - x )

if __name__ == '__main__': 
    print("测试Sqrt")
    for i in range(0,10):
        print(i, Sqrt(i))

