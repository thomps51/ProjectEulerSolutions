import itertools
import math

def sumString(m):
    summ=""
    for i in range(0,len(m)):
        summ+=m[i]
    return summ

def primeTest(N):
    if N==1:
        return False
    for i in xrange(2,int(math.sqrt(N))+1):
        if N % i == 0:
            return False
    return True


fourDprimes=[]
for i in range(1000,10000):
    if primeTest(i):
        fourDprimes.append(i)
        

for prime in fourDprimes:
    primeStr = str(prime)
    perms = [''.join(p) for p in itertools.permutations(primeStr)]
    primePerms = []
    for perm in perms:
        if int(perm) not in primePerms and primeTest(int(perm)):
            primePerms.append(int(perm))
    if len(primePerms) >2:
        flag =True
        primePerms = sorted(primePerms)
        for i in range(0,len(primePerms)-2):
            if primePerms[i+1] - primePerms[i] == primePerms[i+2] - primePerms[i+1]:
                print primePerms





