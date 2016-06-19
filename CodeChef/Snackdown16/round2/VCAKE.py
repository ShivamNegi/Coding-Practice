def twonocheck(k, j, r, c):
    if k % r == 0:
        nc = c - k / r
        if r * nc == j:
            return True
    if k % c == 0:
        nr = r - k / c
        if nr * c == j:
            return True
    return False


def nocheck(m, k, j, r, c):
    if m % r == 0:
        nc = c - m / r
        if nc != 0:
            if twonocheck(k, j, r, nc):
                    return True
            elif twonocheck(j, k, r, nc):
                return True
    if m % c == 0:
        nr = r - m / c
        if nr != 0:
            if twonocheck(k, j, nr, c):
                return True
            elif twonocheck(j, k, nr, c):
                return True
    return False

for i in range(int(raw_input())):
    inp = raw_input().split()
    r = int(inp[0])
    c = int(inp[1])
    m = int(inp[2])
    k = int(inp[3])
    j = int(inp[4])
    # r, c, m, k, j = map(int, raw_input().split())

    if nocheck(m, k, j, r, c):
        print "Yes"
    # elif nocheck(m, j, k, r, c):
    #     print "Yes"
    elif nocheck(j, m, k, r, c):
        print "Yes"
    # elif nocheck(j, k, m, r, c):
    #     print "Yes"
    elif nocheck(k, m, j, r, c):
        print "Yes"
    # elif nocheck(k, j, m, r, c):
    #     print "Yes"
    else:
        print "No"
