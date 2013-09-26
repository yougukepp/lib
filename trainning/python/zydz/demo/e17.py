#!/usr/bin/env python3
# -- coding utf-8 -- 
import numbers
from numbers import gcd

if __name__ == "__main__":
    x, y = numbers.divide(5, 2)
    print("x, y = divide(5, 2):         x:%d,y:%d" % (x, y))

    rst = gcd(12, 9)
    print("rst = gcd(12, 9):            rst:%d" % rst)

