def getgcd(a, b):
    if a % b == 0:
        return b
    else:
        return getgcd(b, a % b)

for i in range(int(raw_input())):
    a, b, c, d = map(int, raw_input().split())
    e = abs(a - b)
    g = getgcd(c, d)
    if e % g == 0:
        no = 0
        print no
    else:
        m = e % g
        n = g - m

        val = min(m, n)
        print val
