import math
# for any a=c^2 , a^b will be a repeat untill a^b > c^100
# for any a=c^3 , a^b will be a repeat until a^b > (c^2)^100
#etc...
# for any a=c^n (use smallest possible n), a^b will be a repeat until a^b > (c^(n-1))^ 100
count = 0
lower=2
upper=9

#highest possible n = floor(log2(upper))
n=math.floor(math.log(upper,2))
print "n="+str(n)
    #if a == 8 or a==16 or a ==64 or a==32:

def isNthPowerFunc(a):
    power=0
    for power in range(2,int(n+1)):
    #for power in range(int(n),1,-1):
        c = math.pow(a,1.0/power)
        #if c % 1.0 ==0:
        if abs( c % 1.0 - 1) < .00005 or c % 1.0 < .00005:
            #print "c = " +str(c)
            #print "power = " + str(power)
            isNthPower=True
            print power
            return True, c, power
    return False , c , power



for a in range(lower,upper+1):
    print "a = " +str(a)

    for b in range(lower,upper+1):
        #print "b = " +str(b)
        print a**b
        isNthPower=False
        # need to check if c^n = a
        c=0
        power=0
        #for power in range(2,int(n+1)):
        ##for power in range(int(n),1,-1):
        #    c = math.pow(a,1.0/power)
        #    #if c % 1.0 ==0:
        #    if abs( c % 1.0 - 1) < .00005 or c % 1.0 < .00005:
        #        #print "c = " +str(c)
        #        #print "power = " + str(power)
        #        isNthPower=True
        #        break
        isNthPower, c, power = isNthPowerFunc(a)
        #array = isNthPowerFunc(a)
        #isNthPower=array[0]
        #c=array[1]
        #power=array[2]
        if(isNthPower):
            #print "power=" + str(power) 
            #if(a**b > (c**(power-1))**upper):
            #        count+=1
            #        print "COUNT"
            if a**b >= c**upper and a**b <= (c**(power-1))**upper:
                isNthPower2, cNew, powerNew = isNthPowerFunc(a**b)
                if isNthPower2 and cNew == c**(power-1):
                #if a**b % c**(power-1)  == 0:
                    print cNew
                    print c
                    print "NOT COUNT"
                else:
                    print cNew
                    print c
                    count+=1
                    print "COUNT"
            elif a**b > (c**(power-1))**upper:
                count+=1
                print "COUNT"

        else:
            count+=1
            print "COUNT"
print count

