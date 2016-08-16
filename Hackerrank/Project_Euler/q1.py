def result(n, k):
    res = (n - 1) / k
    res = res * (res + 1)
    res = (res >> 1) * k
    return res

for i in range(int(raw_input())):
    n = int(raw_input())
    print result(n, 3) + result(n, 5) - result(n, 15)
