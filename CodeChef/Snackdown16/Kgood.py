from collections import Counter

# I don't know which corner case I am missing
global remove
global setword

def madness():
    global remove
    global setword

    currremove = 0
    print "Set word remove base count to rmbase"
    print setword, remove,
    base = min(setword.values())
    count_to_rmbase = 0
    for no in setword.values():
            if no == base:
                count_to_rmbase = count_to_rmbase + 1
    count_to_rmbase = count_to_rmbase * base
    count = 0
    print base, count_to_rmbase

    for ch in setword:
        count_base = 0
        if(base + n < setword[ch]):
            count_base = setword[ch] - base - n

        print "Count_base", count_base
        # removing the base char also if the total remove is lesser than the no
        # of base char
        if(count_base > count_to_rmbase or count_to_rmbase < currremove):
            # removing base characters
            temp_setword = {}
            for ch in setword:
                if setword[ch] != base:
                    temp_setword[ch] = setword[ch]
            setword = temp_setword
            remove = remove + count_to_rmbase
            return False
        else:
            count = count + count_base
            # print "Count", count

        currremove = currremove + count

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
        # print "Rerun ?", flag
        # print setword
        # print flag
