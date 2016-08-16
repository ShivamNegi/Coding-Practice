n, m = map(int, raw_input().split())
duarr = map(int, raw_input().split())
print duarr

for i in range(n - 1):
    arr = map(int, list(raw_input()))
    duarr = duarr + arr

print duarr

counter = 0

for i in range(n):
    for j in range(m):
        val = 0
        for k in range(i):
            for l in range(j):
                val = val ^ duarr[k][l]
        if val == 0:
            counter = counter + 1

print counter
