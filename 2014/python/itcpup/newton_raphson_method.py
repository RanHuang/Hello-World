#!/usr/bin/env python
"""
    Newton's method
    calculate the square root of a digit
"""

epsilon = 0.0001

temp = input("Input a digit: ")
n = float(temp)
x = n/2
while abs(x**2 - n) >= epsilon :
    print 'x:', x
    print 'x*x - n:', x*x - n
    x -= (x**2 - n)/(2*x)
    
print 'Square root of', n, 'is about', x
