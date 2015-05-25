import urllib
import urllib2
import cookielib

cookie = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cookie))

postdata = urllib.urlencode({
    'systemId':'',
    'xmlmsg':'',
    'userName':'0121202750326',
    'password':'0121202750326',
    'type':'xs',
    'imageField.x':'60',
    'imageField.y':'19'
})

req = urllib2.Request(
    url = 'http://sso.jwc.whut.edu.cn/Certification/login.do',
    data = postdata
)

result = opener.open(req)

print result.read()

for item in cookie:
    print 'Name = '+item.name
    print 'Value = '+item.value

result = opener.open('http://202.114.90.180/Score/login.do')
print result.read()

result = opener.open('http://202.114.90.180/Score')
result = opener.open('http://202.114.90.180/Score/')
result = opener.open('http://sso.jwc.whut.edu.cn/certification.do?systemId=03&msg=OsA1NZeonoVERzutbtUWlGP%2BOOf9rkdEJKPq%2BOPqmBDrxQ8HNg97ZgaTDM6E2cxZKHKjrjNS6W6W%0Ad38BUCuXzfLKaA7EDBhh1wzKLfC18HUX5%2FdJDBaPA2a5%2Fn2W83bkFEZwn3Bk06rk8jyqLbisSYri%0AxZpeAgAOJYHe9BlutG4%3D%0A%23Nq9aFLsYIIGAp3lLrsrxviocS6Vh8yXtVgW0K8xi3WnSBmKKtaxrSa2wCc3aCngV5ELslshQec8n%0AKxKXWlM59FHmbk%2Bu11mTKh8IeRctfNnhkRFWAw%2BcMxXL7IkHpS09UlOqJMzHHzenyZiBU40Fru46%0A751%2BfFsrGMqQx0jRzCI%3D%0A%23vDsjRptpdHGlDy0tSm0ET7XmanxVSY2OlGxlHo1GQSpMnD6qI1zy6Qzy7Ym61v2tmFCCUkRd3oAJ%0Ao0oZ%2Bt0ORFomngjkZuZJ3ikQJVcmqbi10pToYo0AsePE3rBYAgILaqPjkJl2FnJZ37hpHdE5QE%2Fw%0AvfG23SI3D%2FGeXhXJH8g%3D%0A%23F0zVff3tKg5k8GlEgMjxFOu9Lu8ABmod80AdEHMkGRX%2F8FPdl1I0Zjnwggl4kYF8wZGCLijFJ2G3%0AdB0jJInt7acQAHQXa3RHX3KqRimgif4XG%2BN1JByVdSL%2BQH3%2F10oupxgKax4kzuc8wix9RUNII3Rj%0AI8yIkQuw8NkRc%2Ft4WvU%3D%0A%23RSXBaL7jSkgWgxi%2B9RUZcB%2BQueeuEmJaZI%2B1IJ0gkbmCo%2BPJ4IGmAR23Wg%2BkbtxQAPCzjo3rSoT7%0ASCBQgdOPTBSCAoph1XMSgRoEE7ZAk%2FBf4wWGuWcMIb1vYZzxC2T%2BVdDyuj9JFjOhG0GGaHRLwVTn%0AirzEtnLp%2Fc%2BSnneQG9g%3D%0A%23')
result = opener.open('http://sso.jwc.whut.edu.cn/Certification//certification.do?systemId=03&msg=OsA1NZeonoVERzutbtUWlGP%2BOOf9rkdEJKPq%2BOPqmBDrxQ8HNg97ZgaTDM6E2cxZKHKjrjNS6W6W%0Ad38BUCuXzfLKaA7EDBhh1wzKLfC18HUX5%2FdJDBaPA2a5%2Fn2W83bkFEZwn3Bk06rk8jyqLbisSYri%0AxZpeAgAOJYHe9BlutG4%3D%0A%23Nq9aFLsYIIGAp3lLrsrxviocS6Vh8yXtVgW0K8xi3WnSBmKKtaxrSa2wCc3aCngV5ELslshQec8n%0AKxKXWlM59FHmbk%2Bu11mTKh8IeRctfNnhkRFWAw%2BcMxXL7IkHpS09UlOqJMzHHzenyZiBU40Fru46%0A751%2BfFsrGMqQx0jRzCI%3D%0A%23vDsjRptpdHGlDy0tSm0ET7XmanxVSY2OlGxlHo1GQSpMnD6qI1zy6Qzy7Ym61v2tmFCCUkRd3oAJ%0Ao0oZ%2Bt0ORFomngjkZuZJ3ikQJVcmqbi10pToYo0AsePE3rBYAgILaqPjkJl2FnJZ37hpHdE5QE%2Fw%0AvfG23SI3D%2FGeXhXJH8g%3D%0A%23F0zVff3tKg5k8GlEgMjxFOu9Lu8ABmod80AdEHMkGRX%2F8FPdl1I0Zjnwggl4kYF8wZGCLijFJ2G3%0AdB0jJInt7acQAHQXa3RHX3KqRimgif4XG%2BN1JByVdSL%2BQH3%2F10oupxgKax4kzuc8wix9RUNII3Rj%0AI8yIkQuw8NkRc%2Ft4WvU%3D%0A%23RSXBaL7jSkgWgxi%2B9RUZcB%2BQueeuEmJaZI%2B1IJ0gkbmCo%2BPJ4IGmAR23Wg%2BkbtxQAPCzjo3rSoT7%0ASCBQgdOPTBSCAoph1XMSgRoEE7ZAk%2FBf4wWGuWcMIb1vYZzxC2T%2BVdDyuj9JFjOhG0GGaHRLwVTn%0AirzEtnLp%2Fc%2BSnneQG9g%3D%0A%23')
result = opener.open('http://202.114.90.180/Score/login.do?msg=tIn6N2XcWh0ph2Plcvn2JS4d9hg%2BmuCF2ugR0LKBFjIliuIUSS9WHtWq%2BdJGtKbLZwydy4eEW2%2Fw%0AhhzDHiE8qpGHC07V72okZkkp7YynBo3Xmp5Vmqen%2FsSKPRTDWq3gWYl89dor6u377wA%2Br%2B92QaHk%0APfVs5rD2wNpfibnY%2BkU%3D%0A%23pHVPwXemYiQ1g2jrxseoLI4xliErxUWWBMp%2FbGPz49seW8MyCRi3C4EHBueGPX5cqIxXqETvcDNw%0AmHQns0ltTKiPhlk8Xy0n0D7iNSQgiT3dfZudbwrTUdRGQCI6rDUnjMoheBHc3rn1XpURpPvIsZor%0Ak%2FU%2FqyLuei71uLPSdhw%3D%0A%23nS8AkpkCffDOSGB6eShavXAOWGcaxhr2ysICD8MEmvx%2BaHk7yFy7L5%2BQh3zRTAN3kHhsKyuRTlYe%0Ag%2Fhr3FlXVuRIyPiaGvosADJerqMw57Dtq2y5AZWek4swsHuiH9L6OeluWEVXA076nQxqdLTlp6En%0AylLNIKhZVRzFaCFAoLg%3D%0A%23PeQkgzizHA0rjMihgKqv1EvOzSLdr4Ah8r6IicsJegGmju2sdijEoxpYLpejsJoEBW68UBrDbEAs%0AQWJIqBgF9Ngsu%2BbqVxwIyVNOhx9ZJugdP18LfDBhrruqIy26MFFuk9nLhuu9kjSab5acwF3Fy5MP%0A%2FNYpc8g3koZ9bBG%2FPSs%3D%0A%23qJCWAvf2tikcAddNFA9pOMRMD%2ByTL9w8yX6sTGSBuHp%2BQ5EBIS2icd9m4yVm0SVbULd2uCddsLjF%0A3DY3wx5c7lhtBmLUyd%2B8EpUBuh3fbKaCUnND8u21ddBMv5mge26d4rPXmjje9wI4c%2FQUj3aEmJdU%0AGANqy4ofskMHew188V8%3D%0A%23')
result = opener.open('http://202.114.90.180/Score/lscjList.do')

print result.read()

cookie.clear()
