import sys
import math

pentNums=[]
for i in range(1,4000):
    pentNums.append(i*(3*i-1)/2)

print len(pentNums)

minimum = sys.maxint
for i in range(0,len(pentNums)):
    for j in range(i+1,len(pentNums)):
        summ = pentNums[i] + pentNums[j]
        diff = pentNums[j] - pentNums[i]

        #if summ in pentNums and diff in pentNums:
        #    print "got one"
        #    print i
        #    print j

        quadSumm = (1 + math.sqrt(1+24*summ)) / 6
        quadDiff = (1 + math.sqrt(1+24*diff)) / 6
        if quadSumm % 1 == 0 and quadDiff % 1 ==0:
            print "got one!"
            print diff

#N = 4000
#for ni in range(1,N):
#    for nj in range(ni,N):
#        summ = 3*ni*ni -ni + 3*nj*nj-ni
#        diff = 3*nj*nj -nj - 3*ni*ni+ni
#        quadSumm = (1 + math.sqrt(1+24*summ)) / 12
#        quadDiff = (1 + math.sqrt(1+24*diff)) / 12
#        if quadSumm == int(quadSumm) and quadDiff == int(quadDiff):
#             print "got one!"
