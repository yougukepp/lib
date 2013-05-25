#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def gcd(m, n):
  if m<n:
    m,n = n,m

  while True:
    r = m%n
    if 0 == r:
      return n;
    else:
      m = n
      n = r

  return 1

if __name__ == '__main__':
  import sys
  print(gcd(17, 68))

