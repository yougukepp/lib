#!/usr/bin/env python3
# -*- coding: utf-8 -*-

gHeadIndex = 0
gContentIndex = 1
gPageMaxKey = 'pages'

class WBDPDataer: 
    def __init__(self, data):
        self.mData = data

    def GetPageMax(self):
        head = self.GetHead()
        return head[gPageMaxKey] 
    
    def Parse2List(self, keyName):
        rstList = []
        content = self.GetContent()
        for item in content:
            #print(item)
            #print(keyName)
            #print(item[keyName])
            if item[keyName]:
                rstList.append(item[keyName])

        return rstList

    def Show(self):
        head = self.GetHead()
        content = self.GetContent()
        print('头部:')
        print(head)

        print('内容:')
        """
        for item in content:
            if item['name']:
                print(item['name'])
        """

    def GetHead(self):
        return self.mData[gHeadIndex]

    def GetContent(self):
        return self.mData[gContentIndex]

if __name__ == '__main__':
    dataer = WBDPDataer(None)
    print('Use WBDPSpider test me.')
    dataer.print()

