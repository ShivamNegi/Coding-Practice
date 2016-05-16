n = int(raw_input())

for i in range(n):
	inp = raw_input()
	inp1 = inp.split()
	out = []
	for word in inp1:
		if word not in out:
			out.append(word)
	out = ' '.join(out)
	print out
