def getgcd(a, b):
    if a % b == 0:
        return b
    else:
        return getgcd(b, a % b)

def getclosest(d, c, closest, reldis):
    nomin = reldis / c
    i = 1
    lcm = c * d / getgcd(c, d)
    while True:
        no = d * i
        if no > lcm:
            break
        checkno = (no / c - nomin) * c
        check = abs(no - checkno - reldis)
        if check >= 0 and check < closest:
            closest = check
        i = i + 1
        print no, checkno, check
    return closest

for t in range(int(raw_input())):
    a, b, c, d = map(int, raw_input().split())
    reldis1 = abs(a - b)
    c, d = min(c, d), max(c, d)

    closest = getclosest(d, c, c - 1, reldis1)
    print closest
