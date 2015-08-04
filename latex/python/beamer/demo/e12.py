#!/usr/bin/env python3
# -- coding utf-8 -- 

def Swap1(a, b):
    (a, b) = (b, a)

def Swap2(v):
    (v[0], v[1]) = (v[1], v[0])

def printMessage(s, times = 1):
    print(s * times) 
    
def printPara(a, b, c):
    print(a, b, c)

if __name__ == "__main__":
    a = 0
    b = 1
    print("a:%d,b:%d                            " % (a, b))
    Swap1(a, b)
    print("Swap1(a, b):                         ", end = ""); print("a:%d,b:%d" % (a, b))
    print()

    lst = [0, 1]
    print("lst:                                ", str(lst))
    Swap2(lst)
    print("Swap2(lst):                          ", end = ""); print("lst:", str(lst))
    print()

    print("printMessage(\"Hello\"):               ", end = ""); printMessage("Hello")
    print("printMessage(\"Hello\", 2):            ", end = ""); printMessage("Hello", 2)
    print("printPara(c = 1, b = 2 , a = 3):     ", end = ""); printPara(c = 1, b = 2 , a = 3)




