
multiple = [1,2,3,4,5,6,7,8,9]
compareString=['1', '2', '3', '4', '5', '6', '7', '8', '9']

for i in range(2,len(multiple)):
    mults = multiple[0:i]
    for num in range(0,99999):
        stringN=""
        for mult in mults:
            stringN += str(mult *  num)
        if sorted(stringN) ==  compareString:
            print str(num) + "*" + str(mults) +"=" +stringN

