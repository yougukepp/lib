#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import urllib.request

g_gdp_url = 'http://api.worldbank.org/zh/countries/all/indicators/NY.GDP.MKTP.CD?format=json&per_page=10&page=1'
g_population_url = 'http://api.worldbank.org/zh/countries/all/indicators/SP.POP.TOTL?format=json&per_page=10&page=1'

if __name__ == '__main__':
    head_index = 0
    content_index = 1
    total_key = 'total'
    date_key = 'date'
    country_key = 'country'
    country_v_key = 'value'
    value_key = 'value'

    response = urllib.request.urlopen(g_gdp_url)
    buff = response.read()
    buff_utf8 = buff.decode("utf8")
    data = json.loads(buff_utf8)

    # 生成头 和 内容
    head = data[head_index]
    content_all = data[content_index]
    # 获取所有内容(content)数目
    total = head[total_key]

    #print(data)

    get_count = 0
    print("共有 %d 个数据项目:" % total)
    for content in content_all:
        date = content[date_key]
        country = content[country_key][country_v_key]
        value = content[value_key]

        print(date, country, value)

        get_count += 1

    print("获取 %d:" % get_count)

