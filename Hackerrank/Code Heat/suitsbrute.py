for k in range(int(raw_input())):
    n = int(raw_input())
    nos = map(int, raw_input().split())
    count = 0

    for i in range(len(nos)):
        cursum = 0
        for j in range(i, len(nos)):
            cursum = cursum + nos[j]
            if cursum == 0:
                count = count + 1

    print count
