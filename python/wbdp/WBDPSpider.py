#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import urllib.request

from WBDPDataer import WBDPDataer

# per_page 使用默认值 50

class WBDPSpider:
    sBaseUrl = 'http://api.worldbank.org/'

    sLanguage ={
            '英文' : 'en',
            '中文' : 'zh',
            }

    sFormat = {
            'json' : 'format=json',
            }

    sDataName = {
            '指标' : 'indicators',
            '国家' : 'countries',
            }

    #国家
    #http://api.worldbank.org/countries
    #指标
    #http://api.worldbank.org/indicators
    #gdp
    #http://api.worldbank.org/countries/all/indicators/NY.GDP.MKTP.CD
    #人口
    #http://api.worldbank.org/countries/all/indicators/SP.POP.TOTL

    def __init__(self):
        pass

    def GetAllCountriesList(self):
        countriesList = []
        pageMax = self.GetPageMax()
        pageMax += 1 # range [min, max) 
        
        print('获取国家列表:     ')
        for page in range(1, pageMax):
            url = self.MakeUrl('国家', page=page)
            data = self.GetData(url) 
            dataer = WBDPDataer(data)
            lst = dataer.Parse2List('name')
            countriesList += lst
            print('%4.2f%%' % (100.0 * page / (pageMax - 1)))

        #print(countriesList)

        return countriesList

    def GetPageMax(self):
        url = self.MakeUrl('国家')
        data = self.GetData(url)
        dataer = WBDPDataer(data)
        pageMax = dataer.GetPageMax()

        return pageMax

    def GetData(self, url):
        response = urllib.request.urlopen(url)
        buff = response.read()
        buff_utf8 = buff.decode('utf8')
        data = json.loads(buff_utf8) 

        return data

    """
    def Update(self):
        self.count = self.GetCount()

        #url = self.MakeUrl('英文', 'json', '指标')
        #url = self.MakeUrl('中文', 'json', '国家', 2)
        url = self.MakeUrl('中文', 'json', '国家')

        print(url) 
        
        response = urllib.request.urlopen(url)
        buff = response.read()
        buff_utf8 = buff.decode('utf8')
        data = json.loads(buff_utf8) 

        wbdpDataer = WBDPDataer(data)
        wbdpDataer.print()
        #return data

    def GetCount(self):
        pass
    """

    def MakeUrl(self, dataNameKey, formatKey='json', languageKey='中文', page=1):
        url = self.sBaseUrl
        url += '' + self.GetLanguage(languageKey)
        url += '/' + self.GetDtaName(dataNameKey)
        url += '/?' + self.GetFormat(formatKey)
        url += '&page=' + str(page)

        return url

    def  GetLanguage(self, languageKey):
        return self.sLanguage[languageKey]

    def  GetFormat(self, formatKey):
        return self.sFormat[formatKey]

    def  GetDtaName(self, dataNameKey):
        return self.sDataName[dataNameKey]

if __name__ == '__main__':
    spider = WBDPSpider()
    spider.GetAllCountriesList()

