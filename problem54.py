
numberCards=["1","2","3","4","5","6","7","8","9","T","J","Q","K","A"]

def TestFlush(numbers,suits):
    if len(set(suits)) == 1:
        highCardsInOrder=[]
        for i in range(len(numberCards)-1,-1,-1):
            if numberCards[i] in numbers:
                highCardsInOrder.append(numberCards[i])
        return (True,highCardsInOrder)
    return (False,[])
def TestStraight(numbers):
    i=0
    for card in numberCards:
        if card in numbers:
            i+=1
        if card not in numbers:
            i=0
        if i==5:
            return (True,card)
    return (False,"")

def testRoyalFlush(numbers,suits):
    if sorted(numbers) == sorted(["T","J","Q","K","A"]) and TestFlush(numbers,suits)[0]:
        return (True,["A"])
    return (False,[])
def testStraightFlush(numbers,suits):
    if TestFlush(numbers,suits)[0] and TestStraight(numbers)[0]:
        return TestStraight(numbers)
    return (False,"")
def testFourOfAKind(numbers):
    if len(set(numbers)) > 2:
        return (False,"")
    # if it is two, it can be four of a kind or full house
    NumberSet=set(numbers)
    card=NumberSet.pop()
    if numbers.count(card) == 4:
        return (True,card)
    card=NumberSet.pop()
    if numbers.count(card) == 4:
        return (True,card)
    return (False,"")

def testFullHouse(numbers):
    # will always test after four of a kind
    NumberSet=set(numbers)
    if len(NumberSet) == 2:
        card=NumberSet.pop()
        if numbers.count(card) == 3:
            return (True,card)
        card=NumberSet.pop()
        return (True,card)
    return (False,"")

def testThreeOfAKind(numbers):
    NumberSet=set(numbers)
    if len(NumberSet) != 3:
        return (False,"")
    for i in range(len(NumberSet)):
        card=NumberSet.pop()
        if numbers.count(card) == 3:
            return (True,card)
    return (False,"")


def testTwoPair(numbers):
    NumberSet=set(numbers)
    if len(NumberSet) != 3: 
        return (False,"")
    pairedCards=[]
    singleCard=""
    for i in range(len(NumberSet)):
        card=NumberSet.pop()
        if numbers.count(card) ==2:
            pairedCards.append(card)
        if numbers.count(card) ==1:
            singleCard=card
    highCard=""
    for i in range(len(numberCards)-1,-1,-1):
       if numberCards[i] in pairedCards:
            highCard=numberCards[i]
            break
    pairedCards.remove(highCard)
    lowCard=pairedCards[0]
    return (True,[highCard,lowCard,singleCard])


def testOnePair(numbers):
    NumberSet=set(numbers)
    if len(NumberSet)!=4:
        return (False,[])
    singleCards=[]
    pairedCard=""
    for i in range(len(NumberSet)):
        card=NumberSet.pop()
        if numbers.count(card) == 1:
            singleCards.append(card)
        if numbers.count(card) == 2:
            pairedCard=card
    singleCardsSorted=[]
    for i in range(len(numberCards)-1,-1,-1):
        if numberCards[i] in singleCards:
            singleCardsSorted.append(numberCards[i])
    return (True,pairedCard,singleCardsSorted)


def getHighCardList(numbers):
    highCardListInOrder=[]
    for i in range(len(numberCards)-1,-1,-1):
        if numberCards[i] in numbers:
            highCardListInOrder.append(numberCards[i])
    return (True,highCardListInOrder)
def getType(cards):
    numbers=[]
    for card in cards:
        numbers.append(card[0])
    suits=[]
    for card in cards:
        suits.append(card[1])
    if testRoyalFlush(numbers,suits)[0]:
        return (1,testRoyalFlush(numbers,suits))
    if testStraightFlush(numbers,suits)[0]:
        return (2,testStraightFlush(numbers,suits))
    if testFourOfAKind(numbers)[0]:
        return (3,testFourOfKind(numbers))
    if testFullHouse(numbers)[0]:
        return (4,testFullHouse(numbers))
    if TestFlush(numbers,suits)[0]:
        return (5,TestFlush(numbers,suits))
    if TestStraight(numbers)[0]:
        return (6,TestStraight(numbers))
    if testThreeOfAKind(numbers)[0]:
        return (7,testThreeOfAKind(numbers))
    test=testTwoPair(numbers)
    if test[0]:
        return (8,test)
    if testOnePair(numbers)[0]:
        return (9,testOnePair(numbers))
    return (10,getHighCardList(numbers))

with open("p054_poker.txt") as f:
    lines=f.readlines()



p1Wins=0
p2Wins=0
for line in lines:
    print "----------------------------------------------------------"
    hands=line[:-1]
    #print hands
    p1hand=hands[:len(hands)/2]
    p2hand=hands[len(hands)/2+1:]

    p1cards=p1hand.split()
    p2cards=p2hand.split()
    print p1cards
    print p2cards

    p1HandType = getType(p1cards)
    p2HandType = getType(p2cards)
    print p1HandType
    print p2HandType
    if (p1HandType[0] < p2HandType[0]):
        print "Player 1 wins!"
        p1Wins+=1
        continue
    if (p1HandType[0] > p2HandType[0]):
        print "Player 2 wins!"
        p2Wins+=1
        continue
    if p1HandType[0] in [2,3,4,6,7]:
        if(numberCards.index(p1HandType[1][1]) > numberCards.index(p2HandType[1][1])):
            print "Player 1 wins!"
            p1Wins+=1
            continue
        else:
            print "Player 2 wins!"
            p2Wins+=1
            continue
    if p1HandType[0] in [5,10]:
        highCardListP1=p1HandType[1][1]
        highCardListP2=p2HandType[1][1]
        for i in range(len(highCardListP1)):
            if numberCards.index(highCardListP1[i]) > numberCards.index(highCardListP2[i]):
                print "Player 1 wins!"
                p1Wins+=1
                break
            if numberCards.index(highCardListP1[i]) < numberCards.index(highCardListP2[i]):
                print "Player 2 wins!"
                p2Wins+=1
                break
        continue
    if p1HandType[0] == 8:
        highCardPairP1=p1HandType[1][1][0]
        highCardPairP2=p2HandType[1][1][0]
        lowCardPairP1=p1HandType[1][1][1]
        lowCardPairP2=p2HandType[1][1][1]
        singleCardP1=p1HandType[1][1][2]
        singleCardP2=p2HandType[1][1][2]

        if numberCards.index(highCardPairP1) > numberCards.index(highCardPairP2):
            print "Player 1 Wins!"
            p1Wins+=1
            continue
        elif numberCards.index(highCardPairP1) < numberCards.index(highCardPairP2):
            print "Player 2 Wins"
            p2Wins+=1
            continue
        else:
            if numberCards.index(lowCardPairP1) > numberCards.index(lowCardPairP2):
                print "Player 1 Wins!"
                p1Wins+=1
                continue
            elif numberCards.index(lowCardPairP1) < numberCards.index(lowCardPairP2):
                print "Player 2 Wins"
                p2Wins+=1
                continue
            else:
                if numberCards.index(singleCardP1) > numberCards.index(singleCardP2):
                    print "Player 1 Wins!"
                    p1Wins+=1
                    continue
                elif numberCards.index(singleCardP1) < numberCards.index(singleCardP2):
                    print "Player 2 Wins"
                    p2Wins+=1
                    continue
    if p1HandType[0] == 9:
        p1Pair=p1HandType[1][1]
        p2Pair=p2HandType[1][1]
        if numberCards.index(p1Pair) > numberCards.index(p2Pair):
            print "Player 1 Wins!"
            p1Wins+=1
            continue
        elif numberCards.index(p1Pair) < numberCards.index(p2Pair):
            print "Player 2 Wins"
            p2Wins+=1
            continue
        else:
            highCardListP1=p1HandType[1][2]
            highCardListP2=p2HandType[1][2]
            for i in range(len(highCardListP1)):
                if numberCards.index(highCardListP1[i]) > numberCards.index(highCardListP2[i]):
                    print "Player 1 wins!"
                    p1Wins+=1
                    break
                if numberCards.index(highCardListP1[i]) < numberCards.index(highCardListP2[i]):
                    print "Player 2 wins!"
                    p2Wins+=1
                    break
            continue
            
    print "FINDME"
    print p1HandType
    print p2HandType

print p1Wins
print p2Wins
