#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def Fibonacci(n):
  if n < 0:
    print("斐波拉西级数没有", n, "项.")
    return None

  a = 0                 # F(n-1)
  b = 1                 # F(n-2)

  if 0 == n:
    return 0
  elif 1 == n:
    return 1
  else:
    for i in range(n , 1, -1):
      a, b = b, a + b

  return b

if __name__ == '__main__':
  for i in range(-1, 50):
    rst = Fibonacci(i)
    if None != rst:
      print("%2d:%70d" % (i, rst))

