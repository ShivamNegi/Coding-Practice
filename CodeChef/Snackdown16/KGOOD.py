from collections import Counter

t = int(raw_input())

for i in xrange(t):
    inp = raw_input().split()
    word = inp[0]
    setword = Counter(inp[0])
    n = int(inp[1])

    remove = 0
    for ch in setword:
        if setword[ch] > n:
            # print ch
            prev = 0
            for i in range(setword[ch]):
                nprev = word[prev:].find(ch)
                # print word[prev:]
                try:
                    if(abs(setword[word[prev:][nprev]] - setword[word[prev:][nprev + 1]]) <= n ):
                        pass
                    else:
                        print word[prev:][nprev],
                        print word[prev:][nprev + 1]
                        setword[word[prev:][nprev]] = setword[word[prev:][nprev]] - 1
                        # word = word[:prev] + word[prev + 1:]
                        remove = remove + 1
                except:
                    pass
                prev = nprev + 1

    print remove
