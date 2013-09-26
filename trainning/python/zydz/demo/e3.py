#!/usr/bin/env python3
# -- coding utf-8 --

if __name__ == "__main__":
    list1 = []
    list2 = [0,1,2]
    list3 = ["red", "green", "blue"]
    list4 = list2 + list3

    print("list1:                       ", end = ""); print(list1)
    print("list2:                       ", end = ""); print(list2)
    print("list3:                       ", end = ""); print(list3)
    print("list4:                       ", end = ""); print(list4)

    list3[1] = "a"
    print("list3[1] = \"a\":              ", end = ""); print(list3)

    list3.append(3)
    print("list3.append(3):             ", end = ""); print(list3)

    list3.insert(1, "b")
    print("list3.insert(1, \"b\"):        ", end = ""); print(list3)

    list3.extend(list2)
    print("list3.extend(list2)          ", end = ""); print(list3)

    del list3[1]
    print("del list3[1]                 ", end = ""); print(list3)
