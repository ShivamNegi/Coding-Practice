from math import sqrt

def isprime(n):
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def getprimes(n):
    primes = [2]
    for i in range(3, n + 1):
        if isprime(i):
            primes.append(i)
    return primes

for k in range(int(raw_input())):
    no = int(raw_input())
    primes = getprimes(no)

    mul = 1
    arr = range(2, no + 1)

    while True:
        flag = False
        for n in primes:
            counter = 0
            for i in range(len(arr)):
                if arr[i] % n == 0:
                    counter = counter + 1

            if counter > 1:
                for i in range(len(arr)):
                    if arr[i] % n == 0:
                        flag = True
                        arr[i] = arr[i] / n
                mul = mul * n

        if not flag:
            break

    for n in arr:
        mul = mul * n

    print mul
