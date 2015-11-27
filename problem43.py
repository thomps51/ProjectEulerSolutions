import itertools

def sumString(m):
    summ=""
    for i in range(0,len(m)):
        summ+=m[i]
    return summ


compareString=['0','1', '2', '3', '4', '5', '6', '7', '8', '9']

permuts = list(itertools.permutations(compareString))

divis = [2,3,5,7,11,13,17]

print len(permuts)

#permuts = ["1406357289"]

summ=0
for permut in permuts:
    flag = True
    for i in range(1,8):
        if not int(permut[i]+permut[i+1]+permut[i+2]) % divis[i-1] == 0:
            flag = False
        if not flag:
            break
    if flag:
        print sumString(permut)
        summ+= int(sumString(permut))

print summ
