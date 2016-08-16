def maxno2(no, q):
    if no / 2 < q:
        return no / 2
    else:
        return q

for i in range(int(raw_input())):
    n, p, q = map(int, raw_input().split())
    arr = map(int, raw_input().split())
    arr.sort()

    counter = 0
    for no in arr:
        val = p + q * 2

        if val < no:
            break

        no_2s = maxno2(no, q)
        no_1s = no - no_2s * 2 if no - no_2s * 2 < p else p

        if no_2s * 2 + no_1s == no:
            counter += 1
            q = q - no_2s
            p = p - no_1s

    print counter
