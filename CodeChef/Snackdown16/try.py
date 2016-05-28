import numpy as np


def maxSubArraySum(a, size):
    max_so_far = a[0]
    curr_max = a[0]

    for i in range(1, size):
        curr_max = max(a[i], curr_max + a[i])
        max_so_far = max(max_so_far, curr_max)
    return max_so_far


t = int(raw_input())

for j in range(t):
    n = int(raw_input())

    a = []
    index = []

    no = raw_input().split()
    a = np.array(map(int, no))

    li = 0
    for i in xrange(n):
        if a[i] < 0:
            index.append(i)
            li = li + 1

    max_sum = a[0]

    if li == 0:
        max_sum = np.sum(a)
    elif n == li:
        max_sum = np.max(a)
    else:
        for i in index:
            b = np.append(a[:i], a[i + 1:])
            max_curr = maxSubArraySum(b, n - 1)
            if max_curr > max_sum:
                max_sum = max_curr

    print max_sum
