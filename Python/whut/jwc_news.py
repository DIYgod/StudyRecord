# -*- coding: utf-8 -*-

import string
import urllib2
import re
import time
import smtplib
from email.mime.text import MIMEText

mailto_list = ['306578968@qq.com']
mail_host = 'smtp.qq.com'
mail_user = '306578968@qq.com'
mail_pass = '199506090512mmqq'

def send_mail(to_list, sub, content):
    msg = MIMEText(content, _subtype = 'html', _charset = 'utf-8')
    msg['Subject'] = sub
    msg['From'] = mail_user
    msg['To'] = ';'.join(to_list)
    try:
        s = smtplib.SMTP()
        s.connect(mail_host)
        s.login(mail_user, mail_pass)
        s.sendmail(mail_user, to_list, msg.as_string())
        s.close()
        return True
    except Exception, e:
        print str(e)
        return False

def GetNews():
    url = 'http://jwc.whut.edu.cn/'
    req = urllib2.Request(url)
    page = urllib2.urlopen(req).read()
    p = re.compile(r'<a class="pad_left" href="(.*?)" title=".*?">(.*?)</a><span class="pad_right" >(.*?)</span>')
    items = p.findall(page)
    news = []
    for item in items:
        if(item[2] == time.strftime('%Y-%m-%d',time.localtime(time.time()))):
            news.append([item[0], item[1], item[2]])
    return news

news = GetNews()
if news:
    sub = 'WHUT教务处最新通知推送（来自Anotherhome）' + time.strftime('%Y-%m-%d',time.localtime(time.time()))
    content = 'WHUT最新通知:<br><br>'
    for item in news:
        content += item[2]
        content += '  '
        content += item[1]
        content += '  '
        content += item[0]
        content += '<br>'
    content += ' （校内资源，请用校园网或VPN访问）  '
    if send_mail(mailto_list, sub, content):
        print 'Succeed'
    else:
        print 'Fail'
else:
    print 'None'
