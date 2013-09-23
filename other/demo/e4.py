#!/usr/bin/env python3
# -- coding utf-8 --

def TestStack():
    stack = [0,1,2]
    print("statck:              ", end = ""); print(stack)

    stack.append(100)
    print("statck.append(100):  ", end = ""); print(stack)

    stack.pop()
    print("statck.pop():        ", end = ""); print(stack)
    stack.pop()
    print("statck.pop():        ", end = ""); print(stack)
    stack.pop()
    print("statck.pop():        ", end = ""); print(stack)

    stack.append("a")
    print("statck.append(\"a\"):  ", end = ""); print(stack)

    stack.append(10)
    print("statck.append(10):   ", end = ""); print(stack)

def TestFifo():
    fifo = [0,1,2]
    print("fifo:                ", end = ""); print(fifo)

    fifo.append(100)
    print("fifo.append(100):    ", end = ""); print(fifo)

    fifo.pop(0)
    print("fifo.pop(0):         ", end = ""); print(fifo)
    fifo.pop(0)
    print("fifo.pop(0):         ", end = ""); print(fifo)
    fifo.pop(0)
    print("fifo.pop(0):         ", end = ""); print(fifo)

    fifo.append("a")
    print("fifo.append(\"a\"):    ", end = ""); print(fifo)

    fifo.append(10)
    print("fifo.append(10):     ", end = ""); print(fifo)
def TestRange():
    print("range(0, 10):        ", end = "")
    for i in range(0 ,10):
        print("%d," % i, end = "")
    print()
    
if __name__ == "__main__":
    TestStack()
    print()
    TestFifo()
    print()
    TestRange()

