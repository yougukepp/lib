#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from tool.base import Square

"""
求平均阻尼
"""
def AverageDamp(func):
  if not callable(func):
    print(str(deal), "不可调用.")
    return None

  rst = lambda x : (func(x) + x)/ 2

  return rst

if __name__ == '__main__':
  for i in range(0, 10):
    v = (AverageDamp(Square))(i)
    print("(Square(%d) + %d) / 2 = %f" % (i, i, v))




