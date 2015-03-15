#coding:utf-8

import string, urllib2

def baidu_tieba(url, begin_page, end_page):
    for i in range(begin_page, end_page+ 1 ):
        sName = 'page' + str(i) + '.html'
        print 'Download ' + str(i) + ' page, and store it as ' + sName + '......'
        f = open(sName, 'w+')
        m = urllib2.urlopen(url + str(i)).read()
        f.write(m)
        f.close()

bdurl = str(raw_input('请输入贴吧的地址，去掉pn=后面的数字：\n'))
begin_page = int(raw_input('请输入开始的页数：\n'))
end_page = int(raw_input('请输入终点的页数：\n'))

baidu_tieba(bdurl, begin_page, end_page)
