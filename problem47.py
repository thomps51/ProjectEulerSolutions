import math
import sys

def primeTest(N):
    if N==1:
        return False
    for i in xrange(2,int(math.sqrt(N))+1):
        if N % i == 0:
            return False
    return True

def findPrimeFactors(N):
    primeFactors = []
    for i in xrange(2,int(math.sqrt(N))+1):
        if N % i == 0:
            if primeTest(i):
                primeFactors.append(i)
            if primeTest(N/i):
                primeFactors.append(N/i)
    return sorted(primeFactors)

#print findPrimeFactors(646)

#sys.exit(0)
sameFactors = []
last = [1]
for i in range(10,1000000):
    primeFactors = findPrimeFactors(i)
    if primeFactors == []:
        last = [1]
        sameFactors = []

        continue
    #print primeFactors    
    if len(primeFactors) == 3:
        sameFactors.insert(0,primeFactors)
    if len(primeFactors) != 3:
        sameFactors = []

    if len(sameFactors)  == 3:
        print i
        print sameFactors
        break

    last = primeFactors





