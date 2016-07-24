from math import sqrt
from time import time

def isprime(no):
    for i in xrange(2, int(sqrt(no)) + 1):
        if no % i == 0:
            return False
    return True

one = time()
counter = 0
i = 2
while True:
    if isprime(i):
        counter = counter + 1
    if counter == 10 ** 6:
        print i
        break
    i = i + 1

print
print "The time take is:", int(time() - one), "sec."
