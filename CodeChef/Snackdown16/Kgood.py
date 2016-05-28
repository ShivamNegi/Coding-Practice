from collections import Counter

# I don't know which corner case I am missing
global remove
global setword

def madness():
    global remove
    global setword

    base = min(setword.values())
    count_to_rmbase = 0
    for no in setword.values():
            if no == base:
                count_to_rmbase = count_to_rmbase + 1

    for ch in setword:
        count_base = 0
        if(base + n < setword[ch]):
            count_base = setword[ch] - base - n

        # print "Count_base", count_base

        '''print setword.values(), "These are the values for the counter"
        print "Count base, count to rm base, base, remove"
        print count_base, count_to_rmbase, base, remove, " This is for ", ch
        print "The corresponding value for remove is", remove'''
        # removing the base char also if the total remove is lesser than the no
        # of base char
        if(count_base > count_to_rmbase or count_to_rmbase < remove):
            # removing base characters
            count = count_to_rmbase
            temp_setword = {}
            for ch in setword:
                if setword[ch] != base:
                    temp_setword[ch] = setword[ch]
            setword = temp_setword
            remove = count
            return False
        else:
            count = count_base
            # print "Count", count

        remove = remove + count

    print remove
    return True

# I think i didn't consider the case of totally removing a
# character. That should be considered.
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
