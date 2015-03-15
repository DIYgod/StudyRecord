# coding=utf-8

import urllib2
import urllib
import re
import thread
import time

class Spider_Model:
    def __init__(self):
        self.page = 1
        self.pages = []
        self.enable = False

    def GetPage(self, page):
        myURL = 'http://www.qiushibaike.com/hot/page/' + page
        headers = {'User-Agent' : 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'}
        req = urllib2.Request(myURL, headers = headers)
        myResponse = urllib2.urlopen(req)
        myPage = myResponse.read()

        # unicodePage = myPage.decode('utf-8')

        myItems = re.findall('<div.*?class="content".*?title="(.*?)">(.*?)</div>', myPage, re.S)
        items = []
        for item in myItems:
            items.append([item[0].replace('\n', ''), item[1].replace('\n', '')])
        return items

    def LoadPage(self):
        while self.enable:
            if len(self.pages) < 2:
                try:
                    myPage = self.GetPage(str(self.page))
                    self.page += 1
                    self.pages.append(myPage)
                except:
                    print '无法链接糗事百科'
            else:
                time.sleep(1)

    def ShowPage(self, nowPage, page):
        for items in nowPage:
            print '第%d页' % page, items[0], items[1]
            myInput = raw_input()
            if myInput == 'quit':
                self.enable = False
                break

    def Start(self):
        self.enable = True
        page = self.page

        print '正在加载中请稍候......'

        thread.start_new_thread(self.LoadPage, ())

        while self.enable:
            if self.pages:
                nowPage = self.pages[0]
                del self.pages[0]
                self.ShowPage(nowPage, page)
                page += 1

print """
---------------------------------------
   程序：糗百爬虫
   版本：0.3
   作者：why
   日期：2014-06-03
   语言：Python 2.7
   操作：输入quit退出阅读糗事百科
   功能：按下回车依次浏览今日的糗百热点
---------------------------------------
"""
print '请按下回车浏览今日的糗事百科'
raw_input(' ')
myModel = Spider_Model()
myModel.Start()
