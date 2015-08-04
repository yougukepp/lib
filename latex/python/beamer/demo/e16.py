#!/usr/bin/env python3
# -- coding utf-8 -- 

class Fibonacci():
    def __init__(self, maxIndex = 10):
        self.maxIndex = maxIndex
        self.mIndex = 1

    def __next__(self):
        current = self.b
        if self.mIndex > self.maxIndex:
            raise StopIteration

        (self.a, self.b) = (self.b, self.a + self.b)
        self.mIndex += 1
        return current

    def __iter__(self):
        self.a = 0
        self.b = 1
        return self

if __name__ == "__main__":
    fib = Fibonacci(5)

    """
    it = iter(fib)
    try:
        while True:
            val = it.__next__()
            print(val, end = ",")
    except StopIteration:
        pass
    """

    print("斐波拉契级数:")
    for i in fib:
        print(i, end = ",")

