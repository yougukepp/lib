#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import os 
import re

g_regex_blank = re.compile(
    r"""^(\s*)$""",
    re.X)

g_regex_line_comment = re.compile(
    r"""^(.*)   # 行注释起点之前的代码
    (//)        # 行注释头
    (.*)$       # 行注释内容""",
    re.X)

g_regex_code = re.compile(
    r"""^
    (.*?)       # 可能的代码
    (//|/\*)    # 注释头
    (.*)$       # 注释""",  
    re.X)

g_regex_block_comment_begin = re.compile(
    r"""^(.*)   # 块注释起点之前的代码
    (/\*)       # 块注释头
    (.*)$       # 块注释内容""",
    re.X)

g_regex_block_comment_end = re.compile(
    r"""^(.*)   # 块注释内容
    (\*/)       # 块注释尾
    (.*)$       # 块注释尾后代码""",
    re.X)

def ckt_has_block_comment_begin(line):
    block_comment_match = g_regex_block_comment_begin.search(line)
    if block_comment_match:
        #print(block_comment_match.group(3))
        return True
    return False

def ckt_has_block_comment_end(line):
    block_comment_match = g_regex_block_comment_end.search(line)
    if block_comment_match:
        #print(block_comment_match.group(1))
        return True
    return False

def ckt_has_blank(line):
    blank_match = g_regex_blank.search(line)
    if blank_match:
        return True
    return False

def ckt_has_code(line):
    code_match = g_regex_code.search(line) 

    if code_match:
        code_string = code_match.group(1)
        if ckt_has_blank(code_string):
            return False

    return True

def ckt_has_line_comment(line):
    line_comment_match = g_regex_line_comment.search(line)
    if line_comment_match:
        return True
    return False 

def ckt_count_cfile(cfile):
    blank_count = 0
    comment_count = 0
    code_count = 0
    line_index = 0      # 行号
    all_count = 0

    in_blcok_comment = False

    cfile_obj = open(cfile) 
    
    block_comment_start_index = 0   # 块注释起点行号
    block_comment_end_index = 0     # 块注释终点行号
    for line in cfile_obj:
        line_index += 1

        # 块注释
        # 块注释开始
        if ckt_has_block_comment_begin(line):
            in_blcok_comment = True
            block_comment_start_index = line_index
        # 块注释结束
        if ckt_has_block_comment_end(line):
            in_blcok_comment = False
            block_comment_end_index = line_index 
            # 块注释计数
            comment_count += (block_comment_end_index - block_comment_start_index) + 1
            #print("start:" + str(block_comment_start_index))
            #print("end  :" + str(block_comment_end_index))
            #print("count:" + str(block_comment_end_index - block_comment_start_index + 1))

        if in_blcok_comment: # 块注释内部
            #print("in :" + str(line_index))
            continue
        else:  # 块注释外部解析 空白行及代码行 (单行块注释算作块注释外部行)
            #print("out:" + str(line_index))
            if ckt_has_blank(line):
                #print(line_index)
                blank_count += 1 
                continue            # 空白行不可能有代码和行注释
            if ckt_has_line_comment(line):
                #print(line_index)
                comment_count += 1
            if ckt_has_code(line):
                code_count += 1
        
    all_count = line_index
    cfile_obj.close()

    return (code_count, comment_count, blank_count, all_count)

def ckt_count_all_cfile(file_list): 
    code_total = 0
    comment_total = 0
    blank_total = 0
    all_total = 0

    print("代码 | 注释 | 空白 | 总计 |  代码率 |  注释率 |  空白率 | 文件名")
    for cfile in file_list:
        # 各文件
        (code_count, comment_count, blank_count, all_count) = ckt_count_cfile(cfile)
        # 避免空文件除零错误
        if 0 == all_count:
            code_rate = 0
            comment_rate = 0
            blank_rate = 0
        else:
            code_rate = code_count / all_count * 100
            comment_rate = comment_count / all_count * 100
            blank_rate = blank_count / all_count * 100

        print("%4d | %4d | %4d | %4d | %6.2f%% | %6.2f%% | %6.2f%% | %s" % (code_count, comment_count, blank_count, all_count, code_rate, comment_rate, blank_rate, cfile))

        # 合计
        code_total += code_count
        comment_total += comment_count
        blank_total += blank_count
        all_total += all_count

    if 0 == all_total:
        code_total_rate = 0
        comment_total_rate = 0
        blank_total_rate = 0
    else:
        code_total_rate = code_total / all_total * 100
        comment_total_rate = comment_total / all_total * 100
        blank_total_rate = blank_total / all_total * 100

    print("%4d | %4d | %4d | %4d | %6.2f%% | %6.2f%% | %6.2f%% | 合计" % (code_total, comment_total, blank_total, all_total, code_total_rate, comment_total_rate, blank_total_rate))

def ckt_filter_cfile(src_dir):
    """
    c源文件列表
    """
    file_list = []

    """
    参数检查
    """
    if not os.path.isdir(sys.argv[1]):
        ctk_usage()
        print('参数不是目录.')
        exit()

    """
    遍历目录
    """
    for root,dirs,files in os.walk(src_dir):
        for file_path in files:

            file_full_path = os.path.join(root, file_path)

            dir_name, base_name = os.path.split(file_full_path)
            name, ext = os.path.splitext(base_name) 
            
            """
            仅滤出.c 和 .h文件
            """
            if '.c' == ext or '.h' == ext:
                file_list.append(file_full_path) 

    return file_list

def ctk_usage():
    usage = str(sys.argv[0]) + ' [目录名]'
    print(usage)

if __name__ == '__main__':
    if 2 != len(sys.argv):
        ctk_usage()
        exit()

    file_list = ckt_filter_cfile(sys.argv[1])

    ckt_count_all_cfile(file_list)

