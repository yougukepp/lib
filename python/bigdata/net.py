#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import urllib.request

g_gdp_url = 'http://api.worldbank.org/zh/countries/all/indicators/NY.GDP.MKTP.CD?format=json&per_page=10&page=1'
g_population_url = 'http://api.worldbank.org/zh/countries/all/indicators/SP.POP.TOTL?format=json&per_page=10&page=1'

if __name__ == '__main__':
    response = urllib.request.urlopen(g_gdp_url)
    buff = response.read()
    json = buff.decode("utf8")
    print(json)

