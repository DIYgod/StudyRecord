import urllib2
req = urllib2.Request('http://www.zhihu.com')
response = urllib2.urlopen(req)
html = response.read()
print html
