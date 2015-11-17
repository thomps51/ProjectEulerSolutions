import time
v = [.01,.02,.05,.10,.20,.50,1,2]
maxV   = [200,100,40,20,10,4,2,1]

start = time.time()
count =0
for i in xrange(0,201):
#    print i
    for j in xrange(0,101):
        if i*1+j*2 > 200:
            break
        for k in xrange(0,41):
            if i*1+j*2+k*5 > 200:
                break
            for l in xrange(0,21):
                if i*1+j*2+k*5+l*10 > 200:
                    break
                for m in xrange(0,11):
                    if i*1+j*2+k*5+l*10+m*20 > 200:
                        break
                    for n in xrange(0,5):
                        if i*1+j*2+k*5+l*10+m*20+n*50 > 200:
                            break

                        for o in xrange(0,3):
                            if i*1+j*2+k*5+l*10+m*20+n*50+o*100 > 200:
                                continue
                            for p in xrange(0,2):
                                summ=i*1+j*2+k*5+l*10+m*20+n*50+o*100+p*200
                                if summ==200:
                                    count+=1
print count
end = time.time()
print end - start
