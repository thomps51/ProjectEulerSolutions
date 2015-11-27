import math

def primeTest(N):
    if N==1:
        return False
    for i in xrange(2,int(math.sqrt(N))+1):
        if N % i == 0:
            return False
    return True

primes=[]
for i in range(10,1000000):
    if primeTest(i) == True:
        primes.append(i)

summ=0
for prime in primes:
    strPrime = str(prime)
    N = len(strPrime)
    #print N
    #print prime
    test=True
    for i in range(0,N):
        num=int(strPrime[i:N])
        #print num
        if not primeTest(num):
            test = False
    test1 = True
    #break
    for i in range(0,N):
        num = int(strPrime[0:N-i])
        #print num 
        if not primeTest(num):
            test1=False
    if test1 and test:
        summ+= prime
        print prime
print summ
