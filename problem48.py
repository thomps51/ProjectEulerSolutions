
N=1000
summ=0
for i in range(1,N):
    strI = str(i**i)
    if len(strI) > 10:
        strI = strI[-11:]
    summ+=int(strI)
print str(summ)[-11:]
print summ
