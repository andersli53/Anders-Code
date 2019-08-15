#PIC 16
#Assignment 2F
#Li, Chak Yin (Anders)
#704950093

import time

def my_divide1(a,b):
    return [i/j for i, j in zip(a,b)]
    
def my_divide2(a,b):
    if all(i % j == 0 for i, j in zip(a, b)):
        return [i/j for i, j in zip(a,b)]
    else:
        print "Something's wrong with the inputs to my_divide2"
        return []

def my_divide3(a,b):
    try:
        return [i/j for i, j in zip(a,b)]
    except (ZeroDivisionError,TypeError) as e:
        print "Something's wrong with the inputs to my_divide3"
        return []
    
def my_divide4(a,b):
    try:
        return [i/j for i, j in zip(a,b)]
    except ZeroDivisionError as e:
        print "There is a zero in b"
        return []
    except TypeError as e:
        print "Non-numeric data detected"
        return []

#%%
a1 = range(0,1000000); b1 = range(1,1000001)

time1 = []
for t in xrange(100):
    begin = time.clock()
    my_divide2(a1,b1)
    end = time.clock()
    time1.append(end - begin)

time2 = []
for t in xrange(100):
    begin = time.clock()
    my_divide3(a1,b1)
    end = time.clock()
    time2.append(end - begin)


#%%
a2 = range(0,1000000); b2 = range(1,1000000)+ [0]

time4 = []
for t in xrange(100):
    begin = time.clock()
    my_divide2(a2,b2)
    end = time.clock()
    time4.append(end - begin)

time5 = []
for t in xrange(100):
    begin = time.clock()
    my_divide3(a2,b2)
    end = time.clock()
    time5.append(end - begin)


#%%
a3 = range(0,1000000); b3 = range(1,1000000)+ ['a']
time7 = []
for t in xrange(100):
    begin = time.clock()
    my_divide2(a3,b3)
    end = time.clock()
    time7.append(end - begin)

time8 = []
for t in xrange(100):
    begin = time.clock()
    my_divide3(a3,b3)
    end = time.clock()
    time8.append(end - begin)

    
print "my_divide2 average time on a1,b1:", sum(time1)/len(time1)
print "my_divide3 average time on a1,b1:", sum(time2)/len(time2)

print "my_divide2 average time on a2,b2:", sum(time4)/len(time4)
print "my_divide3 average time on a2,b2:", sum(time5)/len(time5)

print "my_divide2 average time on a3,b3:", sum(time7)/len(time7)
print "my_divide3 average time on a3,b3:", sum(time8)/len(time8)







