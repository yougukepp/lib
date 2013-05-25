#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from tool.base import IsInt, IsDivisibility,Ceil,Random
from Power import Power
from Sqrt import Sqrt

def IsPrime(n):
  if n <= 1:
    return False

  if 2 == n:
    return True

  iMin = 2
  iMax = Ceil(Sqrt(n)) + 1

  for i in range(iMin, iMax):
    if IsDivisibility(n, i):
      return False

  return True;

"""
TODO:费马检测 返回False表示该数必定不是素数
     返回True表示该数是素数的概率极大
     其中测试次数越大,概率越大.
"""
def IsPrimeWithFermatTest(n, t):
  if n <= 1:
    return False
  if t <= 0:
    print("费马测试的次数不能为:", t)
    return None

  for i in range(0, t):
    r = Random(1, n - 1)
    remainder = Power(r, n) % n
    if remainder != r:
      return False

  return True

"""
测试费马定理
"""
def fermatLaw(n):
  if not IsPrime(n):
    print(n, " 不是素数，不符合费马定理")
    return

  for i in range(1, n):
    rst = Power(i, n) % n
    assert i == rst
    #print(i, rst)
  print("使用 ", n, " 验证费马定理 通过.")

if __name__ == '__main__':
  print("测试IsPrime")
  for i in range(-10, 10):
    rst = IsPrime(i)
    rst = IsPrimeWithFermatTest(i, 10)
    print(i, rst)

  print()
  print("测试IsPrimeWithFermatTest")
  for i in range(-10, 1000):
    rst = IsPrimeWithFermatTest(i, 1)
    print(i, rst)

