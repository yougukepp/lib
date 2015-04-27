#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sqlite3
import time
from WBDPSpider import WBDPSpider

# 表名 年
# 举例 2013

gStorageName = 'wbdp.db'
gStartYear = 1960

gCmdHeadCreateTable = "CREATE TABLE " 
gTableFormat = """ (ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL,
                    INDICATORS_ID      TEXT                NOT NULL,
                    VALUAE             REAL                NOT NULL);"""

class WBDPStorage:
    def __init__(self):
        #
        # 新建数据库
        # 
        conn = sqlite3.connect(gStorageName)
        cmdStr = " select * from sqlite_master where type='table' ";
        cursor = conn.execute(cmdStr)

        if -1 == cursor.rowcount: # 未建表
            print('开始建数据库表')
            tableNameList = []

            nowYear = time.strftime("%Y", time.gmtime())

            index = 1
            size = int(nowYear) - gStartYear

            for year in range(gStartYear, int(nowYear)):
                cmdCreateTable = gCmdHeadCreateTable + str(year) + gTableFormat
                conn.execute(cmdCreateTable)
                print(cmdCreateTable)
                print('%4.2f%%' % (100.0 * index / size))
                index += 1

        print('db connectted.')

if __name__ == '__main__':
    db = WBDPStorage()
    print('WBDPStorage 测试!')




