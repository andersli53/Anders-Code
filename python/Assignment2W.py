#PIC 16
#Assignment 2W
#Li, Chak Yin (Anders)
#704950093

import time

N = 99999
def f(x):
    return x**2

x = range(N)
y = []

timeF = []
for t in range(100):
    begin = time.clock()
    for i in x:
        y.append(f(i))
    end = time.clock()
    timeF.append(end - begin)

print "For loop w/ function call :", sum(timeF)/len(timeF)



#%%

timeG = []
for t in range(100):
    lst = []
    g = lambda i : i**2
    begin = time.clock()
    for i in x:
        lst.append(g(i))
    end = time.clock()
    timeG.append(end - begin)

print "For loop w/ lambda function call :", sum(timeG)/len(timeG)

#%%

timeW = []
for t in range(100):
    lst2 = []
    begin = time.clock()
    for i in x:
        lst2.append(i**2)
    end = time.clock()
    timeW.append(end - begin)
    
print "For loop w/o function call :", sum(timeW)/len(timeW)



#%%


timeL = []
for t in range(100):
    l = range(N)
    begin = time.clock()
    for i in range(len(l)):
        l[i] = l[i]**2
    end = time.clock()
    timeL.append(end - begin)
    
print "For loop w/ existing list : ", sum(timeL)/len(timeL)

#%%


timeJ = []
for t in range(100):
    begin = time.clock()
    j = [f(i) for i in x]
    end = time.clock()
    timeJ.append(end - begin)
    
print "List comp w/ function call :", sum(timeJ)/len(timeJ)


#%%

timeC = []
for t in range(100):
    begin = time.clock()
    c = [(lambda i: i**2)(i) for i in x]
    end = time.clock()
    timeC.append(end - begin)
    
print "List comp w/ lambda function call :", sum(timeC)/len(timeC)

#%%

timeH = []
for t in range(100):
    begin = time.clock()
    h = [v ** 2 for v in x]
    end = time.clock()
    timeH.append(end - begin)
    
print "List comp w/o  function call :", sum(timeH)/len(timeH)


#%%

timeM = []
for t in range(100):
    begin = time.clock()
    m = map(f, x)
    end = time.clock()
    timeM.append(end - begin)
    
print "Map w/ function call :", sum(timeM)/len(timeM)


#%%


time1 = []
for t in range(100):
    begin = time.clock()
    b = map(lambda i: i**2, range(N))
    end = time.clock()
    time1.append(end - begin)

print "Map w/ lambda function call :", sum(time1)/len(time1)

time2 = []
for t in range(100):
    begin = time.clock()
    h = [i**2 for i in range(N)]
    end = time.clock()
    time2.append(end - begin)

print "List comp w/o function call :", sum(time2)/len(time2)

#%%

def u(x,y):
    return x+y

time3 = []
for t in range(100):
    begin = time.clock()
    b = map(u, range(N), range(N))
    end = time.clock()
    time3.append(end - begin)

print "Map w/ function call :", sum(time3)/len(time3)

l1 = range(N)
l2 = range(N)
time4 = []
for t in range(100):
    begin = time.clock()
    h = [l1[i] + l2[i] for i in range(0, len(l1))]
    end3 = time.clock()
    time4.append(end - begin)

print "List comp w/o function call :", sum(time4)/len(time4)









