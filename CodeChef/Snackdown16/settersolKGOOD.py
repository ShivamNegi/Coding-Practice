from collections import Counter
for cas in xrange(input()):
    s, k = raw_input().strip().split()
    k = int(k)
    ct = Counter(s).values()
    print min(sum(w if w < v else max(0, w - v - k) for w in ct) for v in ct)
