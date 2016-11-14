
def factorial(n):
    if n==0:
        return 1
    return n*factorial(n-1)

print factorial(4)

summ=0
for n in range(0,101):
    for r in range (0,n+1):
        val=factorial(n)/(factorial(r)*factorial(n-r))
        if val > 1000000:
            summ+=1
print summ
