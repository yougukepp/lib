#!/usr/bin/env python3
# -- coding utf-8 --

if __name__ == "__main__":
    fileOut = open("e10.txt", "w")
    fileIn = open("e10.txt", "r")

    strWrited = "Hello World.\n"
    print("write:" + strWrited, end = "")
    fileOut.write(strWrited)

    strWrited = "012345\n"
    print("write:" + strWrited)
    fileOut.write(strWrited)

    for line in fileIn.readline():
        print("read:" + line, end = "")

    fileIn.close()
    fileOut.close()
