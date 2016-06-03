from math import sqrt

t = int(raw_input())
primes = []

for i in xrange(2, 10**6):
    flag = True
    for j in range(2, int(sqrt(i)) + 1):
        if i % j == 0:
            flag = False
            break
    if flag:
        primes.append(i)

for i in range(t):
    n = int(raw_input())
