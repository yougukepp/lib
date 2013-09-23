#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def Square(x):
  return x*x

def Sum(deal, step, low, high):
  if not callable(deal):
    print(str(deal), "不可调用.")
    return None
  if not callable(step):
    print(str(step), "不可调用.")
    return None
  if high < low:
    print(high , "<" , low)
    return None
  if low == high:
    return 0

  """
  求和
  """
  rst = 0
  while low < high:
    rst += deal(low)     # 每一项的值
    low = step(low)      # 增加步长

  return rst;

def Integral(func, low, high, dx):
  if not callable(func):
    print(str(deal), "不可调用.")
    return None
  if high < low:
    print(high , "<" , low)
    return None

  rst = Sum(lambda x: func(x + dx/2), lambda x: x + dx, low, high) * dx

  return rst

if __name__ == '__main__':
  print("Integral(Square, 0, 1, 0.001)")
  print(Integral(Square, 0, 1, 0.001))

