#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import urllib.request

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
            }

    def __init__(self):
        pass

    def update(self):
        url = self.MakeUrl('英文', 'json', '指标')
        #mkurl('中文', 'json', '指标')

        print('WBDPSpider update')
        print(url) 
        
        response = urllib.request.urlopen(url)
        buff = response.read()
        buff_utf8 = buff.decode('utf8')
        data = json.loads(buff_utf8) 
        print(data[0])
        #print(data[1])

        #return data

    def MakeUrl(self, languageKey, formatKey, dataNameKey):
        url = self.sBaseUrl
        url += '/' + self.GetLanguage(languageKey)
        url += '/' + self.GetDtaName(dataNameKey)
        url += '/?' + self.GetFormat(formatKey)

        return url

    def  GetLanguage(self, languageKey):
        return self.sLanguage[languageKey]

    def  GetFormat(self, formatKey):
        return self.sFormat[formatKey]

    def  GetDtaName(self, dataNameKey):
        return self.sDataName[dataNameKey]

if __name__ == '__main__':
    spider = WBDPSpider()
    spider.update()


