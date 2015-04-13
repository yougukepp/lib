#!/usr/bin/env python3
# -- coding utf-8 --

import csv

a_country_data = {}
all_gdp_data = {}
all_population_data = {}

with open('gdp.csv', newline='', encoding='utf-8') as f:
    reader = csv.reader(f)
    for row in reader:

        for i in range(1980, 2014):
            index = i - 1976
            if '..' == row[index]:
                print("here")
                print(row[2])
                print(i)
                a_country_data[i] = None
            else:
                a_country_data[i] = row[index]

        all_gdp_data[row[2]] = a_country_data
# {国家:{年:gdp}}
#print(all_gdp_data)

for c in all_gdp_data:
    if '阿富汗' == c:
        print(all_gdp_data[c])

"""

# {国家:{年:population}}
#print(all_population_data)

# {年:{国:[gdp,population]}}
country_list = []
for c in all_gdp_data:
    country_list.append(c)

result = {}
for y in range(1980, 2014):
    result[y] = {}

for y in range(1980, 2014):
    for c in country_list:
        print(y)
        print(c)
        print(all_gdp_data[c][y])
        print(all_gdp_data[c])

        #gdp = all_gdp_data[c][y]
        #population = all_population_data[c][y]
        #result[y][c] = (gdp, population)
print(all_gdp_data)
#print(result)
"""
