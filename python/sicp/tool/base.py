#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math
import random

"""
TODO: 自己实现
"""
Pi = math.pi

"""
TODO: 自己实现
"""
def Cos(x):
    return math.cos(x)

"""
TODO: 自己实现
"""
def Sin(x):
    return math.sin(x)

"""
TODO: 自己实现
"""
def Ceil(n):
  return math.ceil(n)

"""
TODO: 自己实现
"""
def Random(low, high):
  return random.randint(low, high)

def IsInt(n):
  if isinstance(n, int):
    return True
  else:
    return False

def IsDivisibility(n, d):
  if not (IsInt(n) and IsInt(d)):
    s = str(n) + " 和 " + str(d) + " 并非都是整数."
    print(s)
    return False

  remainder = n % d

  if 0 == remainder:
    return True
  else:
    return False

def IsEven(n):
  if not IsInt(n):
    s = str(n) + "不是整数."
    print(s)
    return False

  rst = False

  remainder = n % 2
  if 0 == remainder:
    rst = True
  else:
    assert(1 == remainder)
    rst = False

  return rst

def Square(n):
  return n*n

def CloseEnough(x, y):
    gInfiniteSimal = 1e-6
    if abs(x - y) < gInfiniteSimal:
        return True
    else:
        return False

if __name__ == '__main__':
  print("测试IsInt")
  for i in range(0,10):
    print(i, IsInt(i))
  for i in range(0,10):
    n = i + (1 - 0.1 * i)
    print(n, IsInt(n))

  print()
  print("测试Square")
  for i in range(0,10):
    print("%d,%d" % (i, Square(i)) )

  print()
  print("测试IsEven")
  for i in range(0,10):
    print(i, IsEven(i))

  print()
  print("测试Ceil")
  for i in range(0,10):
    n = i * 0.3
    print(n, Ceil(n))

  print()
  print("测试Random")
  low = 0
  high = 10
  for i in range(0,70):
    print(low, high, Random(low, high))

  print()
  print("测试Cos")
  low = 0
  high = 2 * Pi
  i = low
  while i < high:
      print("Cos(%f) = %f" % (i, Cos(i)))
      i += 0.01

  print()
  print("测试Sin")
  low = 0
  high = 2 * Pi
  i = low
  while i < high:
      print("Sin(%f) = %f" % (i, Sin(i)))
      i += 0.01

  print()
  print("测试CloseEnough")
  low = 0.999999
  high = 1.000002
  i = low
  while i < high:
      print("CloseEnough(%.8f, 1) = " % i + str(CloseEnough(i, 1)))
      i += 0.000001
