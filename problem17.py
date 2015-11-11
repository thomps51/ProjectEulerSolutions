one="one"
two="two"
three="three"
four="four"
five="five"
six="six"
seven="seven"
eight="eight"
nine="nine"

ones=["one","two","three","four","five","six","seven","eight","nine"]
tens=["ten","elevan","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
tens2=["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
hundred="hundred"
hundredand="hundredand"
thousands=["thousand"]
summ=0
for i in range(0,len(ones)):
    summ+=len(ones[i])
    print ones[i] 

#print summ

for i in range(0,len(tens)):
    summ+=len(tens[i])
    print tens[i]

for i in range(0,len(tens2)):
    summ+=len(tens2[i])
    print tens2[i]
    for j in range(0,len(ones)):
        summ+=len(tens2[i])
        summ+=len(ones[j])
        print tens2[i] + ones[j]
# loop over one, two .. hundred
for i in range(0,len(ones)):
    # loop over tens
    summ+=len(ones[i])
    summ+=len(hundred)
    print ones[i] + hundred
    for j in range(0,len(ones)):
        summ+=len(ones[i])  # hundreds place
        summ+=len(hundredand)
        summ+=len(ones[j])  # ones place
        print ones[i] + hundredand + ones[j]
    for j in range(0,len(tens)):
        summ+=len(ones[i]) # hundreds place
        summ+=len(hundredand)
        summ+=len(tens[j]) # tens place
        print ones[i] + hundredand + tens[j]
    for j in range(0,len(tens2)):
        summ+=len(ones[i])
        summ+=len(hundredand)
        summ+=len(tens2[j])
        print ones[i] + hundredand + tens2[j] 
        
        for k in range(0,len(ones)):
            summ+=len(ones[i])
            summ+=len(hundredand)
            summ+=len(tens2[j])
            summ+=len(ones[k])
            print ones[i] + hundredand + tens2[j] + ones[k]

summ+=len("onethousand")
print "onethousand"

print summ





