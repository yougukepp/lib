#!/usr/bin/env python3
# -- coding utf-8 -- 

def divide(a, b):
    q = a / b
    r = a % b
    return(q, r)

def gcd(x, y):
    g = y
    while x > 0:
        g = x
        x = y % x
        y = g
    return g

if __name__ == "__main__":
    print("numbers.py 单元测试")
    x, y = divide(11, 4)
    print("x, y = divide(11, 4):         x:%d,y:%d" % (x, y))

    rst = gcd(51, 72)
    print("rst = gcd(51, 72):            rst:%d" % rst)


