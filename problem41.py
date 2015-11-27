import itertools
import math

compareString=['1', '2', '3', '4', '5', '6', '7', '8', '9']

def primeTest(N):
    if N==1:
        return False
    for i in xrange(2,int(math.sqrt(N))+1):
        if N % i == 0:
            return False
    return True

def sumString(m):
    summ=""
    for i in range(0,len(m)):
        summ+=m[i]
    return summ


for i in range(1,len(compareString)):
    permuts = list(itertools.permutations(compareString[0:i]))
    for permut in permuts:
        if primeTest(int(sumString(permut))):
            print sumString(permut)




