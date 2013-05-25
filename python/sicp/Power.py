#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from tool.base import Square, IsEven, Sqrt

"""
TODO: 使算法可以处理负数幂 及 实数幂
"""
def Power(b, n):
  if(n < 0):
    print("暂时无法处理 ", n, "次幂.")
    return None

  if 0==b and 0 == n:
    print("0的0次方无意义.")
    return None

  divide = n
  base = b
  rst = 1

  while True:
    if not IsEven(divide):
      rst *= base
      base = base
      divide -= 1
    else:
      rst = rst
      base = Square(base)
      divide //= 2
    if 0 == divide:
      break;

  return rst

if __name__ == '__main__':
  for b in range(-1, 11):
      for n in range(-1, 7):
        rst = Power(b, n)
        if None != rst:
          print("%2d^%3d:%70d" % (b, n, rst))

