#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sqlite3

gDbName="db.sqlite3"

class ATDataBase:
    mCur = None
    def __init__(self, dbName): 
        needCreateTable = True
        if os.path.exists(dbName):
            needCreateTable = False 
            
        con = sqlite3.connect(dbName)
        self.mCur = con.cursor() 
        
        if needCreateTable:
            tableHeader={"id":"INTEGER PRIMARY KEY", "value":"VARCHAR(20)"}
            self.CreatTable("AT", tableHeader)
            #使用成员函数
            self.InsertRow()
            cmd = 'INSERT INTO foo (o_id, fruit, veges) VALUES(NULL, "apple", "broccoli")'
            Execute(cmd)

    def CreatTable(self, tableName, tableHeader):
        #TODO:参数检查
        cmd = "CREATE TABLE" + tableName + foo (o_id INTEGER PRIMARY KEY, fruit VARCHAR(20), veges VARCHAR(30))'
        Execute(cmd)
        pass

    def InsertRow(Row):
        pass

    def Execute(cmd):
        con.commit()
        pass

"""
import sqlite3

conn = sqlite3.connect("D:/aaa.db")
conn.isolation_level = None #这个就是事务隔离级别，默认是需要自己commit才能修改数据库，置为None则自动每次修改都提交,否则为""
# 下面就是创建一个表
conn.execute("create table if not exists t1(id integer primary key autoincrement, name varchar(128), info varchar(128))")
# 插入数据
conn.execute("insert into t1(name,info) values ('zhaowei', 'only a test')")
# 如果隔离级别不是自动提交就需要手动执行commit
conn.commit()
# 获取到游标对象
cur = conn.cursor()
# 用游标来查询就可以获取到结果
cur.execute("select * from t1")
# 获取所有结果
res = cur.fetchall()
print 'row:', cur.rowcount
# cur.description是对这个表结构的描述
print 'desc', cur.description
# 用fetchall返回的结果是一个二维的列表
for line in res:
    for f in line:
        print f,
    print
print '-'*60

cur.execute("select * from t1")
# 这次查询后只取一个结果，就是一维列表
res = cur.fetchone()
print 'row:', cur.rowcount
for f in res:
    print f,
print
# 再取一行
res = cur.fetchone()
print 'row:', cur.rowcount
for f in res:
    print f,
print
print '-'*60


cur.close()
conn.close()
"""


if __name__ == '__main__':
    cur.execute('SELECT * FROM foo')
    print(cur.fetchall())

