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

if send_mail(mailto_list, 'Hello', 'Test mail'):
    print 'Succeed'
else:
    print 'Fail'
