#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from tool.base import Square

def Add(n):
  return n + 1

def Sum(deal, low, step, high):
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

  rst = 0
  while low < high:
    rst += deal(low)
    low = step(low)

  return rst;

if __name__ == '__main__':
  print("Sum(Square, 1, Add, 3)")
  print(Sum(Square, 1, Add, 3))

