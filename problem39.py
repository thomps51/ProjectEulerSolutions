import math
import time

start = time.time()
maxSols = 0
maxSolsNum = 0
for p in range(12,1001):
    sols = 0

    for a in range(1,p):
        for b in range(a,p-a):
            c= math.sqrt( a**2 + b**2 )
            if c % 1 != 0 or a + b + c != p:
                continue
            sols += 1
            #print str(a) + "^2 " + "+" + str(b) + "^2 = " +str(c) +"^2"

    if sols > maxSols:
        print "new max! " + str(p)
        print "sols = " + str(sols)
        maxSols = sols
        maxSolsNum=p

print maxSolsNum
end = time.time()
print end - start
