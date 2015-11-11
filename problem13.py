with open("problem13.txt") as f:
    content = f.readlines()
carryOver=0
Nnumbers=len(content)
Ndigits =len(content[0])
#print Ndigits
Ndigits = Ndigits-1
for i in range(0,Ndigits):
    summ=carryOver
    for j in range(0,Nnumbers):
        carryOver=0
        #print content[j][Ndigits-1-i]
        summ+=int(content[j][Ndigits-1-i])
    digit=summ%10
    carryOver=summ/10
    #print "digit is:" + str(digit)
    print str(digit)
print carryOver
