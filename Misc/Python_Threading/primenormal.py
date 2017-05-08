from math import sqrt
from time import time

def isprime(no):
    for i in xrange(2, int(sqrt(no)) + 1):
        if no % i == 0:
            return False
    return True

def getprimes(size):
    primes = []
    i = 2
    while len(primes) != size:
        if isprime(i):
            primes.append(i)
        i = i + 1
    return primes


one = time()
primes = getprimes(10 ** 5)
print "The nth of prime number is:", primes[-1]
print
print "The time take is:", int(time() - one), "sec."
