#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from tool.base import Square

"""
求平均阻尼
"""
def Derivative(func):
  dx = 1e-6
  if not callable(func):
    print(str(deal), "不可调用.")
    return None

  rst = lambda x : (func(x + dx) - func(x)) / dx

  return rst

if __name__ == '__main__':
  for i in range(0, 10):
    v = (Derivative(Square))(i)
    print("(Derivative(Square) %d) = %f" % (i, v))

