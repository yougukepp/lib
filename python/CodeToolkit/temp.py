#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import re

g_regex_code = re.compile(
    r"""^       # 行首
    (\s*)       # 缩进
    (\w*)       # 代码
    (\s*)       # 空白
    (//|/\*)?   # 注释头是该行开始
    (.*)$       # 注释内容
    """,
    re.X)


if __name__ == '__main__':
    match = g_regex_code.search("#include <stdio.h>\n")
    #match = g_regex_code.search("   //1231")
    #match = g_regex_code.search("   //  1231")
    #match = g_regex_code.search("   /*1231")
    #match = g_regex_code.search("  adf //1231")
    if match:
        print(match.group())
        print(match.groups())


