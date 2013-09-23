#!/usr/bin/env python3
# -- coding utf-8 --

if __name__ == "__main__":
    list1 = ()
    list2 = (0,1,2)
    list3 = ("red", "green", "blue")
    list4 = (1,[2,3],(4,5),6,7)

    print("list1:               ", end = ""); print(list1)
    print("list2:               ", end = ""); print(list2)
    print("list3:               ", end = ""); print(list3)
    print("list4:               ", end = ""); print(list4)

    v = list4[0]
    print("v=list4[0]:          ", end = ""); print(v)
    v = list4[1][0]
    print("v=list4[1][0]:       ", end = ""); print(v)

    try:
        list4[3] = 0
    except TypeError:
        print("list4[3] = 0:        ", end = ""); print("ERROR,元组元素无法赋值")

    list4[1][0] = 0
    print("list4[1][0] = 0:     ", end = ""); print(list4)

    try:
        list4[2][0] = 0
    except TypeError:
        print("list4[2][0] = 0:     ", end = ""); print("ERROR,元组元素无法赋值")

