import math
import time
start = time.time()
def primeTest(N):
    for i in xrange(2,int(math.sqrt(N))+1):
        if N % i == 0:
            return False
    return True

primes=[]
for i in range(2,1000000):
    if primeTest(i) == True:
        primes.append(i)

#print len(primes)
count=0
for prime in primes:
    strN=str(prime)
    rotations=[]
    N = len(strN)
    for i in range(0,N):
        Rstr=""
        for j in range(0,N):
            Rstr+=strN[(i+j)%N]
        rotations.append(Rstr)
    flag=True
    for rotation in rotations:
        if not primeTest(int(rotation)):
            flag=False
    if flag:
 #       print prime
        count+=1
print count
end = time.time()
print end - start
