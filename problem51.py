
import math,copy
import pickle,sys
def primeTest(N):
    if N==1:
        return False
    for i in xrange(2,int(math.sqrt(N))+1):
        if N % i == 0:
            return False
    return True

primes=[]
#for i in range(1,999999):
#    if primeTest(i):
#        primes.append(i)
#
#with open('objs.pickle', 'w') as f:
#    pickle.dump(primes,f)
#sys.exit(0)
with open('objs.pickle') as f:
    primes = pickle.load(f)

#print primes

def has2repeat(num):
    

for prime in primes






#testVals=[0,1,2,3,4,5,6,7,8,9]
#maxFamilyPrimes=-1
#for prime in primes:
#    strPrime=str(prime)
#    listPrime=list(strPrime)
#    maxFamilyPrimesPer=0
#    print prime
#    for i in range(0,len(strPrime)-1):
#        for j in range(i,len(strPrime)-1):
#            for k in range(j,len(strPrime)-1):
#
#                NfamilyPrimes=0
#                for val in testVals:
#                    testList=copy.deepcopy(listPrime)
#                    testList[i]=str(val)
#                    testList[j]=str(val)
#                    testList[k]=str(val)
#                    joined=''.join(testList)
#                    if int(joined) in allprimes:
#                        #print joined
#                        NfamilyPrimes+=1
#                if NfamilyPrimes > maxFamilyPrimesPer:
#                    maxFamilyPrimesPer = NfamilyPrimes
#                    maxFamilyPrimePer = strPrime
#    if maxFamilyPrimesPer > maxFamilyPrimes:
#        maxFamilyPrimes= maxFamilyPrimesPer
#        maxFamilyPrime = strPrime
#        print "New Max of " + str(maxFamilyPrimes) + " for " + maxFamilyPrime
#    if maxFamilyPrimes == 8:
#        print "8 reached!!"
#        print maxFamilyPrime
#
#print maxFamilyPrime
#print maxFamilyPrimes
#
