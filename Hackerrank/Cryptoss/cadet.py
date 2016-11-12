from collections import Counter as C

for cases in range(int(raw_input())):
    n = int(raw_input())
    inp = raw_input()
    d = C(inp)

    if d['_'] != 0:
        flag = True
        for key, value in d.iteritems():
            if value == 1 and key != '_':
                flag = False
                break

        if flag:
            print "YES"
        else:
            print "NO"
    else:
        if len(inp) == 1:
            print "NO"
            continue
        if len(inp) == 2:
            if inp[0] == inp[1]:
                print "YES"
            else:
                print "NO"
            continue

        flag = True
        if inp[0] == inp[1] and inp[-1] == inp[-2]:
            pass
        else:
            print "NO"
            continue
        for i in range(1, len(inp) - 1):
            if inp[i - 1] == inp[i] or inp[i + 1] == inp[i]:
                pass
            else:
                flag = False
                break

        if flag:
            print "YES"
        else:
            print "NO"
