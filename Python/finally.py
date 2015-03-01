import time

try:
    f = file('poem.txt')
    while True:
        line = f.readline()
        if len(line) == 0:
            break
        time.sleep(2)
        print line,
except IOError:
    print 'IOError'
finally:
    f.close()
    print 'Cleaning up...closed the file'
