import csv

test = []

triangleNums = []
for i in range(0,100):
    temp =  i * (i + 1) / 2
    triangleNums.append(temp)

print triangleNums

with open('p042_words.txt', 'rb') as csvfile:
    values = csv.reader(csvfile, delimiter=',', quotechar='|')
    for row in values:
        test = row
        #print row
words = []
for word in test:
    words.append(word[1:-1])
count = 0
for word in words:
    wordVal = 0
    for i in range(0,len(word)):
        #print ord(word[i]) - ord("a") + 1
        print word[i] +"="+str( ord(word[i]) )
        wordVal += (ord(word[i]) - ord("A") + 1 )
    #print wordVal
    if wordVal in triangleNums:
        count +=1

print count

print ord("g") - ord("a") + 1

