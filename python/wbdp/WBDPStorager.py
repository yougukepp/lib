#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sqlite3
import time
from WBDPSpider import WBDPSpider

gTableNameInDataBase = 1

# 表名 year年
# 举例 year_2013_table

gStorageName = 'wbdp.db'
gStartYear = 1960

gCmdHeadCreateTable = "CREATE TABLE " 

gYearTableFormat= """ (ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL,
                       COUNTRIES_ID       TEXT                NOT NULL,
                       INDICATORS_ID      TEXT                NOT NULL,
                       VALUAE             REAL                NOT NULL);"""

gCountriesTableFormat= """ (ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL,
                            COUNTRIES_ID       TEXT                NOT NULL UNIQUE);"""

gIndicatorsTableFormat= """ (ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL,
                             INDICATORS_ID      TEXT                NOT NULL UNIQUE);"""

class WBDPStorage:
    def __init__(self):
        #
        # 新建数据库
        # 
        tableList = []
        tableList = self.GetTableList()
        print(tableList)

        if 0 == len(tableList): # 未建表 则建表
            print('开始建数据库表')
            conn = sqlite3.connect(gStorageName)
            # 国家表
            cmdCreateTable = gCmdHeadCreateTable + 'countries_table' + gCountriesTableFormat
            conn.execute(cmdCreateTable)
            # 指标表
            cmdCreateTable = gCmdHeadCreateTable + 'indicators_table' + gIndicatorsTableFormat
            conn.execute(cmdCreateTable)

            # 年表
            tableNameList = []

            nowYear = time.strftime("%Y", time.gmtime())

            index = 1
            size = int(nowYear) - gStartYear 
            for year in range(gStartYear, int(nowYear)):
                cmdCreateTable = gCmdHeadCreateTable + 'year_' + str(year) + '_table' + gYearTableFormat
                conn.execute(cmdCreateTable)
                #print(cmdCreateTable)
                print('%4.2f%%' % (100.0 * index / size))
                index += 1

    
    def GetTableList(self):
        tableList = []

        conn = sqlite3.connect(gStorageName)
        cmdStr = "select * from sqlite_master where type='table'"
        cursor = conn.execute(cmdStr)
        data = cursor.fetchall()
        for d in data:
            tableList.append(d[gTableNameInDataBase])

        return tableList

    def UpdateIndexTable(self, dataName, dataList):
        if '国家' == dataName: 
            print(dataName)
        elif '指标' == dataName:
            print(dataName)
        else:
            print(dataName)


if __name__ == '__main__':
    db = WBDPStorage()
    print('WBDPStorage 测试!')




