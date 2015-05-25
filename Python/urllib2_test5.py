from urllib2 import Request, urlopen, URLError, HTTPError

url = 'http://www.anotherhome.net'
req = Request(url)
response = urlopen(req)
print 'Info:'
print response.info()
