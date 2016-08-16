m, r, w = map(int, raw_input().split())

positions = dict()
fi = map(int, raw_input().split())
ki = map(int, raw_input().split())

for i in range(len(fi)):
    positions[fi[i]] = i

for i in range(r, m):
    fi.insert(0, 0)

fi.sort()
extra = 0

for i, no in enumerate(fi):
    if i == w:
        break
    if no == 0:
        print r + extra + 1,
        extra = extra + 1
    else:
        print positions[no] + 1,
print
