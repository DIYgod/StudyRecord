import datetime

def NextDate(year, mon, day):
    thisdate = datetime.datetime(year, mon, day)
    twoday = datetime.timedelta(days = 2)
    nextdate = thisdate + twoday
    print 'The next date is:'
    print nextdate.strftime('%Y-%m-%d')

if __name__ == '__main__':
    day = raw_input('Please input a date (eg: 2015-04-01):\n').split('-')
    NextDate(int(day[0]), int(day[1]), int(day[2]))
