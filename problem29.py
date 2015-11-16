import math
import sys
# for any a=c^2 , a^b will be a repeat untill a^b > c^100
# for any a=c^3 , a^b will be a repeat until a^b > (c^2)^100
#etc...
# for any a=c^n (use smallest possible n), a^b will be a repeat until a^b > (c^(n-1))^ 100
count = 0
lower=2
upper=100

#highest possible n = floor(log2(upper))
n=math.floor(math.log(upper,2))
#print "n="+str(n)
    #if a == 8 or a==16 or a ==64 or a==32:

def isNthPowerFunc(a):
    power=0
    for power in range(int(n),1,-1):
    #for power in range(int(n),1,-1):
        c = math.pow(a,1.0/power)
        #print c
        #print power
        #if c % 1.0 ==0:
        if abs( c % 1.0 - 1) < .0005 or c % 1.0 < .0005:
            #print "N = " + str(a)
            #print "c = " +str(c)
            #print "power = " + str(power)
            isNthPower=True
            #print power
            return True, c, power
    #print "Not power!"
    return False , c , power


#isNthPowerFunc(32)

#sys.exit(0)
Non=0
for a in range(lower,upper+1):
    print "a = " +str(a)

    for b in range(lower,upper+1):
        #print "b = " +str(b)
        #print a**b
        # need to check if c^n = a
        c=0
        power=0
        isNthPower, c, power = isNthPowerFunc(a)
        flag = True
        if(isNthPower):
            if a**b <= c**upper:
                print "NOT COUNT1"
                Non=0
            elif a**b == (c**(power-1))**upper:
                print "NOT COUNT2"
                Non=0

            elif a**b <= (c**(power-1))**upper:
                for nn in range(1,power):
                    for i in range(upper/power,upper+1):
                        if math.fabs(float(nn)*i/power - b) < .05:
                            print "NOT COUNT3"
                            flag = False
                            break
                if flag:
                    print "YCOUNT1"
                    count+=1
                    print a**b


            else:
                flag=True
                for i in range(0,power):
                    if a==9 and b ==50:
                        print a**b
                        print (c**i)**upper
                        print a**b == c**(i*upper)
                    if power*b == i* upper:
                        print "NOT COUNT4"
                        flag=False
                        break

                if flag and power > 0:
                    count+=1
                    print "YCOUNT2"
                    print a**b

        else:
            count+=1
            print "YCOUNT3"
            print a**b
print count

