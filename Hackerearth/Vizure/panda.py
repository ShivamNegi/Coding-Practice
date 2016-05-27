t = int(raw_input())

h = []
l = []

for i in xrange(t):
    no1 = int(raw_input())
    no2 = int(raw_input())

    h.append(no1)
    l.append(no2)

max_val = 0

for i in xrange(t):
    prev = i
    maxi = h[i]
    for j in xrange(i + 1, t):
        if h[j] >= 0:
            if(l[prev] <= l[j]):
                maxi = maxi + h[j]
                prev = prev + l[j]

    if maxi > max_val:
        max_val = maxi

print max_val        

