from math import sqrt

def isprime(no):
    for i in range(2, int(sqrt(no)) + 1):
        if no % i == 0:
            return False
    return True

def largestprime(no):
    l_prime = 1
    for i in range(1, int(sqrt(no)) + 1):
        if no % i == 0:
            if isprime(i):
                l_prime = i if l_prime < i else l_prime
            if isprime(no / i):
                l_prime = no / i if l_prime < no / i else l_prime
    return l_prime

for k in range(int(raw_input())):
    no = int(raw_input())
    print largestprime(no)
