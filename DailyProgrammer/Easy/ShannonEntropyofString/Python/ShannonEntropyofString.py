from math import log

inp = raw_input()
ele = set(inp)
hx = 0
N = len(inp)

for ch in ele:
	n = inp.count(ch)
	k = float(n) / float(N)
	hx = hx + k * log(k) / log(2)

hx = -1 * hx
print hx