#!/usr/bin/env python3
# -- coding utf-8 --

if __name__ == "__main__":
    dict1 = {}
    dict2 = {0:"red", 1:"green"}
    dict3 = {"论坛":("192.168.88.21", 0)}
    print("dict1:                               ", end = ""); print(dict1)
    print("dict2:                               ", end = ""); print(dict2)
    print("dict3:                               ", end = ""); print(dict3)

    v = dict3["论坛"]
    print("v=dict3[\"论坛\"]:                     ", end = ""); print(v)

    dict3["论坛"] = ("192.168.88.21",80)
    print("dict3[\"论坛\"] = (\"192.168.88.21\",80):", end = ""); print(dict3)
    dict3["百度"] = ("202.108.22.5",80)
    print("dict3[\"百度\"] = (\"202.108.22.5\",80): ", end = ""); print(dict3)
    dict3.clear()
    print("dict3.clear():                       ", end = ""); print(dict3)

    dict4 = {}
    try:
        dict4[[0,1]] = "列表键"
    except TypeError:
        print("dict4[[0,1]] = \"列表键\":             ", end = ""); print("ERROR:列表不能作为字典的键")

    dict4[(0,1)] = "元组键"
    print("dict4[(0,1)] = \"元组键\":             ", end = ""); print(dict4)
