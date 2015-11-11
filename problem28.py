# hard part, find sequences
# then easy, for each quadrant:
# upper right : 4n^2 -4n  + 1  n=1,2,...
# lower right : 4n^2 -10n + 7
# lower left  : 4n^2 -8n  + 5
# upper left  : 4n^2 -6n  + 3

# now sum
summ=0
for n in range(1,502):  # N = 1001 -> n=501  (N=2n-1)
    summ += 4*n**2 -4*n  + 1
    print 4*n**2 -4*n  + 1

for n in range(1,502):  # N = 1001 -> n=501  (N=2n-1)
    summ += 4*n**2 -10*n  + 7
for n in range(1,502):  # N = 1001 -> n=501  (N=2n-1)
    summ += 4*n**2 -8*n  + 5
for n in range(1,502):  # N = 1001 -> n=501  (N=2n-1)
    summ += 4*n**2 -6*n  + 3

summ -= 3 # added 1 four times, need to subtract off

print summ
