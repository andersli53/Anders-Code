#PIC 16
#Assignment 1F
#Li, Chak Yin (Anders)
#704950093

import math

def f(x):
    return x**2 - 1
def fPrime(x):
    return 2*x

def g(x):
    return math.sin(x)
def gPrime(x):
    return math.cos(x)

def h(x):
    return math.log(x) - 1
def hPrime(x):
    return 1/x

def newton(x, f, g):
    residual = f(x)
    while abs(residual) > 0.0001:
        initial = x - f(x)/g(x)
        residual = f(initial)
        x = initial
    return initial

print "x**2 - 1, x_0 = 3,", "root = ", newton(3.0, f, fPrime)
print "x**2 - 1, x_0 = -0.5,","root = ", newton(-0.5, f, fPrime)
print "sin(x), x_0 = 2,", "root = ",newton(2, g, gPrime)
print "ln(x) - 1, x_0 = 1.5,","root = ", newton(1.5, h, hPrime)

