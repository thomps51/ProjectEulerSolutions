import itertools
import pickle
import sys

nums=[]
#for num in range(0,10000000):
#    strnum=str(num)
#    strLength=len(strnum)
#    if num > 10**(strLength-1) * 5./3:
#        continue
#    nums.append(num)
#with open('objs.pickle', 'w') as f:
#    pickle.dump(nums,f)
#sys.exit(0)

with open('objs.pickle') as f:
    nums = pickle.load(f)

#nums=[125874]

highest=0
for num in nums:
    strnum=str(num)
    strLength=len(strnum)
    #print num
    permus = list(itertools.permutations(list(strnum)))
    #print permus
    flag=True
    #print "MULS:"
    for i in range (1,7):
       mul = i * num
       mulStr=str(mul)
       listMul=tuple(mulStr)
       #print listMul
       if listMul not in permus:
           flag=False
           break
       if i > highest:
           print "new highest! "+ str(i)
           highest=i
    if flag:
        print num
        print 2*num
        print 3*num
        print 4*num
        print 5*num
        print 6*num


