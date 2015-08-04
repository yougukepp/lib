#!/usr/bin/env python3
# -- coding utf-8 --

if __name__ == "__main__":
    s = "abcdefghij"

    print("遍历:", end = '')
    for c in s:
        print(c + ",", end = '')    
    print()

    print("s[0]:%s" % s[0])
    print("s[1:5]:%s" % s[1:5])
    print("s[-1]:%s" % s[-1])
    print("s[-2]:%s" % s[-2])
    print("len(s):%s" % len(s))
    print("\"a\" in s:%s" % ("a" in s))
    print("\"4\" in s:%s" % ("4" in s))
