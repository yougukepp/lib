#!/usr/bin/env python3
# -- coding utf-8 -- 

def add(*para):
    s = 0
    for i in para:
        s += i
    return s

def CollectPara(**para):
    for k in para:
        print(str(k) + ":" + str(para[k]))

if __name__ == "__main__":
    s = add(1,2,3,4,5)
    print("s = add(1,2,3,4,5):                  ", end = ""); print(s)
    print()
    print("CollectPara(p1 = 1, p2 = 2, p3 = 3): "); CollectPara(p1 = 1, p2 = 2, p3 = 3)




