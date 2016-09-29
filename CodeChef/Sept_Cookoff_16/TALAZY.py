from math import ceil

def calc_sum(n, b, m):
    res = 0
    counter = 0
    while n != 0:
        if n % 2 == 0:
            val = n >> 1
            n = n >> 1
        else:
            val = (n >> 1) + 1
            n = n >> 1
        res = res + m * val + b
        m = m * 2
        counter = counter + 1
        # print "counter res val m"
        # print counter, res, val, m
    res = res - b
    return res

for i in range(int(raw_input())):
    n, b, m = map(int, raw_input().split())
    print int(calc_sum(n, b, m))
