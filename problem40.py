
count =0
i = 1
powCount=0
summ=1
while count <= 1000000:
    
    strI = str(i)
    for j in range(0, len(strI)):
        count += 1
        if count == 10**powCount:
            summ *= int(strI[j])
            powCount+=1
            print count
    i+=1

print summ



