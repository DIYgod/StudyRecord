import time

def performance(unit):
    def pref_decorator(f):
        def wrapper(*args, **kw):
            t1 = time.time()
            r = f(*args, **kw)
            t2 = time.time()
            if unit == 'ms':
                t = (t2 - t1) * 1000
            elif unit == 's':
                t = (t2 - t1)
            print 'call %s() in %f%s' % (f.__name__, t, unit)
        return wrapper
    return pref_decorator

@performance('ms')
def factorial(n):
    return reduce(lambda x,y: x*y, range(1, n+1))

print factorial(10)
