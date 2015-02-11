#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import os 
import re

c_regex_space = re.compile(r'\/\*(.*?)\*\/', re.MULTILINE)

c_regex_comment = re.compile(r'^(.*)$')
c_regex_code = re.compile(r'^(.*)$')

    #match_list = c_regex_space.match(line)
    #print(match_list)

def ckt_count_cfile(cfile):
    cfile_obj = open(cfile)
    all_lines = cfile_obj.read()

    pp = c_regex_space.findall(all_lines)
    print(pp)

    cfile_obj.close()

def ckt_count_all_cfile(file_list):
    for cfile in file_list:
        ckt_count_cfile(cfile)

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

    """
    file_list = ckt_filter_cfile(sys.argv[1])

    ckt_count_all_cfile(file_list)
    """ 

    ckt_count_cfile(sys.argv[1])

