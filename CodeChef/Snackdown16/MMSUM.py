def maxSubArraySum(a, size):
    max_so_far = 0
    max_ending_here = 0

    for i in xrange(0, size):
        max_ending_here = max_ending_here + a[i]
        if max_ending_here < 0:
            max_ending_here = 0

        # Do not compare for all elements. Compare only
        # when  max_ending_here > 0
        elif (max_so_far < max_ending_here):
            max_so_far = max_ending_here
    return max_so_far

t = int(raw_input())

for i in range(t):
    n = int(raw_input())

    a = []
    index = []

    no = raw_input().split()
    for no1 in no:
        no1 = int(no1)
        a.append(no1)

    for i in xrange(len(a)):
        if a[i] < 0:
            index.append(i)

    max_sum = a[0]

    if len(index) == 0:
        max_sum = sum(a)
    elif len(a) == len(index):
        max_sum = max(a)
    else:
        for i in index:
            b = a[:i] + a[i + 1:]
            max_curr = maxSubArraySum(b, n - 1)
            if max_curr > max_sum:
                max_sum = max_curr

    print max_sum
