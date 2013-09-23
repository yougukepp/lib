#!/usr/bin/env python3
# -- coding utf-8 --

if __name__ == "__main__":
    i = 0
    while i < 3:
        print("while:%d" % i)
        i += 1 
        
    for i in range(0, 3):
        print("for:%d" % i)
    
    for c in "Hello World.":
        print(c, end = "")

