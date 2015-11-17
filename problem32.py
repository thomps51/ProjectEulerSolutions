import itertools
import time
stringN=['1','2','3','4','5','6','7','8','9']
permuts= list(itertools.permutations(stringN))
l=[]
start = time.time()
def sumString(m):
    summ=""
    for i in range(0,len(m)):
        summ+=m[i]
    return summ


for permu in permuts:
    for i in range(1,len(permu)-4):
        for j in range(i+1,len(permu)-3):
            #print sum()
            N=int(sumString(permu[0:i]))*int(sumString(permu[i:j]))
            if N == int(sumString(permu[j:])):
                print N
                if N not in l:
                    l.append(N)

end = time.time()
print end - start 

print sum(l)

