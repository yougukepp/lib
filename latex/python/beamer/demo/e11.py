#!/usr/bin/env python3
# -- coding utf-8 -- 

def add(a, b):
    return a+b

def divide(a, b):
    q = a / b
    r = a % b
    return(q, r)

if __name__ == "__main__":
    v = add(1,2)
    s = add("Hello", "World.")
    q,r = divide(7, 3)

    print("v = add(1,2):                ", end = ""); print(v)
    print("s = add(\"Hello\", \"World.\"):  ", end = ""); print(s)
    print("q,r = divide(7, 3):          ", end = ""); print("q:%d,r:%d" % (q, r))
