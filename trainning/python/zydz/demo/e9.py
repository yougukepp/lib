#!/usr/bin/env python3
# -- coding utf-8 --

import math

def IsPrime(n):
  if n <= 1:
    return False

  if 2 == n:
    return True

  iMin = 2
  iMax = math.ceil(math.sqrt(n)) + 1

  for i in range(iMin, iMax):
      if 0 == n % i:
          return False
  return True;

if __name__ == "__main__":
    primeLst = []
    for i in range(0, 51):
        if not IsPrime(i):
            continue
        else:
            primeLst.append(i)

    print("50以内的素数:     ", end =""); print(primeLst)

    for i in range(1000, 0, -1):
        if IsPrime(i):
            print("1000以内最大素数: ", end = ""); print(i)
            break



