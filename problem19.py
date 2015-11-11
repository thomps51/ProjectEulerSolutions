monthdays=[31,28,31,30,31,30,31,31,30,31,30,31]
monthdaysLEAP=[31,29,31,30,31,30,31,31,30,31,30,31]
year=1901
dayofWeek = 2  # define days as 0=sunday 1= monday ...
dayofMonth= 1  
month=0  # 0 == Jan, 1==Feb ...
sundayCount=0
leapYear=False
while year<2001:
    # check if day is a sunday
    if dayofWeek==0 and dayofMonth==1:
        sundayCount+=1
        print "Sunday on first of month found:"
        print str(year) + " " + str(month) +" " + str(dayofMonth)
    # now advance days
    dayofMonth +=1
    dayofWeek  +=1
    # check if new week
    if dayofWeek > 6:
        dayofWeek = 0
    # check if new month
    if not leapYear:
        if dayofMonth > monthdays[month]:
            dayofMonth = 1
            month +=1
            # check if new year
            if month > 11:
                year+=1
                month=0
                if year % 4==0 and (year % 100 != 0 or year % 400==0):
                    leapYear=True
                    print str(year) + " is a leap year!"
                else:
                    leapYear=False
    else:
        if dayofMonth > monthdaysLEAP[month]:
            dayofMonth = 1
            month +=1
            # check if new year
            if month > 11:
                year+=1
                month = 0
                if year % 4==0 and year % 100 != 0:
                    leapYear=True
                else:
                    leapYear=False
print sundayCount


