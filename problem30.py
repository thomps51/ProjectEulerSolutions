summ2=0
Ns=[]
for i in xrange(2,1000000):
    stringN=str(i)
    summ=0
    for j in range(0,len(stringN)):
        summ+=int(stringN[j])**5
    if summ==i:
        print i
        Ns.append(i)
for N in Ns:
    summ2+=N
print summ2
