#PIC 16
#Assignment 3M
#Li, Chak Yin (Anders)
#704950093

class MathVector:

    def __init__(self, *data):
        if len(data) == 1:
            self.vector = [0 for i in range(len(data))]
        elif type(data) is list or tuple:
            self.vector = [i for i in data]
        else:
            pass

    def get_el(self, i):
        return self.vector[i-1]

    def neg(self):
        self.vector = [i*-1 for i in self.vector]
        return self.vector

    def mag(self):
        return (sum(i**2 for i in self.vector))**(1/2)

    def dot(self, y):
        x = sum(i*j for i,j in zip(self.vector,y))
        return x

    def plus(self, y):
        self.vector = [i+j for i,j in zip(self.vector,y)]

    def sp(self, num):
        self.vector = [num*i for i in self.vector]

    def print_me(self):
        print self.vector

u = MathVector(5)
print "u =",
u.print_me()

v = MathVector([2,3,6])
print "v =",
v.print_me()

w = MathVector(1,2,3)
print "w =",
w.print_me()

print v.get_el(2)
v.neg().print_me()
print v.mag()
print v.dot(w)
v.plus(w).print_me()
v.sp(3).print_me()

print v
print v[2]
print -v
print abs(v)
print v*w
print v+w
print v*3
