#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import re

g_regex_code = re.compile(
    r"""^
    (.*?)       # 可能的代码
    (//|/\*)    # 注释头
    (.*)$       # 注释""",  
    re.X)

def ckt_is_blank_string(code_string):
    pass

if __name__ == '__main__':
    i = 0
    f = open("main.c")

    for line in f: 
        i += 1
        match = g_regex_code.search(line)
        if match:
            print(str(i) + ":" + line, end = '')

            code_string = match.group(1)
            if ckt_is_blank_string(code_string):
                pass
            else:
                pass

            print("代码  :" + match.group(1))
            print("注释头:" + match.group(2))
            print("注释  :" + match.group(3))
        else:
            print(str(i) + ":" + line, end = '')
            print("代码  :" + line, end = '')

    f.close()

