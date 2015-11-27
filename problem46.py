import math

def primeTest(N):
    if N==1:
        return False
    for i in xrange(2,int(math.sqrt(N))+1):
        if N % i == 0:
            return False
    return True

N = 10000
primes=[]
oddComps=[]
for i in range(2,N):
    if i%2 ==0:
        continue
    if primeTest(i):
        primes.append(i)
    else:
        oddComps.append(i)


for oddComp in oddComps:
    flag = False
    for prime in primes:
        if prime > oddComp:
            break
        N = math.sqrt((float(oddComp) - prime)/2)
        if int(N) == N:
            flag = True
        if flag:
            break
    if not flag:
        print oddComp
