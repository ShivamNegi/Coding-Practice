def isprime(n):
    for no in primes:
        if no >= n:
            break
        if n % no == 0:
            return False
    return True


def getprimes(n):
    no = n - len(primes)
    counter = 0
    val = primes[-1]

    if val == 3:
        val = 5
        w = 2
    elif val % 6 == 5:
        val = val + 2
        w = 4
    else:
        val = val + 4
        w = 2

    while True:
        if counter == no:
            break
        if isprime(val):
            primes.append(val)
            counter = counter + 1
        val = val + w
        w = 6 - w
    return primes

primes = [2, 3]
for k in range(int(raw_input())):
    n = int(raw_input())
    primes = getprimes(n)
    print primes[n - 1]
