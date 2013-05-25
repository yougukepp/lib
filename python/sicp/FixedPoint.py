#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from tool.base import CloseEnough, Cos, Sin

def FixedPoint(func):
  if not callable(func):
    print(str(func), "不可调用.")
    return None

  firstGuess = 1.0
  maxIterTimes = 1000

  guess = func(firstGuess)
  times = 0
  while True:
      if CloseEnough(guess, func(guess)):
          return guess
      else:
          guess = func(guess)

      #print(times, guess)
      times += 1
      if times >= maxIterTimes:
          return None
  
  
if __name__ == '__main__':
    print("测试不动点")
    FixedPointOfCos = 0.7390845495752126
    if CloseEnough(FixedPointOfCos, FixedPoint(Cos)):
        print("cos(x)的不动点为%f,计算值为:%f,测试通过" % (FixedPointOfCos, FixedPoint(Cos)))
    else:
        print("cos(x)的不动点为%f,计算值为:%f,测试失败" % (FixedPointOfCos, FixedPoint(Cos)))
