#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def Factorial(n):
  if n <= 0:
    print(n, "没有阶乘.")
    return None

  rst = 1

  for i in range(1, n+1):
    rst *= i

  return rst;

if __name__ == '__main__':
  for i in range(-1, 50):
    rst = Factorial(i)
    if None != rst:
      print("%2d:%70d" % (i, rst))


