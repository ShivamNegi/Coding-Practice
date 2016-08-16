from math import sqrt

def isprime(no):
    for i in xrange(2, int(sqrt(no)) + 1):
        if no % i == 0:
            return False
    return True

for i in range(int(raw_input())):
    n = int(raw_input())
    limit = n
    max_prime = 1
    i = 2

    if isprime(n):
        print n
        continue

    flag = False

    while i < limit:
        if n % i == 0:
            if isprime(i):
                max_prime = i if i > max_prime else max_prime
            if isprime(n / i):
                print n / i
                flag = True
                break
            limit = n / i
        i = i + 1

    if not flag:
        print max_prime
