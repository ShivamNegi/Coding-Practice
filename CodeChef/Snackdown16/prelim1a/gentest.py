inp = map(int, raw_input().split())
m = int(raw_input())

for i in range(m):
    pos = 0
    a = []
    for j in range(2 * len(inp) - 1):
        if j % 2 == 0:
            a.append(inp[pos])
            pos = pos + 1
        else:
            a.append(inp[pos] + inp[pos - 1])
    inp = a
    # print inp, len(inp)
