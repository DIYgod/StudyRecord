# coding=utf-8

import string
import urllib2
import re

# Handling label
class HTML_Tool:
    BgnCharToNoneRex = re.compile('(\t|\n| |<a.*?>|<img.*>)')
    EndCharToNoneRex = re.compile('<.*?>')
    BgnPartRex = re.compile('<p.*?>')
    CharToNewLineRex = re.compile('(<br/>|</p>|<tr>|<div>|</div>)')
    CharToNextTabRex = re.compile('<td>')

    replaceTab = [('&lt;', '<'), ('&gt;', '>'), ('&amp;', '&'), ('&amp;', '\"'), ('&nbsp;', ' ')]

    def Replace_Char(self, x):
        x = self.BgnCharToNoneRex.sub('', x)
        x = self.BgnPartRex.sub('\n    ', x)
        x = self.CharToNewLineRex.sub('\n', x)
        x = self.CharToNextTabRex.sub('\t', x)
        x = self.EndCharToNoneRex.sub('', x)

        for t in self.replaceTab:
            x = x.replace(t[0], t[1])
        return x

class Baidu_Spider:
    def __init__(self, url):
        self.myURL = url + '?see_lz=1'
        self.datas = []
        self.myTool = HTML_Tool()
        print 'Link Start'

    # Loading and storing
    def baidu_tieba(self):
        myPage = urllib2.urlopen(self.myURL).read().decode('utf-8')
        endPage = self.page_counter(myPage)
        title = self.find_title(myPage)
        print 'Title: ' + title
        self.save_date(self.myURL, title, endPage)

    # Calculate the number of pages
    def page_counter(self, myPage):
        myMatch = re.search(r'<span class="red">(\d+?)</span>', myPage, re.S)
        if myMatch:
            endPage = int(myMatch.group(1))
            print 'There are %d pages' % endPage
        else:
            print 'Failed to load page number'
        return endPage

    def find_title(self, myPage):
        myMatch = re.search(r'<h1.*?>(.*?)</h1>', myPage, re.S)
        title = 'No title'
        if myMatch:
            title = myMatch.group(1)
        else:
            print 'Failed to load title'
        title = title.replace('\\', '').replace('/', '').replace(':', '').replace('*', '').replace('?', '').replace('"', '').replace('>', '').replace('<', '').replace('|', '')
        return title

    def save_date(self, url, title, endPage):
        self.get_data(url, endPage)
        f = open(title+'.txt', 'w+')
        f.writelines(self.datas)
        f.close()
        print 'Download and store as txt file'
        print 'Press Any Key To Exit'
        raw_input()

    def get_data(self, url, endPage):
        url = url + '&pn='
        for i in range(1, endPage+1):
            print 'Spider No.%d is working' % i
            myPage = urllib2.urlopen(url + str(i)).read().decode('utf-8')
            self.deal_date(myPage)

    def deal_date(self, myPage):
        myItems = re.findall('id="post_content.*?>(.*?)</div>', myPage, re.S)
        for item in myItems:
            data = self.myTool.Replace_Char(item.replace('\n', '').encode('utf-8'))
            self.datas.append(data+'\n')

print u"""#---------------------------------------
#   程序：百度贴吧爬虫
#   版本：0.5
#   作者：why
#   日期：2013-05-16
#   语言：Python 2.7
#   操作：输入网址后自动只看楼主并保存到本地文件
#   功能：将楼主发布的内容打包txt存储到本地。
#---------------------------------------
"""

print '请输入贴吧的地址最后的数字串: '
bdurl = 'http://tieba.baidu.com/p/' + str(raw_input('http://tieba.baidu.com/p/'))

mySpider = Baidu_Spider(bdurl)
mySpider.baidu_tieba()
