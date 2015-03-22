# -*- coding:utf-8 -*-

import urllib2
import re
import string
import smtplib
import os
from email.mime.text import MIMEText


def send_mail(to_list, sub, content):
    mail_host = 'smtp.gmail.com'
    mail_user = 'diy.d.god@gmail.com'
    mail_pass = 'kielqxynvplcljvb'
    msg = MIMEText(content, _subtype = 'html', _charset = 'utf-8')
    msg['Subject'] = sub
    msg['From'] = mail_user
    msg['To'] = ';'.join(to_list)
    try:
        s = smtplib.SMTP()
        s.connect(mail_host)
        s.ehlo()
        s.starttls()
        s.login(mail_user, mail_pass)
        s.sendmail(mail_user, to_list, msg.as_string())
        s.close()
        return True
    except Exception, e:
        print str(e)
        return False

def GetError():
    url = 'http://www.anotherhome.net/'
    req = urllib2.Request(url)
    page = urllib2.urlopen(req).read()
    print page
    r = re.compile(r'<title>数据库错误</title>')
    return r.match(page)

mailto_list = ['306578968@qq.com']

if GetError():
    content = '检测到数据库错误 <br> '
    os.system('service mysql restart')
    content += '正在尝试自动修复 <br>'
    if GetError():
        content += '自动修复失败，请连接服务器(ssh root@106.187.98.70)手动修复'
        sub = '紧急!!!!!数据库错误!!!!!'
    else:
        content += '自动修复成功'
        sub = '数据库错误已自动修复'
    print content
    send_mail(mailto_list, sub, content)

else:
    print 'Succeed'
