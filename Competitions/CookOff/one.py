from math import ceil

t = int(raw_input())
s = 0

n = raw_input().split()

for i in range(t):
	s = s + int(n[i])

print int(ceil(s/2.0))
