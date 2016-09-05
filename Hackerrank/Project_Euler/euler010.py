from math import sqrt

def isprime(no):
    for i in range(2, int(sqrt(no)) + 1):
        if no % i == 0:
            return False
    return True

def sumtill(n):
    next_check = primes[-1]

    if n < next_check:
        res = 0
        for no in primes:
            if no <= n:
                res = res + no
            else:
                return res
    else:
        if (next_check + 1) % 6 == 0:
            next_check = next_check + 2
            w = 4
        else:
            next_check = next_check + 4
            w = 2

        # print "here"
        while next_check <= n:
            if isprime(next_check):
                primes.append(next_check)
            next_check = next_check + w
            w = 6 - w

        return sum(primes)

primes = [2, 3, 5]

for k in xrange(int(raw_input())):
    no = int(raw_input())
    print sumtill(no)
