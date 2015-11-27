

summ=0
for i in xrange(1,1000000):
    b2Rep  = bin(i)[2:]
    b10Rep = str(i)
    b2Test = True
    for j in range (0,len(b2Rep)/2):
        if b2Rep[j] != b2Rep[len(b2Rep)-j-1]:
            b2Test = False
    b10Test = True
    for j in range (0,len(b10Rep)/2):
        if b10Rep[j] != b10Rep[len(b10Rep)-j -1]:
            b10Test = False 
    
    if b2Test and b10Test:
        summ+=i
        print i
print summ
