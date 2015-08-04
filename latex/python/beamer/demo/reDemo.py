#!/usr/bin/env python3
# -- coding utf-8 -- 

import random, re

gReStr = r"^9.*"

def search(line):
    pattern = re.compile(gReStr)
    m = pattern.search(line)
    if None != m:
        print("line %d:%s" % (i, line), end = "")
        print("search:%s" % m.group())
        print()

if __name__ == "__main__":
    #生成一个随机源文件
    """
    fileOut = open("re.txt", "w")
    for i in range(0, 30):
        r = random.sample(range(0, 1000000000), 1)
        fileOut.write(str(r[0]) + "\n")
    fileOut.close()
    """

    fileIn = open("re.txt", "r")
    i = 0

    for line in fileIn:
        i += 1
        search(line)

    fileIn.close()

