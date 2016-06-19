def getgcd(a, b):
    if a % b == 0:
        return b
    else:
        return getgcd(b, a % b)

for i in range(int(raw_input())):
    inp = raw_input().strip().split()
    n = int(inp[0])
    c = int(inp[1])
    # n = (n * (n + 1)) / 2

    if (2 * c / n) / (n + 1) < 1:
        print "No"
        continue
    if c % n != 0:
        print "No"
        continue

    l_new = 2 * c / n
    g = getgcd(2, n - 1)

    if l_new % g == 0:
        print "Yes"
    else:
        print "No"
