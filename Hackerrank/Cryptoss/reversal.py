def get_count(no):
    a = [no]
    while(True):
        revno = int(str(abs(no))[::-1])
        if(no < 0):
            revno = -revno
        no = no - revno
        if no == 0 or no in a:
            break
        else:
            a.append(no)
    return len(a)

for i in range(int(raw_input())):
    no1, no2 = map(int, raw_input().split())
    for i in xrange(no1, no2 + 1):
        print get_count(i),
    print
