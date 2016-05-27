from collections import Counter

# I think i didn't consider the case of totally removing a
# character. That should be considered.
t = int(raw_input())

for i in xrange(t):
    inp = raw_input().split()
    word = inp[0]
    setword = Counter(inp[0])
    n = int(inp[1])

    base = min(setword.values())
    remove = 0

    for ch in setword:
        if(base + n < setword[ch]):
            remove = remove + setword[ch] - base - n

    print remove
