from collections import Counter as co

for t in range(int(raw_input())):
    no = int(raw_input())
    inp = map(int, raw_input().split())
    setinp = co(inp)
    flag = False
    for val in setinp.values():
        if val >= 3:
            print "Yes"
            flag = True
            break
    if not flag:
        print "No"
