import math
import itertools

facts = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
# method 1 loop over numbers, check if digits are sums of factorials
for i in range(10,10000000):
    #print i
    stringN=str(i)
    summ=0
    for j in stringN:
        summ += facts[int(j)]
    if i==summ:
        print i



