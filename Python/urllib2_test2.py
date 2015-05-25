import urllib2

req = urllib2.Request('http://www.avast.com')

try:
    urllib2.urlopen(req)
except urllib2.URLError, e:
    print e.code
