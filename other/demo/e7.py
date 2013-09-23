#!/usr/bin/env python3
# -- coding utf-8 --

if __name__ == "__main__":
    x = int(input("请输入x的值:"))
    if 0 < x:
        print("0 > x")
    elif 0 == x:
        print("0 == x")
    else:
        print("x < 0") 


    a = 1; b = 2; c = 3;
    if b >= a and b <= c :
        print("b在a与c之间.")
    if not (b < a or b > c ):
        print("b依然在a与c之间.")
    

