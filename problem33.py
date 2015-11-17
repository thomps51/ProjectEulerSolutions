cancel1=0
cancel2=0
cancel3=0
cancel4=0
for i in range(10,100):
    for j in range(i+1,100):
        value =  float(i) / j
        v1=str(i)
        v2=str(j)
        if v2[0] != '0' and v1[0] != v1[1] and v2[0] != v2[1] and (v1[0] == v2[1] or v1[1]==v2[0]):
            #cancel1=float(v1[0])/float(v2[0])
            #if cancel1==value:
            #    print v1 + "/" + v2 + " == " + v1[0] + "/" + v2[0]
            cancel3=float(v1[1])/float(v2[0])
            if cancel3==value:
                print v1 + "/" + v2 + " == " + v1[1] + "/" + v2[0]
        if v2[1] != '0' and v1[0] != v1[1] and v2[0] != v2[1] and (v1[0] == v2[1] or v1[1]==v2[0]):
            cancel2=float(v1[0])/float(v2[1])
            if cancel2==value:
                print v1 + "/" + v2 + " == " + v1[0] + "/" + v2[1]
            #cancel4=float(v1[1])/float(v2[1])
            #if cancel4==value:
            #    print v1 + "/" + v2 + " == " + v1[1] + "/" + v2[1]
