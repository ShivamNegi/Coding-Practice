from collections import Counter as Count

for k in range(int(raw_input())):
    n = int(raw_input())
    nos = map(int, raw_input().split())

    temp = [0]

    for i in range(len(nos)):
        if i == 0:
            temp.append(nos[i])
        else:
            temp.append(nos[i] + temp[i])

    d = Count(temp)
    print d
