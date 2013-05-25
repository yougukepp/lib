#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from Sum import Sum
from tool.base import Square

"""
求定积分
dx 越小 定积分越精确,但是越耗时
"""
def Integral(func, low, high, dx):
  if not callable(func):
    print(str(deal), "不可调用.")
    return None
  if high < low:
    print(high , "<" , low)
    return None

  rst = Sum(lambda x: func(x + dx/2), low, lambda x: x + dx, high) * dx

  return rst

def Const(n):
  return 1

if __name__ == '__main__':
  print("Integral(Square, 0, 1, 0.001)")
  print(Integral(Square, 0, 1, 0.001))
  print("Integral(Const, 0, 1, 0.001)")
  print(Integral(Const, 0, 1, 0.001))
