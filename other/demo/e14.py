#!/usr/bin/env python3
# -- coding utf-8 -- 

def factorial(n):
    if n < 0:
        raise ValueError
    elif (n <= 1):
        return 1
    else:
        return n * factorial(n-1)

if __name__ == "__main__":
    print("0至9的阶乘:")
    for i in range(0, 10):
        print(str(factorial(i)) + ",", end = "")

    print()
    print("f = factorial(-1):", end = "")
    try:
        f = factorial(-1)
    except ValueError:
        print("期望的参数非负")
       
    
