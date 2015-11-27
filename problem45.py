import math

def isPentagonal(x):
    n = ( 1 + math.sqrt(1+24*x))/6
    return n == int(n)

def isHexagonal(x):
    n = ( 1 + math.sqrt(1+8*x))/4
    return n == int(n)


for i in range(0,1000000):
    num = i*(i+1)/2
    if isPentagonal(num) and isHexagonal(num):
        print num

