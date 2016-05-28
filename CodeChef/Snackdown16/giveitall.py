from collections import Counter

global remove
global setword


def madness():
    global remove
    global setword
    base = min(setword.values())
    countofbases = 0
    for i in setword.values():
        if i == base:
            countofbases = countofbases + i

    currremove = 0
    for ch in setword:
        if(base + n < setword[ch]):
            count_base = setword[ch] - base - n
            currremove = currremove + count_base
        if(countofbases < currremove):
            temp_setword = {}
            for ch in setword:
                if setword[ch] != base:
                    temp_setword[ch] = setword[ch]
            setword = temp_setword
            remove = remove + countofbases
            return False

    remove = remove + currremove
    print remove
    return True


t = int(raw_input())

for i in xrange(t):
    inp = raw_input().split()
    word = inp[0]
    setword = Counter(inp[0])
    n = int(inp[1])

    flag = False
    remove = 0

    while not flag:
        flag = madness()
