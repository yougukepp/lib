#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import urllib.request

g_gdp_url = 'http://api.worldbank.org/zh/countries/all/indicators/NY.GDP.MKTP.CD?format=json&per_page=10&page=1'
g_population_url = 'http://api.worldbank.org/zh/countries/all/indicators/SP.POP.TOTL?format=json&per_page=10&page=1'

if __name__ == '__main__':
    response = urllib.request.urlopen(g_gdp_url)
    buff = response.read()
    buff_utf8 = buff.decode("utf8")
    data = json.loads(buff_utf8)

    print(data)

    head = data[0]
    content = data[1]
    total = head['total']

    print(total)

    for v in content:
        print(v)

